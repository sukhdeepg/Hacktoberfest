class Queue {
  constructor(dataStore = []) {
    this.dataStore = dataStore;
  }
  push(element) {
    this.dataStore.push(element);
  }
  shift() {
    this.dataStore.shift();
  }
  peekFront() {
    return this.dataStore[0];
  }
  peekBack() {
    return this.dataStore[this.dataStore.length - 1];
  }
  isEmpty() {
    return !this.dataStore.length;
  }
  toString() {
    let str = '';
    for (var i = 0; i < this.dataStore.length; i++) {
      str += `${this.dataStore[i]}\n`;
    }
    return str;
  }
}