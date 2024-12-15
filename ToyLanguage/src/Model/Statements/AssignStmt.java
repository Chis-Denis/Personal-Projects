package Model.Statements;

import Model.Structures.IDictionary;
import Model.ProgramState.ProgramState;
import Model.Types.IType;
import Model.Values.IValue;
import Model.Expressions.IExp;

import Model.Exceptions.StatementException;
import Model.Exceptions.ExpressionException;
import Model.Exceptions.HeapException;
import Model.Exceptions.DictionaryException;

public class AssignStmt implements IStmt {
    private String id;
    private IExp expression;

    public AssignStmt(String id, IExp expression) {
        this.id = id;
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws StatementException, ExpressionException, DictionaryException, HeapException {
        IDictionary<String, IValue> symbolTable = state.getSymbolTable();

        if (symbolTable.isDefined(this.id)) {
            IValue val = this.expression.eval(symbolTable, state.getHeapTable());
            IType type = symbolTable.lookUp(this.id).getType();
            
            if (val.getType().equals(type)) {
                symbolTable.addKeyValuePair(this.id, val);
            } 
            
            else {
                throw new StatementException("Declared type of variable " + id + " and type of the assigned expression do not match.");
            }
        } 
        
        else {
            throw new StatementException("The used variable " + id + " was not declared before.");
        }

        return state;
    }

    @Override
    public IStmt deepCopy() {
        return new AssignStmt(this.id, this.expression.deepCopy());
    }

    @Override
    public String toString() {
        return this.id + " = " + this.expression.toString();
    }
    
}
