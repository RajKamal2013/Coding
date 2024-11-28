package org.example;

import java.util.logging.Logger;

public class MyUnit {
    static Logger logger = Logger.getLogger(MyUnit.class.getName());

    public String concatenate(String one, String two) {
        logger.info("Concatenate string!!");
        return one + two;
    }
}
