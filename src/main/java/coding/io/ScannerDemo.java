package coding.io;

import java.util.Scanner;

public class ScannerDemo {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Name:");
        String placeHolder = sc.nextLine();
        System.out.println("Name: " + placeHolder);

        System.out.println("Nationality:");
        placeHolder = sc.next();
        System.out.println("Nationality: " + placeHolder);
    }
}
