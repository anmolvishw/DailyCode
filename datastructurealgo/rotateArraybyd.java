package datastructurealgo;
import java.util.Arrays;


public class rotateArraybyd {
    public static void rotatebyd(int arr[],int d){
        int n = arr.length;
        d %= n;

        reverse(arr, 0, d-1);

        reverse(arr, d, n-1);

        reverse(arr, 0, n-1);
    }

    public static void reverse(int arr[], int s, int e){
        while(s < e){
            int temp = arr[s];
            arr[s] = arr[e];
            arr[e] = temp;

            s++; e--;
        }
    }
    public static void main(String[] args) {
        int arr[] = {7,4,5,31,2,0,11,7};
        int d = 3;


        System.out.println("Before Left Rotate by "+d+" : "+Arrays.toString(arr));
        rotatebyd(arr, d);
        System.out.println("After Left Rotate  by "+d+" : "+Arrays.toString(arr));


    }
}
