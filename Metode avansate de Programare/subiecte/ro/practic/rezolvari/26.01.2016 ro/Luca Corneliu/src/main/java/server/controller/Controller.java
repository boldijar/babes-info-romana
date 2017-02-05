package server.controller;

import common.model.Clerk;
import common.model.Ticket;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.security.core.context.SecurityContextHolder;
import org.springframework.security.core.userdetails.User;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;
import server.repository.RepositoryS;

/**
 * Created by luca_ on 26.01.2016 at 16:04.
 */

@RestController
public class Controller {

    @Autowired
    RepositoryS repository;

    Ticket current;
    Ticket oldCurrent;

    @RequestMapping(value = "server/auth", method = RequestMethod.POST)
    public Clerk auth(@RequestBody Clerk clerk1){
        User user = (User) SecurityContextHolder.getContext().getAuthentication().getPrincipal();
        Clerk clerk = new Clerk(user.getUsername(),user.getPassword());
        return clerk;
    }

    @RequestMapping(value = "server/ticket", method = RequestMethod.GET)
    public Ticket getTicket(){
        current = repository.getTicket();
        return current;
    }

    @RequestMapping(value = "server/next", method = RequestMethod.GET)
    public Ticket next(){
        oldCurrent = current;
        current = repository.getTicket();
        repository.deleteTicket(current);
        return oldCurrent;
    }

    @RequestMapping(value = "server/arrived", method = RequestMethod.DELETE)
    public Boolean arrived(){
        oldCurrent = null;
        return true;
    }
}
