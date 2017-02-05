package client2.view;

import client2.ClerkOffice;
import client2.controller.LoginController;
import common.IntegerField;
import common.model.Clerk;
import common.view.AlertUtils;
import javafx.collections.ObservableList;
import javafx.concurrent.Service;
import javafx.scene.Node;
import javafx.scene.control.*;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/**
 * Created by luca_ on 26.01.2016 at 15:06.
 */
public class WelcomeView extends VBox {
    private static final Log LOG = LogFactory.getLog(WelcomeView.class);

    private final ClerkOffice application;
    private IntegerField counter;
    private LoginController loginController;

    private TextField username;
    private PasswordField password;
    private Button authButton;

    // background service
    private Service<Clerk> authService;
    public WelcomeView(ClerkOffice clerkOffice, LoginController loginController) {

        setMinWidth(240);
        application = clerkOffice;
        this.loginController = loginController;

        ObservableList<Node> children = getChildren();
        //title
        children.add(new Text("Sala de asteptare\n Buna ziua"));
        // username (label + textfield)
        children.add(new Label("Username:"));
        username = new TextField();
        children.add(username);
        // password (label + textfield)
        children.add(new Label("Password:"));
        password = new PasswordField();
        children.add(password);

        children.add(new Label("Ghiseu:"));
        counter = new IntegerField();
        children.add(counter);
        // auth button (login or cancel)
        authButton = new Button("Login");

        authButton.setOnAction(btnEvent -> onLoginButtonTriggered());
        authButton.setOnKeyPressed(event -> onLoginButtonTriggered());
        children.add(authButton);
    }
    private void onLoginButtonTriggered() {
        String authButtonText = authButton.getText();
        LOG.info(authButtonText + " button triggered");
        Dialog<Boolean> booleanDialog = AlertUtils.cancellableDialog("Logare", "Va rugam asteptati!");
        booleanDialog.setOnCloseRequest(dialogEvent -> {
            if (authService != null) {
                authService.cancel(); // cancel the call from app thread
            }
        });
        booleanDialog.show();
        authService = this.loginController.authService(username.getText(), password.getText(), Integer.parseInt(counter.getText())); // just a reference to an async call/task
        authService.setOnSucceeded(e -> { // prepare what to do when the call succeeds
            Clerk user = (Clerk) e.getSource().getValue();
            LOG.info("auth service succeeded, " + user); // executed on app thread
            this.application.userAuthenticated(user);
            booleanDialog.close();
        });
        authService.setOnFailed(e -> { // prepare what to do when the call fails
            // executed on app thread
            Throwable exception = e.getSource().getException();
            LOG.warn("auth service failed", exception);
            booleanDialog.close();
            AlertUtils.showError(exception);
        });
        authService.setOnCancelled(e -> { // prepare what to do when the call was cancelled
            // executed on app thread
            LOG.info("auth service cancelled");
        });
        LOG.info("starting auth service");
        authService.start(); // start the async call/task (from app thread)
        // the task is executed on background threads
    }
}
