package client2.service;

import client1.service.AuthHttpComponentsClientHttpRequestFactory;
import client1.service.ServiceException;
import common.model.Clerk;
import common.model.Ticket;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.http.HttpHost;
import org.springframework.web.client.HttpClientErrorException;
import org.springframework.web.client.ResourceAccessException;
import org.springframework.web.client.RestTemplate;

import java.util.concurrent.Callable;

/**
 * Created by luca_ on 26.01.2016 at 15:04.
 */
public class ServiceClerkClient {

    public static final String URL = "http://localhost:8080/server";
    public static final String AUTH = "auth";
    public static final String NEXT = "next";
    public static final String ARRIVED = "arrived";
    static Log log = LogFactory.getLog(ServiceClerkClient.class.getSimpleName());
    private final AuthHttpComponentsClientHttpRequestFactory requestFactory;
    private RestTemplate restTemplate;
    private Clerk clerk;
    private int counter;

    public ServiceClerkClient() {
        log.info("created");
        HttpHost host = new HttpHost("localhost", 8080, "http");
        requestFactory = new AuthHttpComponentsClientHttpRequestFactory(host, clerk);
        restTemplate = new RestTemplate(requestFactory);
    }

    public void setClerk(Clerk clerk) {
        this.clerk = clerk;
        requestFactory.setUser(clerk);
    }

    public Clerk auth(Clerk clerk, int counter) {
        clerk.setOnline(counter);
        return execute(() -> restTemplate.postForObject(String.format("%s/%s", URL, AUTH), clerk, Clerk.class));
    }
    private <T> T execute(Callable<T> callable) throws ServiceException {
        try {
            return callable.call();
        } catch (ResourceAccessException | HttpClientErrorException e) { // server down, resource exception
            throw new ServiceException(e);
        } catch (Exception e) {
            throw new ServiceException(e);
        }
    }

    public void setCounter(int counter) {
        this.counter = counter;
    }

    public Ticket next() {
        return execute(() -> restTemplate.getForObject(String.format("%s/%s", URL, NEXT), Ticket.class));
    }

    public Boolean arrived() {
        return execute(() -> {
            restTemplate.delete(String.format("%s/%s", URL, ARRIVED));
            return true;
        });
    }
}
