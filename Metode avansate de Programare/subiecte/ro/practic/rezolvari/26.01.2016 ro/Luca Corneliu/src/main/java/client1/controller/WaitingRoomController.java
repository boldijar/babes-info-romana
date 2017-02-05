package client1.controller;

import client1.service.ServiceClient;
import common.model.Ticket;
import javafx.concurrent.Service;
import javafx.concurrent.Task;

/**
 * Created by luca_ on 26.01.2016 at 14:36.
 */
public class WaitingRoomController {
    private final ServiceClient serviceClient;

    public WaitingRoomController(ServiceClient serviceClient) {
        this.serviceClient = serviceClient;

    }

    public Service<Ticket> getTicket() {
        return new Service<Ticket>() {
            @Override
            protected Task<Ticket> createTask() {
                return new Task<Ticket>() {
                    @Override
                    protected Ticket call() throws Exception {
                        return serviceClient.getTicket();
                    }
                };
            }
        };
    }
}
