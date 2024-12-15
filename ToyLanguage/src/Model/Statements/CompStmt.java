package Model.Statements;

import Model.Structures.IStack;
import Model.ProgramState.ProgramState;

import Model.Exceptions.StatementException;

public class CompStmt implements IStmt{
    private IStmt first;
    private IStmt second;

    public CompStmt(IStmt first, IStmt second) {
        this.first = first;
        this.second = second;
    }

    @Override
    public ProgramState execute(ProgramState state) throws StatementException {
        IStack<IStmt> stack = state.getExecutionStack();
        stack.push(this.second);
        stack.push(this.first);
        return state;
    }

    @Override
    public IStmt deepCopy() {
        return new CompStmt(this.first.deepCopy(), this.second.deepCopy());
    }

    @Override
    public String toString() {
        return "(" + this.first.toString() + "; " + this.second.toString() + ")";
    }

}
