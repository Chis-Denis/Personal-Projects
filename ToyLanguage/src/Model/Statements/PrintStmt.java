package Model.Statements;

import Model.Expressions.IExp;
import Model.Values.IValue;
import Model.ProgramState.ProgramState;

import Model.Exceptions.ExpressionException;
import Model.Exceptions.HeapException;
import Model.Exceptions.DictionaryException;

public class PrintStmt implements IStmt{
    private IExp expression;

    public PrintStmt(IExp e) {
        this.expression = e;
    }

    @Override
    public ProgramState execute(ProgramState currentState) throws ExpressionException, DictionaryException, HeapException {
        IValue expressionValue = this.expression.eval(currentState.getSymbolTable(), currentState.getHeapTable());
        currentState.getOutput().add(expressionValue);
        return currentState;
    }

    @Override
    public IStmt deepCopy() {
        return new PrintStmt(this.expression.deepCopy());
    }

    @Override
    public String toString() {
        return "print(" + this.expression.toString() + ")";
    }

}
