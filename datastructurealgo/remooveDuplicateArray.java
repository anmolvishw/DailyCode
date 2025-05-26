package datastructurealgo;

import java.util.ArrayList;

public class remooveDuplicateArray {
    public static int fun(int arr[]){
        ArrayList<Integer> list = new ArrayList<>();

        for(int i : arr){
            if(!list.contains(i)){
                list.add(i);
            }
        }

        int res = list.size();
        // arr = list.stream().mapToInt(Integer::intValue).toArray();
        for(int i =0 ; i<list.size(); i++){
            System.out.print(list.get(i)+" ");
        }
        System.out.println();
        return res;
    }
    public static void main(String[] args) {
        int arr[] = {32,40 ,43, 60, 72, 78, 82, 82, 82, 99};  //32 40 43 60 72 78 82 82 82 99
        
        System.out.println(fun(arr));
    }
}
