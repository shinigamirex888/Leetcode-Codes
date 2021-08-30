package Leetcode.StacksandQueues;
import java.io.*;
import java.util.*;
public class balancedBrackets {
    public static void main(String[] args) throws Exception {
        Scanner sc=new Scanner(System.in);
        String s=sc.nextLine();
        Stack<Character>st=new Stack<>();
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }else if(ch==')'){
                if(st.size()==0){
                    System.out.println(false);
                    return;
                }else if(st.peek()!='('){
                    System.out.println(false);
                    return;
                }else{
                    st.pop();
                }
            }else if(ch=='}'){
                if(st.size()==0){
                    System.out.println(false);
                    return;
                }else if(st.peek()!='{'){
                    System.out.println(false);
                    return;
                }else{
                    st.pop();
                }
            }else if(ch==']'){
                if(st.size()==0){
                    System.out.println(false);
                    return;
                }else if(st.peek()!='['){
                    System.out.println(false);
                    return;
                }else{
                    st.pop();
                }
            }
        }
        if(st.size()==0){
            System.out.println(true);
        }else{
            System.out.println(false);
        }
    }
}
