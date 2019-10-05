//Linked list implementation in JavaScript.

class node{
	
	constructor(x){
		this.data=x;
		this.next=null;
	}
}

class linked_list{

	constructor(){
		this.head=null;
	}

	insert_node(x){
		var newnode=new node(x);
		if(this.head==null){this.head=newnode;}
		else{
			var temp=this.head;
			while(temp.next!=null){
				temp=temp.next;
			}
			temp.next=newnode;
		}
	}

	traverse(){
		var temp=this.head;
		var linklist;
		while(temp!=null){
			linklist=temp.data+"->";
			temp=temp.next;
		}
		console.log(linklist);
		console.log("NULL");
	}
}