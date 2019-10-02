import java.util.*;

/*
* Author : Abhishek Kansal
* Date   : 01/10/2019
*
* Editor   : VSCode
* Compiler : javac 1.8.0_222
*
* NOTE : This program checks whether a given string of parentheses is valid or not.
*
* Time : O('n')
* Space : O('n')
*/

class Main {
    public static void main(String[] args) {
        Solution s = new Solution();
        //System.out.println(s.isValid("(())[]{}{][}"));
        System.out.println(s.isValid("(())[]{}"));
    }
}


class Solution {
    public boolean isValid(String s) {
        if(s.length() == 0) {
            return true;
        }
        
        Stack<Character> stack = new Stack<>();
        
        for(int i=0; i<s.length(); i++) {
            char ch = s.charAt(i);
            
            if(ch == '(' || ch == '{' || ch == '[') {
                stack.push(ch);
            } else {
                if(stack.empty()) {
                    return false;
                } else if(ch == ')'){
                    if(stack.peek() == '(') {
                        stack.pop();
                    } else {
                        return false;
                    }
                } else if(ch == '}'){
                    if(stack.peek() == '{') {
                        stack.pop();
                    } else {
                        return false;
                    }
                } else {
                    if(stack.peek() == '[') {
                        stack.pop();
                    } else {
                        return false;
                    }
                }
            }
        }
        
        if(stack.empty()) {
            return true;
        } else {
            return false;
        }
    }
}

