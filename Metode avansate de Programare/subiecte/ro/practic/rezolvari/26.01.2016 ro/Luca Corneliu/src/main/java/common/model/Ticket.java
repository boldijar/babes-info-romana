package common.model;

/**
 * Created by luca_ on 26.01.2016 at 14:45.
 */
public class Ticket {
    public Ticket() {
    }

    public void setOrderNumber(Integer orderNumber) {
        this.orderNumber = orderNumber;
    }

    public Integer getOrderNumber() {
        return orderNumber;
    }

    Integer orderNumber;

    public Ticket(Integer orderNumber) {
        this.orderNumber = orderNumber;
    }

    @Override
    public String toString() {
        return orderNumber.toString();
    }
}
