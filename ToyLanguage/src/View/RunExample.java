package View;

import Controller.Controller;
import Model.Exceptions.*;

import java.io.IOException;

public class RunExample extends Command {
    private Controller controller;

    public RunExample(String key, String description, Controller controller) {
        super(key, description);
        this.controller = controller;
    }

    @Override
    public void execute() {
        try {
            this.controller.reinitializeProgramState();
            this.controller.allSteps();
        } 
        catch (ControllerException | ListException | StackException | IOException | ExpressionException | DictionaryException | StatementException | HeapException |FileException e) {
            System.out.println(e.getMessage());
        }
    }

}
