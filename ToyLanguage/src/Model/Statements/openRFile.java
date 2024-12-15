package Model.Statements;

import Model.ProgramState.ProgramState;
import Model.Types.StringType;
import Model.Values.IValue;
import Model.Values.StringValue;
import Model.Expressions.IExp;

import Model.Exceptions.DictionaryException;
import Model.Exceptions.ExpressionException;
import Model.Exceptions.FileException;
import Model.Exceptions.HeapException;
import Model.Exceptions.StatementException;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileNotFoundException;

public class openRFile implements IStmt {
    private IExp expression;

    public openRFile(IExp expression) {
        this.expression = expression;
    }

    @Override
    public ProgramState execute(ProgramState state) throws StatementException, ExpressionException, DictionaryException, FileException, HeapException {
        IValue filePath = this.expression.eval(state.getSymbolTable(), state.getHeapTable());

        if (filePath.getType().equals(new StringType())) {
            StringValue stringFilePath = (StringValue) filePath;

            if (state.getFileTable().isDefined(stringFilePath)) {
                throw new FileException("File path already in the file table.");
            }

            try {
                BufferedReader file = new BufferedReader(new FileReader(stringFilePath.getValue()));
                state.getFileTable().addKeyValuePair(stringFilePath, file);
            } 
            
            catch (FileNotFoundException e) {
                throw new FileException("File not found.");
            }
        } 

        else {
            throw new StatementException("File path is not a string.");
        }

        return state;
    }

    @Override
    public IStmt deepCopy() {
        return new openRFile(this.expression.deepCopy());
    }

    @Override
    public String toString() {
        return "openRFile(" + this.expression.toString() + ")";
    }

}
