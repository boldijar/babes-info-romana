package server.repository;

import common.model.Ticket;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.jdbc.core.JdbcTemplate;
import org.springframework.stereotype.Repository;

import java.util.List;

/**
 * Created by luca_ on 26.01.2016 at 16:04.
 */
@Repository
public class RepositoryS {

    @Autowired
    private JdbcTemplate jdbcTemplate;

    Integer orderNumber = 0;

    public Ticket getTicket() {
        orderNumber++;
        jdbcTemplate.update("insert into Tickets values(?)", orderNumber);
        List<Ticket> tickets = jdbcTemplate.query("select orderNumber from Tickets", (rs, i) -> {
            return new Ticket(rs.getInt("orderNumber"));
        });
        return tickets.get(0);
    }

    public void deleteTicket(Ticket current) {
        jdbcTemplate.update("delete from Tickets where orderNumber = ?", current.getOrderNumber());
    }
}
