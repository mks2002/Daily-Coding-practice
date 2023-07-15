import java.util.Arrays;
import java.util.Scanner;

public class BinarySearch {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    System.out.print(" Enter SIZE of the Array: ");
    int n = sc.nextInt();

    int[] arr = new int[n];

    System.out.print(" Enter " + n + " Elements: ");
    for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

    System.out.println(Arrays.toString(arr));

    System.out.print(" Enter target Element to Find: ");
    int target = sc.nextInt();

    System.out.println(target + " Found at Index: " + search(arr, target));
  }

  static int search(int[] nums, int target) {
    /*
        Binary Search Explanation:
        NOTE :   Binary Search can be Only Applied on Sorted Arrays
        let Array is -->  [1,2,3,4]      key = 4
        here,
                indices -->   0   1   2   3
                [ 1,  2,  3,  4 ]
                              /            \
        start          end
        mid = start + (end - start)/2  -->  0 + (3-0)/2   --> 3/2  --> 1
        Step1 :   arr[mid]  = arr[1] --> 2    Not Equal to 4 (key)
                Step2 :   arr[mid] > key   -->  2 > 4    FALSE
        Step3 :   arr[mid] < key   -->  2 < 4    TRUE   --> Search in Right Sub Array
        start --> mid + 1
                [ 1,  2,  3,  4 ]
        indices -->     0   1   2   3
                /   \
        start end
        Now , mid = 2 + (3-2)/2   --> 2 + 1/2  -->  2 + 0 --> 2
        step1 :  arr[mid] = arr[2] --> 3  Not Equal to 4 (key)
                step2 :  arr[mid] > key    --> 3 > 4   FALSE
        step3 :  arr[mid] < key    --> 3 < 4    TRUE  --> Search in Right SUb Array
        now,   start --> mid + 1
                [ 1,  2,  3,  4 ]
        indices -->     0   1   2   3
                /\
        start end
        Hence , mid = 3 + (3-3)/2  --> 3 + 0   --> 3
        step1:  arr[mid] = arr[3] -->  4   YES Equals to 4 (key)   --> return true
         */

    int start = 0;
    int end = nums.length - 1;
    while (start <= end) {
      // find mid
      int mid = start + (end - start) / 2;
      if (nums[mid] == target) return mid; else if (nums[mid] > target) end =
        mid - 1; else start = mid + 1;
    }
    return -1;
  }
}
