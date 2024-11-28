package org.project;

public class User {
    final String username;
    final boolean hasBlog;
    final Integer id;

    public User(String username){
        this.username = username;
        this.hasBlog = false;
        this.id = 0;
    }


    public User(String username, boolean hasBlog, Integer id){
        this.username = username;
        this.hasBlog = hasBlog;
        this.id =id;
    }

    public boolean hasBlog(){
        return hasBlog;
    }
}
