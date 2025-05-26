package datastructurealgo;

import java.util.Arrays;

public class shiftRightZero {

    public static void shiftRightFun(int arr[]){ // O(n) 
        int count = 0; 

        for(int i =0; i<arr.length; i++){
            if(arr[i] != 0){
                int temp = arr[i];
                arr[i] = arr[count];
                arr[count] = temp;

                count++;
            }
        }
    }

    
    public static void main(String[] args) {
        int arr[] = {4,2,0,5,1,0,0,1}; // Excepted output 4,2,5,1,1,0,0,0

        System.out.println("Before Shift : "+Arrays.toString(arr));
        System.out.print("After Shift : ");
        shiftRightFun(arr);
        System.out.println(Arrays.toString(arr));
    }
}
