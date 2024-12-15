package Repository;

import Model.ProgramState.ProgramState;

import Model.Exceptions.FileException;

import java.io.IOException;

public interface IRepository {
    ProgramState getCurrentProgramState();
    void addProgramState(ProgramState newProgramState);
    void logPrgStateExec() throws FileException, IOException;
    
}
