package datastructurealgo;

public class plusOne { // leetcode 66

    public static void main(String[] args) {
        int arr[] = {9,8,7,6,5,4,3,2,1,0};

        int res[] = fun(arr);

        for(int i : res){
            System.out.print(i+" ");
        }
    }

    public static int[] fun(int digits[]){
        for (int i = digits.length - 1; i >= 0; i--) {
            // If digit is less than 9, just add 1 and return
            if (digits[i] < 9) {
                digits[i]++;
                return digits;
            }
            // Otherwise set to 0 and continue loop
            digits[i] = 0;
        }

        // If we're here, all digits were 9 (e.g., 999 + 1 = 1000)
        int[] newNumber = new int[digits.length + 1];
        newNumber[0] = 1; // rest are 0 by default
        return newNumber;
    }
    }
    

