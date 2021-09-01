package Leetcode.StacksandQueues;

import java.io.*;
import java.util.*;

public class largestAreaHistogram{
  

public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int n = Integer.parseInt(br.readLine());
    int[] arr = new int[n];
    for(int i = 0; i < n; i++){
       arr[i] = Integer.parseInt(br.readLine());
    }

   largestAreaHistogram(arr);
 }
 public static void largestAreaHistogram(int[] arr) {
         
        int[] lb = NSEOnLeft(arr);
        int[] rb = NSEOnRight(arr);
        
        int maxArea = Integer.MIN_VALUE;
        for(int i=0;i<arr.length;i++){
            int height = arr[i];
            int width = rb[i] - lb[i] - 1;
            int correspondingArea = height * width;
            if(correspondingArea > maxArea){
                maxArea = correspondingArea;
            }
        }
        System.out.println(maxArea);
    }
    
    public static int[] NSEOnLeft(int[] arr) {
        int ans[] = new int[arr.length];
        Stack < Integer > stack = new Stack < > ();
        for (int i = arr.length - 1; i >= 0; i--) {
            while (stack.size() > 0 && arr[i] < arr[stack.peek()]) {
                ans[stack.pop()] = i;
            }
            stack.push(i);
        }
        while (stack.size() > 0) {
            ans[stack.pop()] = -1;
        }
        return ans;
    }
    public static int[] NSEOnRight(int[] arr) {
        int ans[] = new int[arr.length];
        Stack < Integer > stack = new Stack < > ();
        for (int i = 0; i < arr.length; i++) {
            while (stack.size() > 0 && arr[i] < arr[stack.peek()]) {
                ans[stack.pop()] = i;
            }
            stack.push(i);
        }
        while (stack.size() > 0) {
            ans[stack.pop()] = arr.length;
        }
        return ans;
    }

}