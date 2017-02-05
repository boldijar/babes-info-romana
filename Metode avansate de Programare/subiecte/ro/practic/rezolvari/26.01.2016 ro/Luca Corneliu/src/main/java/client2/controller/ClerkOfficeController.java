package client2.controller;

import client2.service.ServiceClerkClient;
import common.model.Ticket;
import javafx.concurrent.Service;
import javafx.concurrent.Task;

/**
 * Created by luca_ on 26.01.2016 at 15:26.
 */
public class ClerkOfficeController {
    private final ServiceClerkClient serviceClerkClient;

    public ClerkOfficeController(ServiceClerkClient serviceClerkClient) {
        this.serviceClerkClient = serviceClerkClient;
    }

    public Service<Ticket> next() {
        return new Service<Ticket>() {
            @Override
            protected Task<Ticket> createTask() {
                return new Task<Ticket>() {
                    @Override
                    protected Ticket call() throws Exception {
                        return serviceClerkClient.next();
                    }
                };
            }
        };
    }

    public Service<Boolean> arrived() {
        return new Service<Boolean>() {
            @Override
            protected Task<Boolean> createTask() {
                return new Task<Boolean>() {
                    @Override
                    protected Boolean call() throws Exception {
                        return serviceClerkClient.arrived();
                    }
                };
            }
        };
    }
}
