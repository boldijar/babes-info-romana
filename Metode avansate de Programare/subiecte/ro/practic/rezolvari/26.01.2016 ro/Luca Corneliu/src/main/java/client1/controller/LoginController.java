package client1.controller;

import client1.service.ServiceClient;
import common.model.Clerk;
import javafx.concurrent.Service;
import javafx.concurrent.Task;

/**
 * Created by luca_ on 26.01.2016 at 14:00.
 */
public class LoginController {
    private final ServiceClient serviceClient;

    public LoginController(ServiceClient serviceClient) {
        this.serviceClient = serviceClient;
    }

    public Service<Clerk> authService(String username, String password) {
        return new Service<Clerk>() {
            @Override
            protected Task<Clerk> createTask() {
                return new Task<Clerk>() {
                    @Override
                    protected Clerk call() throws Exception {
                        Clerk clerk = new Clerk(username, password);
                        serviceClient.setClerk(clerk);
                        return serviceClient.auth(clerk);
                    }
                };
            }
        };
    }
}
