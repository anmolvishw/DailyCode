package datastructurealgo;
import java.util.Arrays;

public class SecondLargest {
    public static int secoondLargest(int arr[]){
            int large = Integer.MIN_VALUE;
            int second = Integer.MIN_VALUE;

            for(int i =0; i<arr.length; i++){   // O(N)
                    if(arr[i] > large){
                        second = large;
                        large = arr[i];
                    }

                    if(arr[i] < large && arr[i] > second){
                        second = arr[i];
                    }
            }

            return second;
    }
    public static void main(String[] args) {
        int arr[] = {8,7,6,-1,7,5,8,9};

        System.out.println("Values are : "+Arrays.toString(arr));
        System.out.println("Second Largest is : "+secoondLargest(arr));
    }
}
