package datastructurealgo;

public class removeDuplicates { // *** leetcode 26 using two pinter approach
    public static void main(String[] args) {
       
        int arr[] = {1,2,2,4};

        int res = removedup(arr);

        for(int i =0; i<res; i++){
            System.out.print(arr[i]+" ");
        }
    }

    

    public static int removedup(int []arr){
        if(arr.length == 0) return 0;
        int i =0; 
        for(int j =1; j<arr.length; j++){
            if(arr[j] != arr[i]){
                i++;
                arr[i] = arr[j];
            }
        }

        return i + 1;
    }
}
