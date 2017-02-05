package client1.service;

/**
 * Created by luca_ on 26.01.2016 at 14:30.
 */
public class ServiceException extends RuntimeException {
    public ServiceException(Exception e) {
        super(e);
    }

    public ServiceException(String message) {
        super(message);
    }
}
