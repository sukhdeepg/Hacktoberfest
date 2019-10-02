#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    Node *next;
};

bool Isempty(Node *head){
  if(head==nullptr)
    return true;
  return false;
}
Node* insert(Node *head, int x){
  Node *temp = new Node();
  temp->val = x;
  temp->next = nullptr;
  if(head==nullptr)
    head = temp;
  else{
    Node *cat = head;
    while(cat->next!=nullptr){
      cat = cat->next;
    }
    cat->next = temp;
  }
  temp->next = head;
  return head;
}

int main(){
Node *head = nullptr;
  return 0;
}
