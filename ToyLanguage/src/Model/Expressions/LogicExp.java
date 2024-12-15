package Model.Expressions;

import Model.Structures.IDictionary;
import Model.Structures.IHeapTable;
import Model.Values.IValue;
import Model.Values.BoolValue;
import Model.Types.BoolType;

import Model.Exceptions.ExpressionException;
import Model.Exceptions.HeapException;
import Model.Exceptions.DictionaryException;

public class LogicExp implements IExp {
    private IExp exp1;
    private IExp exp2;
    private String operation;

    public LogicExp(IExp e1, IExp e2, String op) {
        this.exp1 = e1;
        this.exp2 = e2;
        this.operation = op;
    }

    @Override
    public IValue eval(IDictionary<String, IValue> symbolTable, IHeapTable<IValue> heapTable) throws DictionaryException, ExpressionException, HeapException {
        IValue val1, val2;
        val1 = exp1.eval(symbolTable, heapTable);
        if (val1.getType().equals(new BoolType())) {
            val2 = exp2.eval(symbolTable, heapTable);
            if(val2.getType().equals(new BoolType())) {
                BoolValue boolValue1 = (BoolValue) val1;
                BoolValue boolValue2 = (BoolValue) val2;
                boolean b1, b2;
                b1 = boolValue1.getValue();
                b2 = boolValue2.getValue();

                switch (this.operation) {
                    case "&&":
                        return new BoolValue(b1 && b2);
                    case "||":
                        return new BoolValue(b1 || b2);
                    case "^":
                        return new BoolValue(b1 ^ b2);
                    default:
                        throw new ExpressionException("Invalid logical operation given.");
                }
            }
            else {
                throw new ExpressionException("Second operand is not a boolean.");
            }
        }
        else {
            throw new ExpressionException("First operand is not a boolean.");
        }
    }

    @Override
    public IExp deepCopy() {
        return new LogicExp(this.exp1.deepCopy(), this.exp2.deepCopy(), this.operation);
    }

    @Override
    public String toString() {
        return "(" + this.exp1.toString() + " " + this.operation + " " + this.exp2.toString() + ")";
    }

}
