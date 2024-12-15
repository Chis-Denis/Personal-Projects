package Controller;

import Model.Structures.*;
import Model.Statements.*;
import Model.ProgramState.*;
import Model.Values.*;

import Model.Exceptions.*;

import java.io.IOException;
import java.sql.Ref;
import java.util.*;
import java.util.stream.Collectors;

import Repository.IRepository;

public class Controller {
    private IRepository repo;
    private boolean displayFlag;

    public Controller(IRepository repo) {
        this.repo = repo;
        this.displayFlag = true;
    }

    public void addProgramState(ProgramState prg) {
        this.repo.addProgramState(prg);
    }

    public void reinitializeProgramState() {
        ProgramState currentProgramState = this.repo.getCurrentProgramState();
        ProgramState newProgramState = new ProgramState(currentProgramState.getOriginalProgram());
        this.repo.addProgramState(newProgramState);
    }

    public ProgramState oneStep(ProgramState currentState) throws ControllerException, StackException, StatementException, ExpressionException, DictionaryException, HeapException ,FileException {
        IStack<IStmt> executionStack = currentState.getExecutionStack();
        if (executionStack.isEmpty()) {
            throw new ControllerException("Program state's execution stack is empty.");
        }

        IStmt topStatement = executionStack.pop();
        return topStatement.execute(currentState);
    }

    public void allSteps() throws ControllerException, StatementException, StackException, ExpressionException, DictionaryException, ListException, HeapException ,FileException, IOException {
        ProgramState programState = this.repo.getCurrentProgramState();

        if (programState.getExecutionStack().isEmpty()) {
            throw new ControllerException("The program state's execution stack is empty.");
        }

        this.repo.logPrgStateExec();
        if (this.displayFlag) {
            System.out.println("Program execution started:");
            System.out.print(programState.toString() + "\n");
        }

        int outputListSize = 0;
        IList<IValue> output;

        while (!programState.getExecutionStack().isEmpty()) {
            this.oneStep(programState);
            this.repo.logPrgStateExec();

            //Garbage Collector
            Map<Integer, IValue> heapContent = programState.getHeapTable().getContent();
            List<Integer> symbolTableAddresses = this.getAddressesFromSymTable(programState.getSymbolTable().getContent().values());
            List<Integer> allReferencedAddresses = this.addIndirectAddresses(symbolTableAddresses, heapContent);
            programState.getHeapTable().setContent(this.garbageCollector(allReferencedAddresses, heapContent));

            if (this.displayFlag) {
                System.out.println(programState);
            } 
            
            else {
                output = programState.getOutput();
                
                if (outputListSize != output.size()) {
                    outputListSize = output.size();
                    System.out.println(output.getElemAtIndex(output.size() - 1).toString());
                }
            }
        }
    }

    private List<Integer> getAddressesFromSymTable(Collection<IValue> symbolTableValues) {
        return symbolTableValues.stream()
                .filter(value -> value instanceof RefValue)
                .map(v -> {RefValue v1 = (RefValue) v; return v1.getAddress();})
                .collect(Collectors.toList());
    }

    private List<Integer> addIndirectAddresses(List<Integer> symbolTableAddresses, Map<Integer, IValue> heapContent) {
        boolean change = true;
        List<Integer> newAddressList = new ArrayList<>(symbolTableAddresses);
        while (change) {
            List<Integer> appendingList;
            change = false;

            appendingList = heapContent.entrySet().stream()
                    .filter(e -> e.getValue() instanceof RefValue)
                    .filter(e -> newAddressList.contains(e.getKey()))
                    .map(e -> ((RefValue) e.getValue()).getAddress())
                    .filter(e -> !newAddressList.contains(e))
                    .collect(Collectors.toList());
            if (!appendingList.isEmpty()) {
                change = true;
                newAddressList.addAll(appendingList);
            }
        }
        return newAddressList;
    }

    private Map<Integer, IValue> garbageCollector(List<Integer> referencedAddresses, Map<Integer, IValue> heap) {
        return heap.entrySet().stream()
                .filter(e -> referencedAddresses.contains(e.getKey()))
                .collect(Collectors.toMap(Map.Entry::getKey, Map.Entry::getValue));
    }

    public void turnDisplayFlagOn() {
        this.displayFlag = true;
    }

    public void turnDisplayFlagOff() {
        this.displayFlag = false;
    }
}
