import java.util.*;

/*
* Author : Abhishek Kansal
* Date   : '01/10/2019'
*
* Editor   : VSCode
* Compiler : javac 1.8.0_222
*
* NOTE : 'Used another stack for maintaining minimum elements'
*
* Time : O('')
* Space : O('')
*/

class MinStackImplementation {
    public static void main(String[] args) {
      
    }
}

class MinStack {
    
    Stack<Integer> data;
    Stack<Integer> minData; // To store current min for each stack state

    /** initialize your data structure here. */
    public MinStack() {
        data = new Stack<>();
        minData = new Stack<>();
    }
    
    public void push(int x) {
        if(data.empty()){
            data.push(x);
            minData.push(x);
            return;
        }
        
        data.push(x);
        
        if(x < minData.peek()){
            minData.push(x);
        } else{
            minData.push(minData.peek());
        }
    }
    
    public void pop() {
        if(data.empty()){
            return;
        }
        
        data.pop();
        minData.pop();
    }
    
    public int top() {
        return data.peek();
    }
    
    public int getMin() {
        return minData.peek();
    }
}

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
