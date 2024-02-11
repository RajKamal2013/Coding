package coding.record;

public record Vehicle(String brand, String licensePlate) {

    public Vehicle(String brand) {
        this(brand, null);
    }

}