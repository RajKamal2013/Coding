package coding.unitTest;

public class Database {
    int id;
    public boolean isAvailable() {
        // currently not implemented, as this is just demo used in a software test
        return false;
    }
    public int getUniqueId() {
        return 42;
    }

    public void setUniqueId(int eq) {
        id = eq;
    }
}