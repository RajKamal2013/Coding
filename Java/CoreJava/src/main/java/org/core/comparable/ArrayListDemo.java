package org.core.comparable;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class ArrayListDemo {

    public static void main(String args[]) {
        List<Vehicle> list = new ArrayList<>();
        list.add(new Vehicle("Volkswagen", 2010));
        list.add(new Vehicle("Audi", 2009));
        list.add(new Vehicle("Ford", 2001));
        list.add(new Vehicle("BMW", 2015));

        Collections.sort(list);
        for (Vehicle vehicle : list) {
            System.out.println("Vehicle Brand: " + vehicle.brand + ", Vehicle Make: " + vehicle.makeYear);
        }
    }
}
