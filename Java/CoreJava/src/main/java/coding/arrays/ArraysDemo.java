package coding.arrays;

import java.util.Arrays;
import java.util.List;

public class ArraysDemo {
    public static void main(String args[]) {

        Integer[] numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
        Arrays.fill(numbers, 20);

        for (int i : numbers) {
            System.out.print(i + " ");
        }

        List<Integer> list = Arrays.asList(numbers);

        System.out.print(list);


        Integer[] numbers1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        Integer[] numbers2 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        boolean isEqual = Arrays.equals(numbers1, numbers2);


        System.out.print("Checking if two arrays are equal : " + isEqual);

        Employee[] employees = { new Employee(123, "Jay"), new Employee(124, "Roy"), new Employee(125, "Nikki"),
                new Employee(126, "Tom") };

        int index = Arrays.binarySearch(employees, new Employee(124, "Roy"), (emp1, emp2) -> emp1.empId - emp2.empId);

        System.out.println("The index of employee object in the array is " + index);

        Integer[] numbers3 = { 10, 2, 32, 12, 15, 76, 17, 48, 79, 9 };
        Arrays.sort(numbers3);

        for (int i : numbers3) {
            System.out.print(i + " ");
        }
    }
}


