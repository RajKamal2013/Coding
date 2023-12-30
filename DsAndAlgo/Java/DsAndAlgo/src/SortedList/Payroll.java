package DS.SortedList;

public class Payroll {
    private Integer ID;
    private String name;
    private String address;

    Payroll(int ID, String name, String address) {
        this.ID = ID;
        this.name = name;
        this.address = address;
    }

    public Integer getID() { return this.ID; }
    public String getName() { return  this.name; }
    public String getaddr() { return this.address; }
    public String toString() {
        String str = "[ID:" + ID + "," + name + "," + address + "]";
        return str;
    }

}
