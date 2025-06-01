package datastructurealgo;

public class reverseString2 { // leetcode ******. 541 ****
    public static void main(String[] args) {
        String str = "abcdefg";

        System.out.println(fun(str,8));
    }

    public static String fun(String s, int k){
        char ch[] = s.toCharArray();
        k=k%s.length()-1;

        for(int i =0; i<s.length()-1; ){
            rev(ch, i, i+k-1);  
            i=i+k+k;
        }


         s = new String(ch); 
         return s;
    }

    public static void rev(char ch[], int s, int e){
        while(s<e){
            char temp = ch[s];
            ch[s] = ch[e];
            ch[e] = temp;
            s++;
            e--;
        }
    }
    
}
