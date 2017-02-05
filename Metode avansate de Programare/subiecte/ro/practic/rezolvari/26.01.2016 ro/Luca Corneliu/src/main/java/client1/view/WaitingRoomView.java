package client1.view;

import client1.controller.WaitingRoomController;
import common.view.AlertUtils;
import common.model.Ticket;
import javafx.collections.ObservableList;
import javafx.concurrent.Service;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.control.Dialog;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;

/**
 * Created by luca_ on 26.01.2016 at 14:36.
 */
public class WaitingRoomView extends VBox {
    private final WaitingRoomController waitingRoomController;
    private final Text ticketText;
    private final Text clientNumber;
    private final Text counterNumber;

    public WaitingRoomView(WaitingRoomController waitingRoomController) {
        this.waitingRoomController = waitingRoomController;

        ObservableList<Node> children = getChildren();
        //title
        children.add(new Text("Buna ziua!"));
        children.add(new Text("Apasati butonul tichet!"));
        children.add(new Text("Numar ordine: "));
        ticketText = new Text();
        children.add(ticketText);


        Button ticketButton = new Button("Tichet");
        ticketButton.setOnAction(event -> onTicketButtonTriggered());

        children.add(new Text("Clientul urmator este: "));
        clientNumber = new Text("");
        children.add(clientNumber);
        children.add(new Text("la ghiseul: "));
        counterNumber = new Text("");
        children.add(counterNumber);

        children.add(ticketButton);
    }

    private void onTicketButtonTriggered() {
        Service<Ticket> getTicketService = waitingRoomController.getTicket();
        Dialog<Boolean> gettingDialog = AlertUtils.cancellableDialog("Aduce", "Va rugam asteptati!");
        gettingDialog.setOnCloseRequest(event -> getTicketService.cancel());
        gettingDialog.show();

        getTicketService.setOnSucceeded(event -> {
            ticketText.setText(getTicketService.getValue().toString());
            gettingDialog.close();
        });

        getTicketService.setOnFailed(event -> {
            gettingDialog.close();
            Throwable e = event.getSource().getException();
            AlertUtils.showError(e);
        });

        getTicketService.setOnCancelled(event -> gettingDialog.close());

        getTicketService.start();
    }
    public void update(String clientN, String counterN){

    }
}
