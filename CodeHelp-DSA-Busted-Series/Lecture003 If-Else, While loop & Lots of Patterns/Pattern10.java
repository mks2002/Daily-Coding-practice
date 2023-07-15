package com.company;

import java.util.Scanner;

public class Pattern10 {
    // Pattern 10
    public static void main(String [] args){
        /*
        Pattern 10
                         *
                        * *
                       * * *
                      * * * *
                     * * * * *
         */

       
        Scanner sc = new Scanner(System.in);

       
        System.out.print(" Enter Number of ROWS for the Pattern: ");
        int n = sc.nextInt();
        pattern(n);
    }

    static void pattern(int n){
       
        for(int row =1; row <= n ; row++){
            for(int spaces = 1; spaces<= n - row; spaces++){
                System.out.print("  ");
            }
            for(int column = 1; column <= row ; column++){
                System.out.print("*   ");
            }
            System.out.println();
        }
    }
}
