package org.core.collections.hashMap;

import java.util.Collection;
import java.util.HashMap;
import java.util.Map;
import java.util.Set;

public class HashMapDemo {
    public static void main(String[] args){
        Map<String, Integer> stockPrice = new HashMap<>();

        stockPrice.put("Oracle", 56);
        stockPrice.put("Fiserv", 117);
        stockPrice.put("BMW", 73);
        stockPrice.put("Microsoft", 213);

        System.out.println(stockPrice.containsKey("Oracle"));

        System.out.println(stockPrice.containsValue(73));

        System.out.println("HashMap Keys");
        Set<String> keys = stockPrice.keySet();
        for(String key : keys) {
            System.out.println(key);
        }

        System.out.println("HashMap Values");
        Collection<Integer> values = stockPrice.values();
        for(Integer value : values) {
            System.out.println(value);
        }

        System.out.println(stockPrice.isEmpty());

        System.out.println(stockPrice.get("Oracle"));
        System.out.println(stockPrice.get("Google")); //This will return null.

        //Since Google is not present in our Map, this will insert it with default value of 100.
        System.out.println(stockPrice.getOrDefault("Google", 100));

        stockPrice.replace("Fiserv", 100);



    }
}
