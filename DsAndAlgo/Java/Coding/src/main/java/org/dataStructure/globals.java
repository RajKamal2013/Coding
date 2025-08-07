package org.dataStructure;

public class globals {
    public static int []warning = {1, 2, 3};
    public static boolean[] warn = {true, true, false};
    public static int []error = {1, 2, 3};
    public static boolean[] err = {true, true, false};
    public static int[]debug = {1, 2, 3};
    public static boolean[]dbg = {true, false, false};

    public static void LogWarning(int level, int line, String warning , String fileName) {
        if (warn[level]) {
            System.out.println("WARNING:" + fileName + ":" + line + ":" + warning);
        }
    }
    public static void LogError(int level, int line, String fileName, String error) {
        if (err[level]) {
            System.out.println("WARNING:" + fileName + ":" + line + ":" + error);
        }
    }

    public static void LogDBG(int level, int line, String fileName, String error) {
        if (err[level]) {
            System.out.println("Debug:" + fileName + ":" + line + ":" + error);
        }
    }
}
