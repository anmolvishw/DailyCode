package datastructurealgo;

public class maximumparenthesis { // leetcopde 1614
    public static void main(String[] args) {
        String str = "(1+(2*3)+((8)/4))+1";

        System.out.println(fun("(()(())((()()))"));
    }


    public static int fun(String s){
        int max = Integer.MIN_VALUE;
        int count = 0;
            for(int i=0; i<s.length(); i++){
                if(s.charAt(i) == '('){
                    count++;
                    max = Math.max(max, count);
                }else if(s.charAt(i) == ')'){
                    count--;
                }
            }
        return max;
    }

   
}
