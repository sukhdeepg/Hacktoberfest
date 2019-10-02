#include<bits/stdc++.h>
using namespace std;
struct Node{
  int val;
  Node *left;
  Node *right;
};
Node *root = nullptr;

void insert(int x){
  Node *temp = new Node();
  temp->val = x;
  temp->left = nullptr;
  temp->right = nullptr;
  if(root==nullptr)
    root = temp;
  else{
    Node *parent;
    parent = nullptr;
    Node *cat = root;
    while(cat!=nullptr){
      parent = cat;
      if(x<cat->val)
        cat=cat->left;
      else
        cat=cat->right;
    }
    if(x<parent->val)
      parent->left = temp;
    else
      parent->right = temp;
  }
}
void inOrderReal(Node *temp){
  if(temp!=nullptr){
    inOrderReal(temp->left);
    cout << temp->val << " ";
    inOrderReal(temp->right);
  }
}
void inOrder(){
  inOrderReal(root);
  cout << endl;
}
stack<Node*> s;
Node * addToStack(Node *cat){
  while(cat!=nullptr){
    s.push(cat);
    cat = cat->left;
  }
  return cat;
}
void inOrderStack(){
  Node *current;
  Node* hey;
  current = addToStack(root);
  while(current==nullptr && !s.empty()){
    hey = s.top();
    s.pop();
    cout << hey->val << " ";
    current = addToStack(hey->right);
  }

}

int depth(Node *temp){
  if(temp==nullptr)
    return 0;
  return max(depth(temp->left)+1, depth(temp->right)+1);
}
map<int,vector<int>> m;
void getOrder(Node *temp, int hd){
   if(temp==nullptr)
       return;
   m[hd].push_back(temp->val);
   getOrder(temp->left, hd-1);
   getOrder(temp->right, hd+1);
}
vector<vector<int>> verticalOrderTraversal(){
   int hd = 0;
   getOrder(root, hd);
   vector<vector<int>> ans;
   for(auto it=m.begin(); it!=m.end(); it++){
       ans.push_back(it->second);
   }
   return ans;
 }
int main(){
  std::vector<int> v = {5,10,3,0,12,52,1};
  for(int i=0; i<v.size(); i++)
    insert(v[i]);
  inOrderStack();
  cout << depth(root) << endl;
  return 0;
}
