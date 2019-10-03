// This is my favorite code snippet because it is a balanced BST and i like balanced things
#include <bits/stdc++.h>

using namespace std;

struct Node
{
	int d;
	struct Node* left;
	struct Node* right;
	int bal;
};
typedef struct Node node;

node* newNode(int data)
{
	node* p = new node;
	p->d = data;
	p->left = p->right = NULL;
	p->bal = 0;
	return p;
}

int Height(node* root)
{
	if (root)
	{
		int lHeight = Height(root->left);
		int rHeight = Height(root->right);

		if (lHeight > rHeight)
			return (lHeight + 1);
		else
			return (rHeight + 1);
	}
	else
		return 0;
}

int BalFactor(node* root)
{
	int lHeight = Height(root->left);
	int rHeight = Height(root->right);
	int balfactor = lHeight - rHeight;
	return balfactor;
}

node* rotateLeft(node* root)
{
	node* tempPtr = root->right;
	root->right = tempPtr->left;
	tempPtr->left = root;
	root->bal = BalFactor(root);
	tempPtr->bal = BalFactor(tempPtr);
	return tempPtr;
}

node* rotateRight(node* root)
{
	node* tempPtr = root->left;
	root->left = tempPtr->right;
	tempPtr->right = root;
	tempPtr->bal = BalFactor(tempPtr);
	root->bal = BalFactor(root);
	return tempPtr;
}

node* Insert(node* root, int data)
{
	if (root == NULL)
	{
		root = newNode(data);
	}
	else
	{
		if (data > root->d)
			root->right = Insert(root->right, data);
		else if (data < root->d)
			root->left = Insert(root->left, data);
		else
			cout << "Equal datas are not allowed in AVL trees" << endl;
	}

	root->bal = BalFactor(root);

	if (root->bal > 1 && data < root->left->d)
	{
		root = rotateRight(root);
	}

	if (root->bal < -1 && data > root->right->d)
	{
		root = rotateLeft(root);
	}

	if (root->bal > 1 && data > root->left->d)
	{
		root->left = rotateLeft(root->left);
		root = rotateRight(root);
	}

	if (root->bal < -1 && data < root->right->d)
	{
		root->right = rotateRight(root->right);
		root = rotateLeft(root);
	}

	return root;
}

void Preorder(node* root)
{
	if (root != NULL)
	{
		cout << root->d << " ";
		Preorder(root->left);
		Preorder(root->right);
	}
}

node* Deletenode(node* root, int data)
{
	if (root == NULL)
	{
		return root;
	}
	else
	{
		if (data > root->d)
		{
			root->right = Deletenode(root->right, data);
		}
		else if (data < root->d)
		{
			root->left = Deletenode(root->left, data);
		}
		else
		{
			if (root->left == NULL)
			{
				node*p = root->right;
				delete(root);
				return p;
			}
			if (root->right == NULL)
			{
				node* p = root->left;
				delete(root);
				return p;
			}

			node* p = root->left;

			if (p != NULL && p->right != NULL)
			{
				p = p->right;
			}

			root->d = p->d;
			root->left = Deletenode(root->left, p->d);
		}

		if (root == NULL)
			return root;

		root->bal = BalFactor(root);

		if (root->bal > 1 && BalFactor(root->left) >= 0)
		{
			root = rotateRight(root);
		}

		if (root->bal < -1 && BalFactor(root->right) <= 0)
		{
			root = rotateLeft(root);
		}

		if (root->bal > 1 && BalFactor(root->left) > 0)
		{
			root->left = rotateLeft(root->left);
			root = rotateRight(root);
		}

		if (root->bal < -1 && BalFactor(root->right) < 0)
		{
			root->right = rotateRight(root->right);
			root = rotateLeft(root);
		}
	}
	return root;
}

int main()
{
	node* root = NULL;

	root = Insert(root, 9);
	root = Insert(root, 5);
	root = Insert(root, 10);
	root = Insert(root, 0);
	root = Insert(root, 6);
	root = Insert(root, 11);
	root = Insert(root, -1);
	root = Insert(root, 1);
	root = Insert(root, 2);

	cout << "Before Deletion" << endl;

	Preorder(root);

	root = Deletenode(root, 10);

	cout << endl << "After Deletion" << endl;
	Preorder(root);
	cout << endl;


	return 0;
}
