package org.core.oops;

class User {

    // Private fields
    private String userName;
    private String password;

    //Parameterzied constructor to create a new users
    public User(String userName, String password) {
        this.userName = userName;
        this.password = password;
    }

    public void login(String userName, String password) {
        //Check if the username and password match
        if (this.userName.toLowerCase().equals(userName.toLowerCase()) && this.password.equals(password)) {
            // .toLowrcase converts all the characters to lowercase & .equals checks if two strings match

            System.out.println("Access Granted against the username: "+this.userName +" and password: "+this.password);
        }
        else System.out.println("Invalid Credentials!"); //Else invalid credentials
    }

}

