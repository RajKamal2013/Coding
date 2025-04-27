package org.core.logging;

import java.io.IOException;
import java.util.logging.*;


public class SampleLogger {

    private static final Logger logger = Logger.getLogger(SampleLogger.class.getName());
    public static void main(String[] args) throws IOException {
        String name = logger.getName();
        logger.log(Level.INFO, "Hello logging");
        //FileHandler handler = new FileHandler(String pattern, boolean append);
        FileHandler handler = new FileHandler("myapp-log.%u.%g.txt",
                true);
        logger.addHandler(handler);
        logger.log(Level.INFO, "Hello logging");
        logger.setFilter(new MyFilter());
        logger.log(Level.INFO, "Hello logging");
        logger.setLevel(Level.INFO);
    }
}
