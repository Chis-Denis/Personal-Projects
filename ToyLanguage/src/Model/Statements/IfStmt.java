package Model.Statements;

import Model.Expressions.IExp;
import Model.ProgramState.ProgramState;
import Model.Types.BoolType;
import Model.Values.BoolValue;
import Model.Values.IValue;

import Model.Exceptions.ExpressionException;
import Model.Exceptions.HeapException;
import Model.Exceptions.StatementException;
import Model.Exceptions.DictionaryException;

public class IfStmt implements IStmt {
    private IExp expression;
    private IStmt thenStatement;
    private IStmt elseStatement;

    public IfStmt(IExp expression, IStmt thenStatement, IStmt elseStatement) {
        this.expression = expression;
        this.thenStatement = thenStatement;
        this.elseStatement = elseStatement;
    }

    @Override
    public ProgramState execute(ProgramState state) throws StatementException, ExpressionException, DictionaryException, HeapException {
        IValue conditional = this.expression.eval(state.getSymbolTable(), state.getHeapTable());

        if (conditional.getType().equals(new BoolType())) {
            BoolValue boolConditional = (BoolValue) conditional;

            if (boolConditional.getValue()) {
                state.getExecutionStack().push(this.thenStatement);
            } 

            else {
                state.getExecutionStack().push(this.elseStatement);
            }
        } 

        else {
            throw new StatementException("Conditional expression is not a boolean.");
        }

        return state;
    }

    
    @Override
    public IStmt deepCopy() {
        return new IfStmt(this.expression.deepCopy(), this.thenStatement.deepCopy(), this.elseStatement.deepCopy());
    }
    
    @Override
    public String toString() {
        return "If (" + this.expression.toString() + ") " +
                "then (" + this.thenStatement.toString() + ") " +
                "else (" + this.elseStatement.toString() + ")";
    }

}
