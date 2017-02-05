package client2.view;

import client2.controller.ClerkOfficeController;
import common.model.Ticket;
import common.view.AlertUtils;
import javafx.collections.ObservableList;
import javafx.concurrent.Service;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.Dialog;
import javafx.scene.layout.VBox;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;

/**
 * Created by luca_ on 26.01.2016 at 15:26.
 */
public class ClerkOfficeView extends VBox {
    private final Log logger = LogFactory.getLog(ClerkOfficeView.class.getSimpleName());
    private final ClerkOfficeController clerkOfficeController;

    public ClerkOfficeView(ClerkOfficeController clerkOfficeController) {
        this.clerkOfficeController = clerkOfficeController;

        ObservableList<Node> children = getChildren();

        Button buttonNext = new Button("Urmatorul");
        buttonNext.setOnAction(event -> nextEvent());
        children.add(buttonNext);

        Button buttonArrived = new Button("Sosit");
        buttonArrived.setOnAction(event -> arrivedEvent());
        children.add(buttonArrived);
    }

    private void arrivedEvent() {
        Service<Boolean> arrivedService = clerkOfficeController.arrived();
        Dialog<Boolean> dialog = AlertUtils.cancellableDialog("Sosit", "Asteptati ...");
        dialog.setOnCloseRequest(event -> arrivedService.cancel());
        dialog.show();

        arrivedService.setOnSucceeded(event -> {
            logger.info("succeeded ...");
            dialog.close();
        });

        arrivedService.setOnFailed(event -> {
            logger.info("failed ...");
            dialog.close();
            Throwable e = event.getSource().getException();
            AlertUtils.showError(e);
        });
        arrivedService.setOnCancelled(event -> logger.info("cancelled ..."));

        logger.info("starting ...");
        arrivedService.start();
    }

    private void nextEvent() {
        Service<Ticket> nextService = clerkOfficeController.next();
        Dialog<Boolean> dialog = AlertUtils.cancellableDialog("Urmatorul", "Astaptati ...");
        dialog.setOnCloseRequest(event -> nextService.cancel());
        dialog.show();

        nextService.setOnSucceeded(event -> {
            logger.info("succeeded ...");
            dialog.close();
        });

        nextService.setOnFailed(event -> {
            logger.info("failed ...");
            dialog.close();
            Throwable e = event.getSource().getException();
            AlertUtils.showError(e);
        });
        nextService.setOnCancelled(event -> logger.info("cancelled ..."));

        logger.info("starting ...");
        nextService.start();
    }
}
