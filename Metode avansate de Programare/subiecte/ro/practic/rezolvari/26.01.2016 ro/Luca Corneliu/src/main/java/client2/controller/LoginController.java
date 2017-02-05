package client2.controller;

import client2.service.ServiceClerkClient;
import common.model.Clerk;
import javafx.concurrent.Service;
import javafx.concurrent.Task;

/**
 * Created by luca_ on 26.01.2016 at 15:04.
 */
public class LoginController {
    private final ServiceClerkClient serviceClerkClient;

    public LoginController(ServiceClerkClient serviceClerkClient) {
        this.serviceClerkClient = serviceClerkClient;
    }

    public Service<Clerk> authService(String username, String password, int counter) {
        return new Service<Clerk>() {
            @Override
            protected Task<Clerk> createTask() {
                return new Task<Clerk>() {
                    @Override
                    protected Clerk call() throws Exception {
                        Clerk clerk = new Clerk(username, password);
                        serviceClerkClient.setClerk(clerk);
                        serviceClerkClient.setCounter(counter);
                        return serviceClerkClient.auth(clerk, counter);
                    }
                };
            }
        };
    }
}
