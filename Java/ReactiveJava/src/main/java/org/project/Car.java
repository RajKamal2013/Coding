package org.project;

import lombok.AllArgsConstructor;
import lombok.Data;

@AllArgsConstructor
@Data
public class Car {
    public Integer price;
    public String year;
    public String make;
    public String model;

    enum Type{
        ALL_ELECTRIC,
        ALL_DIESEL,
        ALL_PETROL
    }

    public Type type;

}
