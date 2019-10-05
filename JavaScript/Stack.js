//This code is my favourite because it explains us stack in JavaScript ES6
class Stack {
    constructor() {
        this.count = 0;
        this.storage = {};
    }
    push(value) {
        this.storage[this.count] = value;
        this.count++;
    }
    pop() {
        if (this.count === 0) {
            return undefined;
        }
        this.count--;
        var result = this.storage[this.count];
        delete this.storage[this.count];
        return result;
    }
    size() {
        return this.count;
    }
    display(){
        var stackSize = this.size();
        for(var i = 0; i < stackSize; i++){
            console.log(`${stack.storage[i]}`);
        }
    }
}

//Driver code:
var stack = new Stack();

//pushing elements
stack.push(3);
stack.push(4);
stack.push(6);
console.log('Before popping: ');
stack.display();

//popping element
stack.pop();
//displaying
console.log('After popping: ');
stack.display();
//size of stack elements
console.log(`Stack size: ${stack.size()}`);

