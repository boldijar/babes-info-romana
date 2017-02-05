package common.model;

/**
 * Created by luca_ on 26.01.2016 at 14:12.
 */
public class Clerk {
    private String username;

    private String password;

    private Integer counter;

    public Clerk() {
    }

    public Clerk(String username, String password) {
        this.password = password;
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public Integer getOnline() {
        return counter;
    }

    public void setOnline(Integer online) {
        this.counter = online;
    }
}
