package datastructurealgo;

public class reverseVowel {
    public static void main(String[] args) {
        String str = "IceCreAm";

        System.out.println(fun(str));
    }

    public static String fun(String str){
        char []ch = str.toCharArray();
 
        int s = 0;
        int e = str.length()-1;

        while(s<e){
            if(isVowel(ch[s])==false) s++;
            if(isVowel(ch[e])==false) e--;
            
            if(isVowel(ch[s]) && isVowel(ch[e])){
                    char temp = ch[s];
                    ch[s] = ch[e];
                    ch[e] = temp;

                    s++; e--;
            }
        }
        System.out.println(ch.length);
        str = new String(ch);

        return str;
    }

    public static boolean isVowel(char ch){
        return String.valueOf(ch).matches("[aeiouAEIOU]");
    }
}
