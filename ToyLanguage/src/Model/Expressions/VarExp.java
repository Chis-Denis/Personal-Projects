package Model.Expressions;

import Model.Structures.IDictionary;
import Model.Structures.IHeapTable;
import Model.Values.IValue;

import Model.Exceptions.ExpressionException;
import Model.Exceptions.DictionaryException;

public class VarExp implements IExp {
    private String id;

    public VarExp(String id) {
        this.id = id;
    }

    public String getId() {
        return this.id;
    }

    @Override
    public IValue eval(IDictionary<String, IValue> symbolTable, IHeapTable<IValue> heapTable) throws ExpressionException, DictionaryException {
        return symbolTable.lookUp(this.id);
    }

    @Override
    public IExp deepCopy() {
        return new VarExp(this.id);
    }

    @Override
    public String toString() {
        return this.id;
    }

}
