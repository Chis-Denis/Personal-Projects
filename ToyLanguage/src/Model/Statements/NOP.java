package Model.Statements;

import Model.ProgramState.ProgramState;

import Model.Exceptions.StatementException;
import Model.Exceptions.ExpressionException;
import Model.Exceptions.DictionaryException;

public class NOP implements IStmt {

    public NOP() {}

    @Override
    public ProgramState execute(ProgramState state) throws StatementException, ExpressionException, DictionaryException {
        return state;
    }

    @Override
    public IStmt deepCopy() {
        return new NOP();
    }

    @Override
    public String toString() {
        return "No OPStatement";
    }
}
