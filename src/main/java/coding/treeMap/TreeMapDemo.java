package coding.treeMap;

import java.util.TreeMap;

public class TreeMapDemo {
  public static void main(String[] args) {
    TreeMap<String, Integer> map = new TreeMap<>();

    map.put("Oracle", 43);
    map.put("Microsoft", 56);
    map.put("Apple", 43);
    map.put("Novartis", 87);

    System.out.println(map);

    TreeMap<String, Integer> finalMap = new TreeMap<>();

    map.put("Google", 65);
    map.put("Audi", 32);
    finalMap.putAll(map);

    System.out.println(finalMap);

    map.put("Oracle", 43);
    map.put("Microsoft", 56);
    map.put("Apple", 43);
    map.put("Novartis", 87);

    System.out.println(
        "Removing Oracle from Map. This will return the value corresponding to Oracle: "
            + map.remove("Oracle"));
    System.out.println(
        "Removing Google from Map. This will return null as Google is not present in the Map: "
            + map.remove("Google"));
    }
}
