#ifndef BST_H
#define BST_H

#include <iostream>
using namespace std;

struct BSTNode {
	int data;
	BSTNode *left;
	BSTNode *right;

	BSTNode (): left(NULL), right(NULL) {}
	BSTNode(int d): data(d), left(NULL), right(NULL) {}
};

class BST
{
public:
	BST() {
		root = NULL;
		size = 0;
	}
	~BST(){}
	
	void insert(int data) {
		insert(data, &root);
	}

	bool search(int data) {
		return search(data, root);
	}

	bool remove(int data) {
		return remove(data, &root);
	}

	void inorder_print() {
		cout << "inorder:  " << endl;
		inorder_print(root);
		cout << endl;
	}

	void preorder_print() {
		cout << "preorder: " << endl;
		preorder_print(root);
		cout << endl;
	}

private:
	void insert(int data, BSTNode ** root) {
		if(*root == NULL) {
			*root = new BSTNode(data);
		} else {
			if(data < (*root)->data) {
				insert(data, &((*root)->left));
			} else {
				insert(data, &((*root)->right));
			}
		}
	}

	bool search(const int target, BSTNode * root) {
		if(!root) return false;
		if(target == root->data) return true;
		if(target < root->data){
			return search(target, root->left);
		} else {
			return search(target, root->right);
		}
	}

	bool remove(const int target, BSTNode ** root_ptr) {
		BSTNode * root = *root_ptr;
		if(root == NULL) return false;

		int val = root->data;
		if(target < val) {
			return remove(target, &(root->left));
		} else if (target > val) {
			return remove(target, &(root->right));
		} else {
			if(root->right) {
				BSTNode ** tmp_ptr = &(root->right);
				while((*tmp_ptr)->left) {
					tmp_ptr = &((*tmp_ptr)->left);
				}
				BSTNode *tmpnode = *tmp_ptr;

				if(tmpnode != root->right) {
					root->data = tmpnode->data;
					delete tmpnode;
					*tmp_ptr = NULL; //!! important
				} else {
					tmpnode->left = root->left;
					delete root;
					*root_ptr = tmpnode;
				}
			} else {
				BSTNode *left = root->left;
				delete *root_ptr;
				*root_ptr = left;
			}

			return true;
		}
	}

	void inorder_print(BSTNode * root) {
		if (!root) return;
		inorder_print(root->left);
		cout << root->data << " ";
		inorder_print(root->right);
	}

	void preorder_print(BSTNode * root) {
		if (!root) return;
		cout << root->data << " ";
		preorder_print(root->left);
		preorder_print(root->right);
	}

private:
	BSTNode *root;
	int size;
};

#endif