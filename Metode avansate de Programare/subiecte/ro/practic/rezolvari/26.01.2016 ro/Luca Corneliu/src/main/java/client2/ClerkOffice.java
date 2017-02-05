package client2;

import client2.controller.ClerkOfficeController;
import client2.controller.LoginController;
import client2.service.ServiceClerkClient;
import client2.view.ClerkOfficeView;
import client2.view.WelcomeView;
import common.model.Clerk;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

/**
 * Created by luca_ on 26.01.2016 at 14:57.
 */
public class ClerkOffice extends Application{
    private Stage stage;
    private ServiceClerkClient serviceClerkClient;

    public static void main(String[] args){
        launch(args);
    }

    @Override
    public void start(Stage primaryStage) throws Exception {
        stage = primaryStage;
        serviceClerkClient = new ServiceClerkClient();
        LoginController loginController = new LoginController(serviceClerkClient);
        WelcomeView view = new WelcomeView(this, loginController);
        Scene scene = new Scene(view);
        stage.setScene(scene);
        stage.show();
    }

    public void userAuthenticated(Clerk user) {
        ClerkOfficeController waitingRoomController = new ClerkOfficeController(serviceClerkClient);
        ClerkOfficeView waitingRoomView = new ClerkOfficeView(waitingRoomController);
        Scene scene = new Scene(waitingRoomView);
        stage.setScene(scene);
    }
}
