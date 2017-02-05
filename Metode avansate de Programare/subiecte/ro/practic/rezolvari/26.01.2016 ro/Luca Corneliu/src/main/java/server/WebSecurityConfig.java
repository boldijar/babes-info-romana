/*
 * Copyright (c)  21.12.2015
 * Name: Luca Corneliu Daniel
 * Contact: luca_corneliu2003@yahoo.com
 *
 */

package server;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.authentication.builders.AuthenticationManagerBuilder;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;

@Configuration
@EnableWebSecurity
public class WebSecurityConfig extends WebSecurityConfigurerAdapter {
    @Override
    protected void configure(HttpSecurity http) throws Exception {
        http
                .authorizeRequests()
                .antMatchers("/**")
//                .permitAll()
                .authenticated()
                .and()
                .httpBasic()
                .and()
                .csrf().disable(); // Authorization: Basic user:password
    }
    @Autowired
    protected void configureGlobal(AuthenticationManagerBuilder auth) throws Exception {

        auth.inMemoryAuthentication()
                .withUser("f1").password("f1").roles("USER")
                .and()
                .withUser("f2").password("f2").roles("USER")
                .and()
                .withUser("admin").password("admin").roles("ADMIN");
    }
}
