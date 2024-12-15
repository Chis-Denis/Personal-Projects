package Model.Statements;

import Model.Exceptions.DictionaryException;
import Model.Exceptions.ExpressionException;
import Model.Exceptions.StatementException;
import Model.Exceptions.FileException;
import Model.Exceptions.HeapException;
import Model.ProgramState.ProgramState;

public interface IStmt {
    String toString();
    ProgramState execute(ProgramState currentState) throws StatementException, ExpressionException, DictionaryException, HeapException ,FileException;
    IStmt deepCopy();
}
