package org.core.record;

public class RecordExample {
    public static void main(String[] args) {

        Vehicle vehicle = new Vehicle("Mercedes", "UX 1238 A95");

        System.out.println( vehicle.brand() );
        System.out.println( vehicle.licensePlate() );

        System.out.println( vehicle.toString() );

    }
}
