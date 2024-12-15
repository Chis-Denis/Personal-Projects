package Repository;

import Model.Exceptions.FileException;

import Model.ProgramState.ProgramState;

import java.util.ArrayList;
import java.io.*;

public class Repository implements IRepository{
    private ArrayList<ProgramState> elements;
    private String logFilePath;
    boolean firstTimeWrite;

    public Repository(ProgramState prgState, String logFilePath) {
        this.elements = new ArrayList<ProgramState>();
        this.elements.add(prgState);
        this.logFilePath = logFilePath;
        this.firstTimeWrite = true;
    }

    @Override
    public ProgramState getCurrentProgramState() {
        return this.elements.get(0);
    }

    @Override
    public void addProgramState(ProgramState newProgramState) {
        this.elements.set(0, newProgramState);
    }

    @Override
    public void logPrgStateExec() throws FileException, IOException {
        PrintWriter logFile;

        try {
            if (this.firstTimeWrite) {
                logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, false)));
                this.firstTimeWrite = false;
            }

            else {
                logFile = new PrintWriter(new BufferedWriter(new FileWriter(this.logFilePath, true)));
            }
        }

        catch (IOException e) {
            throw new FileException("Could not open/create/exist log file.");
        }

        logFile.print(this.getCurrentProgramState().toString());
        logFile.flush();
        logFile.close();
    }

}
