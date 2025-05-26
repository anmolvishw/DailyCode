package datastructurealgo;

import java.util.Arrays;

public class ReverseArray {

    public static void reverse(int arr[]){ // o(n)
        int s = 0;
        int e = arr.length - 1;

        while(s < e){
            int temp = arr[s];
            arr[s] = arr[arr.length - s - 1];
            arr[arr.length - s - 1] = temp;

            s++; e--;
        }
    }
    public static void main(String[] args) {
        int arr[] = {1,2,3,4,5,6};

        System.out.println("Before Reverse : "+Arrays.toString(arr));
        System.out.print("After Reversed : ");
        reverse(arr);
        System.out.println(Arrays.toString(arr));

    }
}