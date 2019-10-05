//JavaScript implementation of stack


class Stack{
    constructor(){
        this.arr=[];
        this.top=-1;
        this.size=0;
    }
    push(x){
        this.top+=1;
        this.arr.push(x);
        this.size+=1;
    }
    pop(){
        this.top-=1;
        this.arr.pop();
        this.size-=1;
    }
    isEmpty(){
        return(this===0);
    }
    get_top(){
        return this.arr[this.top];
    }

}
