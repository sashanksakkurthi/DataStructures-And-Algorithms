#include <bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node* left;
	Node* right;
	Node(int d){
		this->data = d;
		this->left = NULL;
		this->right = NULL; 
	}
};

class BST{
private:
	Node* root = NULL;
public:

	Node* insert(Node* root,int data){
		Node* newNode = new Node(data);
		if(root == NULL){
			root = newNode;
			return root;
		}
		if(root->data > data){
			root->left = insert(root->left,data);
		}
		if(root->data < data){
			root->right = insert(root->right,data);
		}
		return root;
	}
	
	Node* inorder(Node* root){
		if (root == NULL)
        {
            return root;
        }
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
        return root;
	};

	Node* preorder(Node* root){
		if (root == NULL)
        {
            return root;
        }
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
        return root;
	};

	Node* postorder(Node* root){
		if (root == NULL)
        {
            return root;
        }
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
        return root;
	};

	void insert(int data){
		root = insert(root,data);
	}

	void inorder(){
		inorder(root);
	}

	void postorder(){
		postorder(root);
	}

	void preorder(){
		preorder(root);
	}
	
};

int main(){
	BST* tree = new BST();

	tree->insert(25);
	tree->insert(15);
	tree->insert(50);

	tree->inorder();
	cout << "\n" << endl;
	tree->preorder();
	cout << "\n" << endl;
	tree->postorder();
}
