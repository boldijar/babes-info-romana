package client1;

import client1.controller.LoginController;
import client1.controller.WaitingRoomController;
import client1.service.ServiceClient;
import client1.view.WaitingRoomView;
import common.model.Clerk;
import common.view.WelcomeView;
import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class WaitingRoom extends Application {

    private Stage stage;
    private ServiceClient serviceClient;

    public static void main(String[] args){
        launch(args);
    }
    @Override
    public void start(Stage primaryStage) throws Exception {
        stage = primaryStage;
        serviceClient = new ServiceClient();
        LoginController loginController = new LoginController(serviceClient);
        WelcomeView view = new WelcomeView(this, loginController);
        Scene scene = new Scene(view);
        stage.setScene(scene);
        stage.show();
    }

    public void userAuthenticated(Clerk user) {
        WaitingRoomController waitingRoomController = new WaitingRoomController(serviceClient);
        WaitingRoomView waitingRoomView = new WaitingRoomView(waitingRoomController);
        Scene scene = new Scene(waitingRoomView);
        stage.setScene(scene);
    }
}
