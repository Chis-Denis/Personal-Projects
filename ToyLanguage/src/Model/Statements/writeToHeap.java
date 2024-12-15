package Model.Statements;

import Model.Expressions.IExp;
import Model.ProgramState.ProgramState;
import Model.Types.RefType;
import Model.Values.IValue;
import Model.Values.RefValue;

import Model.Exceptions.*;

public class writeToHeap implements IStmt {
    private String varName;
    private IExp exp;

    public writeToHeap(String varName, IExp exp) {
        this.varName = varName;
        this.exp = exp;
    }

    @Override
    public ProgramState execute(ProgramState state) throws StatementException, ExpressionException, DictionaryException, FileException, HeapException {
        if (!state.getSymbolTable().isDefined(this.varName)) {
            throw new StatementException("ERROR: The given variable(" + this.varName + ") is not defined in the symbol table.");
        }
        IValue varValue = state.getSymbolTable().lookUp(this.varName);
        if (!(varValue.getType().equals(new RefType(null)))) {
            throw new StatementException("ERROR: The given variable(" + this.varName + ") is not of type RefType.");
        }
        RefValue refValue = (RefValue) varValue;
        if (!state.getHeapTable().isDefined(refValue.getAddress())) {
            throw new StatementException("ERROR: The address associated with the given variable(" + this.varName + ") is no longer available in the heap.");
        }
        IValue expValue = this.exp.eval(state.getSymbolTable(), state.getHeapTable());
        if (!expValue.getType().equals(refValue.getLocationType())) {
            throw new StatementException("ERROR: The type of the given expression(" + this.exp.toString() + ") does not match with the location type.");
        }
        state.getHeapTable().updateHeapValue(refValue.getAddress(), expValue);
        return state;
    }

    @Override
    public IStmt deepCopy() {
        return new writeToHeap(this.varName, this.exp);
    }

    @Override
    public String toString() {
        return "WriteToHeap(" + this.varName + ", " + this.exp.toString() + ")";
    }

}
