package Model.Statements;

import Model.Expressions.IExp;
import Model.ProgramState.ProgramState;
import Model.Types.IntType;
import Model.Types.StringType;
import Model.Values.IValue;
import Model.Values.IntValue;
import Model.Values.StringValue;

import Model.Exceptions.DictionaryException;
import Model.Exceptions.ExpressionException;
import Model.Exceptions.FileException;
import Model.Exceptions.HeapException;
import Model.Exceptions.StatementException;

import java.io.BufferedReader;
import java.io.IOException;

public class readFile implements IStmt {
    private IExp expression;
    private String variableName;

    public readFile(IExp expression, String variableName) {
        this.expression = expression;
        this.variableName = variableName;
    }

    @Override
    public ProgramState execute(ProgramState state) throws StatementException, ExpressionException, DictionaryException, HeapException ,FileException {
        if (state.getSymbolTable().isDefined(this.variableName)) {
            IValue varValue = state.getSymbolTable().lookUp(this.variableName);

            if (varValue.getType().equals(new IntType())) {
                IValue filePath = this.expression.eval(state.getSymbolTable(), state.getHeapTable());
                 
                if (filePath.getType().equals(new StringType())) {
                    StringValue stringFilePath = (StringValue) filePath;

                    if (!state.getFileTable().isDefined(stringFilePath)) {
                        throw new FileException("File is not open.");
                    }

                        BufferedReader file = state.getFileTable().lookUp(stringFilePath);

                        try {
                            String line = file.readLine();

                            if(line != null) {
                                state.getSymbolTable().addKeyValuePair(this.variableName, new IntValue(Integer.parseInt(line)));
                            }

                            else {
                                state.getSymbolTable().addKeyValuePair(this.variableName, new IntValue(0));
                            }
                        } 
                        
                        catch (IOException e) {
                            throw new FileException("Error reading line from file.");
                        }
                }

                else {
                    throw new StatementException("File path is not a string.");
                }
            }

            else {
                throw new StatementException("Variable is not an integer.");
            }
        }

        else {
            throw new StatementException("Variable is not defined.");
        }

        return state;
        
    }

    @Override
    public IStmt deepCopy() {
        return new readFile(this.expression.deepCopy(), this.variableName);
    }

    @Override
    public String toString() {
        return "readFile(" + this.expression.toString() + ", " + this.variableName + ")";
    }

}
