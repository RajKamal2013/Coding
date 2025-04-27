package org.core.logging;

import java.util.logging.Filter;
import java.util.logging.LogRecord;

public class MyFilter implements Filter {
    public boolean isLoggable(LogRecord record) {
        return false;
    }
}
