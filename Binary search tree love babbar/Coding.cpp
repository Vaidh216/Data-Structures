// Coding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BST {

public:
	int data;
	BST* left;
	BST* right;

	BST() {
		data = 0;
		left = NULL;
		right = NULL;
	}

	BST* newNode(int data) {
		BST* newNode = new BST();
		newNode->data = data;
		return newNode;
	}

	BST* insert(BST* root,int data) {
		if (root == NULL) {
			root = newNode(data);
			return root;
		}
		else if (data <= root->data) {
			root->left = insert(root->left, data);
			return root;
		}
		else {
			root->right = insert(root->right, data);
			return root;
		}
		cout << "The node is inserted : " << endl;
	}

	void TraversalInroder(BST* root) {
		if (root == NULL)
			return;

		TraversalInroder(root->left);
		cout << root->data << " ";
		TraversalInroder(root->right);
	}

	void TraversalPreorder(BST* root) {
		if (root == NULL)
			return;

		cout << root->data << " ";
		TraversalPreorder(root->left);
		TraversalPreorder(root->right);
	}

	void TraversalPostorder(BST* root) {
		if (root == NULL)
			return;

		TraversalPostorder(root->left);
		TraversalPostorder(root->right);
		cout << root->data << " ";
	}
	BST* max(BST* root) {
		if (root->right == NULL)
			return root;
		return max(root->right);
	}

	BST* min(BST* root) {
		if (root->left == NULL)
			return root;
		return min(root->left);
	}

	BST* inorderpredecessor(BST* root) {
		return max(root->left);
	}
	BST* inorderSuccerssor(BST* root) {
		return min(root->right);
	}

	BST* searchNode(BST* root, int data) {
		if (root == NULL) {
			cout << "The given value is not found : " << endl;
			return NULL;
		}
		else if (root->data == data) {
			return root;
		}
		else if (data < root->data) {
			return searchNode(root->left, data);
		}
		else {
			return searchNode(root->right, data);
		}
	}


	BST* Delete(BST* root, int data) {
		
		if (data < root->data) {
			root->left = Delete(root->left, data);
			return root;
		}
		else if (data > root->data) {
			root->right = Delete(root->right, data);
			return root;
		}
		else {
			if (root->left == NULL && root->right == NULL) {
				//delete(root);
				return NULL;
			}
			else if (root->left == NULL) {
				root = root->right;
				return root;
			}
			else if (root->right == NULL) {
				root = root->left;
				return root;
			}
			else {
				BST* temp = min(root->right);
				root->data = temp->data;
				root->right = Delete(root->right, temp->data);
				return root;
			}
		}
		
		/*temp = searchNode(root, data);

		if (temp->left == NULL && temp->right == NULL) {
			//delete(temp);
			temp = NULL;
			return root;
		}
		else if (temp->left == NULL) {
			temp = temp->right;
			delete(temp);
			return root;
		}
		else if (temp->right == NULL) {
			temp = temp->left;
			delete(temp);
			return root;
		}
		else {
			BST* t;
			t = min(temp->right);
			temp->data = t->data;
			Delete(temp, t->data);
			return root;
		}
		*/
	}

	int height(BST* root) {
		if (root == NULL)
			return -1;
		else if (height(root->left) > height(root->right)) {
			return height(root->left) + 1;
		}
		else {
			return height(root->right) + 1;
		}
	}

	void levelorder(BST* root, int h) {
		if (root == NULL) {
			return;
		}
		else if(h == 0) {
			cout << root->data;
		}
		else {
			levelorder(root->left, h - 1);
			levelorder(root->right, h - 1);
		}
	}

	void printlevelorderiterative(BST* root) {
		int h = height(root);
		for (int i = 0; i <= h; i++) {
			levelorder(root, i);
		}
	  }
};

int main()
{
	BST* root = new BST();
	root = NULL;
	cout << "Enter the number of values you want to inert : ";
	int value;
	cin >> value;
	cout << endl << "Now enter " << value << " value : " << endl;
	for (int i = 0; i < value; i++) {
		int data;
		cin >> data;
		root = root->insert(root, data);

	}
	cout << "Now Printing data : " << endl;
	cout << "Printing Preorder : " << endl;
	root->TraversalPreorder(root);
	cout << endl << "Printing Inorder : " << endl;
	root->TraversalInroder(root);
	cout << endl << "Printing Postorder : " << endl;
	root->TraversalPostorder(root);
	cout << endl << "Printing levelorder : " << endl;
	root->printlevelorderiterative(root);

	cout << "The height of the tree is : " << root->height(root) << endl;
	//cout << endl << "The maximumvalue is : " << root->max(root)->data << endl;
	/*
	do {
		cout << "Enter the data you want to delete " << endl;
		cin >> value;
		root->Delete(root, value);

		cout << "Now Printing data : " << endl;
		cout << "Printing Preorder : " << endl;
		root->TraversalPreorder(root);
		cout << endl << "Printing Inorder : " << endl;
		root->TraversalInroder(root);
		cout << endl << "Printing Postorder : " << endl;
		root->TraversalPostorder(root);
	} while (value != 0);
	*/
	return 0;
}