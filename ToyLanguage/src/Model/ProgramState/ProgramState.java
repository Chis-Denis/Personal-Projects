package Model.ProgramState;

import Model.Structures.*;
import Model.Statements.IStmt;
import Model.Values.IValue;
import Model.Values.StringValue;

import java.io.BufferedReader;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class ProgramState {
    private IStack<IStmt> executionStack;
    private IDictionary<String, IValue> symbolTable;
    private IDictionary<StringValue, BufferedReader> fileTable;
    private IList<IValue> output;
    private IHeapTable<IValue> heapTable;
    private IStmt originalProgram;

    public ProgramState(IStack<IStmt> exeStack, IDictionary<String, IValue> symTable, IList<IValue> out, IDictionary<StringValue, BufferedReader> fileT,                          
                        IHeapTable<IValue> heapTable ,IStmt origPrg) {
        this.executionStack = exeStack;
        this.symbolTable = symTable;
        this.fileTable = fileT;
        this.output = out;
        this.heapTable = heapTable;
        this.originalProgram = origPrg.deepCopy();
        this.executionStack.push(this.originalProgram);
    }

    public ProgramState(IStmt originalProgram) {
        this.executionStack = new MyStack<>();
        this.symbolTable = new MyDictionary<>();
        this.fileTable = new MyDictionary<>();
        this.output = new MyList<>();
        this.heapTable = new MyHeapTable<>();
        this.originalProgram = originalProgram;
        this.executionStack.push(originalProgram);
    }

    public IStack<IStmt> getExecutionStack() {
        return this.executionStack;
    }

    public IDictionary<String, IValue> getSymbolTable() {
        return this.symbolTable;
    }

    public IDictionary<StringValue, BufferedReader> getFileTable() {
        return this.fileTable;
    }

    public IList<IValue> getOutput() {
        return this.output;
    }

    public IHeapTable<IValue> getHeapTable() {
        return this.heapTable;
    }

    public IStmt getOriginalProgram() {
        return this.originalProgram;
    }

    @Override
    public String toString() {
        DateTimeFormatter dtf = DateTimeFormatter.ofPattern("yyyy/MM/dd HH:mm:ss");
        LocalDateTime now = LocalDateTime.now();
        return dtf.format(now) +
                "\n" +
                "Execution Stack: " + this.executionStack.toString() +
                "\n" +
                "Symbol Table: " + this.symbolTable.toString() +
                "\n" +
                "Heap Table: " + this.heapTable.toString() +
                "\n" +
                "Output: " + this.output.toString() +
                "\n" +
                "~".repeat(50) +
                "\n";

    }
}
