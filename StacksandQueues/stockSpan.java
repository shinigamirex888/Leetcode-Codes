package Leetcode.StacksandQueues;

import java.io.*;
import java.util.*;

public class stockSpan {
    public static void display(int[] a) {
        StringBuilder sb = new StringBuilder();

        for (int val: a) {
            sb.append(val + "\n");
        }
        System.out.println(sb);
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(br.readLine());
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = Integer.parseInt(br.readLine());
        }

        int[] span = solve(a);
        display(span);
    }

    public static int[] solve(int[] arr) {
        int ans[] = new int[arr.length];
        Stack < Integer > stack = new Stack < > ();
        for (int i = arr.length - 1; i >= 0; i--) {
            while (stack.size() > 0 && arr[i] > arr[stack.peek()]) {
                int si = stack.pop();
                ans[si] = si - i;
            }
            stack.push(i);
        }
        while (stack.size() > 0) {
            int usi = stack.pop();
            ans[usi] = usi + 1;
        }
        return ans;
    }
}

