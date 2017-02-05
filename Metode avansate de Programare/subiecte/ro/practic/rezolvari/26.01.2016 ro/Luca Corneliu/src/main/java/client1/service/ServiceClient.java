package client1.service;

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
 * Created by luca_ on 26.01.2016 at 14:00.
 */
public class ServiceClient {
    public static final String URL = "http://localhost:8080/server";
    public static final String AUTH = "auth";
    static Log log = LogFactory.getLog(ServiceClient.class.getSimpleName());
    private final AuthHttpComponentsClientHttpRequestFactory requestFactory;
    private RestTemplate restTemplate;
    private Clerk clerk;

    public ServiceClient() {
        log.info("created");
        HttpHost host = new HttpHost("localhost", 8080, "http");
        requestFactory = new AuthHttpComponentsClientHttpRequestFactory(host, clerk);
        restTemplate = new RestTemplate(requestFactory);
    }


    public Clerk auth(Clerk clerk) {
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

    public void setClerk(Clerk clerk) {
        this.clerk = clerk;
        requestFactory.setUser(clerk);
    }

    public Ticket getTicket() {
        return execute(() -> restTemplate.getForObject(String.format("%s/ticket", URL), Ticket.class));
    }
}
