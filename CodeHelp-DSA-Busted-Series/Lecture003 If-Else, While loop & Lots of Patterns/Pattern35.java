package com.company;

import java.util.Scanner;

public class Pattern35 {


  public static void main(String[] args) {
    /*
        Pattern 35
                                   1      1
                                   12    21
                                   123  321
                                   12344321
         */
   
    Scanner sc = new Scanner(System.in);
   
    System.out.print(" Enter Number of ROWS for the Pattern: ");
    int n = sc.nextInt();
    pattern(n);
  }

  static void pattern(int n) {
    
    int inSpaces = 2 * n - 2;
    for (int row = 1; row <= n; row++) {
      for (int column = 1; column <= row; column++) {
        System.out.print(column);
      }

      for (int spaces = 1; spaces <= inSpaces; spaces++) {
        System.out.print(" ");
      }
      inSpaces = inSpaces - 2;

      for (int column = row; column >= 1; column--) System.out.print(column);
      System.out.println();
    }
  }
}
