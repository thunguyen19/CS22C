/**
 * ThuMinh Nguyen
 * CIS 22C
 * BinarySearchTree.h
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <cstddef>
#include <assert.h>
#include <iostream>

using namespace std;

template<class bstitem>
class BinarySearchTree {
private:
	struct Node {
		bstitem data;
		Node* left;
		Node* right;
		Node();
		Node(bstitem newdata) :
				data(newdata), left(NULL), right(NULL) {
		}
	};

	typedef struct Node* NodePtr;
	NodePtr root;

	/**Private helper functions*/

	void insertHelper(NodePtr root, bstitem value);
	//private helper function for insert
	//recursively inserts a value into the BST

	bool findHelper(NodePtr root, bstitem value);

	bstitem minimumHelper(NodePtr root);

	bstitem maximumHelper(NodePtr root);

	int getHeightHelper(NodePtr root);

	int getSizeHelper(NodePtr root);

	void destructorHelper(NodePtr node);

	NodePtr copyHelper(NodePtr original);

	NodePtr removeHelper(NodePtr root, bstitem value);

	void inOrderPrintHelper(NodePtr root);
	//private helper function for inOrderPrint
	//recursively prints tree values in order from smallest to largest

	void preOrderPrintHelper(NodePtr root);
	//private helper function for preOrderPrint
	//recursively prints tree values in preorder

	void postOrderPrintHelper(NodePtr root);
	//private helper function for postOrderPrint
	//recursively prints tree values in postorder

	/**Public functions*/

public:
	BinarySearchTree();
	//Instantiates a new Binary Search Tree
	//post: a new Binary Search Tree object

	~BinarySearchTree();

	BinarySearchTree(const BinarySearchTree &BST);

	bool isEmpty();
	//determines whether the Binary Search Tree is empty

	void insert(bstitem value);
	//inserts a new value into the Binary Search Tree
	//post: a new value inserted into the Binary Search Tree

	bool find(bstitem value);

	bstitem minimum();

	bstitem maximum();

	int getHeight();

	int getSize();

	bstitem getRoot();
	//returns the value stored at the root of the Binary Search Tree
	//pre: the Binary Search Tree is not empty

	void remove(bstitem value);

	void inOrderPrint();
	//calls the inOrderPrintHelper function to print out the values
	//stored in the Binary Search Tree
	//If the tree is empty, prints nothing

	void preOrderPrint();
	//calls the preOrderPrintHelper function to print out the values
	//stored in the Binary Search Tree
	//If the tree is empty, prints nothing

	void postOrderPrint();
	//calls the postOrderPrintHelper function to print out the values
	//stored in the Binary Search Tree
	//If the tree is empty, prints nothing
};

#endif /* BINARYSEARCHTREE_H_ */

template<class bstitem>
BinarySearchTree<bstitem>::BinarySearchTree() :
		root(NULL) {
}

template<class bstitem>
BinarySearchTree<bstitem>::~BinarySearchTree() {
	if (root == NULL) {
		return;
	} else {
		destructorHelper(root);
		root = NULL;
	}
}

template<class bstitem>
void BinarySearchTree<bstitem>::destructorHelper(NodePtr node) {
	if (node != NULL) {
		destructorHelper(node->left);
		destructorHelper(node->right);
		delete node;
	}
}

template<class bstitem>
BinarySearchTree<bstitem>::BinarySearchTree(const BinarySearchTree &BST) {
	if (BST.root == NULL) {
		root = NULL;
	} else
		root = copyHelper(BST.root);
}

template<class bstitem>
typename BinarySearchTree<bstitem>::NodePtr BinarySearchTree<bstitem>::copyHelper(NodePtr original) {
	if (original != NULL) {
		NodePtr copy = new Node(original->data);
		copy->left = copyHelper(original->left);
		copy->right = copyHelper(original->right);
		return copy;
	}
}

template<class bstitem>
bool BinarySearchTree<bstitem>::isEmpty() {
	return (root == NULL);
}

template<class bstitem>
void BinarySearchTree<bstitem>::insert(bstitem value) {
	if (root == NULL) {
		root = new Node(value); //if the tree is empty insert the value at the root
	} else {
		insertHelper(root, value); //otherwise call the helper function, passing it the root
	}
}

template<class bstitem>
void BinarySearchTree<bstitem>::insertHelper(NodePtr root, bstitem value) {
	//base case
	if (value == root->data) {
		return;
	} else if (value < root->data) {
		if (root->left == NULL) {
			root->left = new Node(value);
		} else
			insertHelper(root->left, value);
	} else {
		if (root->right == NULL) {
			root->right = new Node(value);
		} else
			insertHelper(root->right, value);
	}
}

template<class bstitem>
bool BinarySearchTree<bstitem>::find(bstitem value) {
	assert(!isEmpty());
	if (value == root->data)
		return true;
	else
		return findHelper(root, value);
}

template<class bstitem>
bool BinarySearchTree<bstitem>::findHelper(NodePtr root, bstitem value) {
	if (value == root->data){
		return true;
	}
	else if (value < root->data){
		if (root->left == NULL)
			return false;
		else
			return findHelper(root->left, value);
	}
	else{
		if (root->right == NULL)
			return false;
		else
			return findHelper(root->right, value);
	}
	return false;
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::minimum() {
	assert(!isEmpty());
	return minimumHelper(root);
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::minimumHelper(NodePtr root) {
	if (root->left == NULL)
		return root->data;
	else
		return minimumHelper(root->left);
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::maximum() {
	assert(!isEmpty());
	return maximumHelper(root);
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::maximumHelper(NodePtr root) {
	if (root->right == NULL){
		return root->data;
	}
	else
		return maximumHelper(root->right);
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::getRoot() {
	assert(!isEmpty());
	return root->data;
}

template<class bstitem>
int BinarySearchTree<bstitem>::getHeight() {
	assert(!isEmpty());
	return getHeightHelper(root);

}

template<class bstitem>
int BinarySearchTree<bstitem>::getHeightHelper(NodePtr root) {
	//base case
	if (root == NULL) {
		return -1;
	}
	int heightLeft = getHeightHelper(root->left);
	int heightRight = getHeightHelper(root->right);
	if (heightLeft > heightRight)
		return (heightLeft + 1);
	else
		return (heightRight + 1);
}

template<class bstitem>
int BinarySearchTree<bstitem>::getSize() {
	return getSizeHelper(root);
}

template<class bstitem>
int BinarySearchTree<bstitem>::getSizeHelper(NodePtr root) {
	//base case
	if (root == NULL)
		return 0;
	else
		return (1 + getSizeHelper(root->left) + getSizeHelper(root->right));
}

template<class bstitem>
void BinarySearchTree<bstitem>::remove(bstitem value) {
	assert(!isEmpty()); //check if test is empty
	assert(find(value)); //check if value is in the BST
	root = removeHelper(root, value);
}

template<class bstitem>
typename BinarySearchTree<bstitem>::NodePtr BinarySearchTree<bstitem>::removeHelper(
		NodePtr root, bstitem value) {
	if (root == NULL) {
		return root;
	}
	if (value < root->data) {
		root->left = removeHelper(root->left, value);
	} else if (value > root->data) {
		root->right = removeHelper(root->right, value);
	} else {
		//if root is a leaf node
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		}
		//if root node has left child but no right child
		else if (root->left != NULL && root->right == NULL) {
			NodePtr temp = root;
			root = root->left;
			delete temp;
		}
		//if root has right child but no left child
		else if (root->right != NULL && root->left == NULL) {
			NodePtr temp = root;
			root = root->right;
			delete temp;
		}
		//root has 2 children
		else {
			bstitem min = minimumHelper(root->right);
			root->data = min;
			root->right = removeHelper(root->right, min);
		}
	}
	return root;
}

template<class bstitem>
void BinarySearchTree<bstitem>::inOrderPrint() {
	if (root == NULL) {
		cout << "Empty tree.\n";
	} else
		inOrderPrintHelper(root);
	cout << "\n";
}

template<class bstitem>
void BinarySearchTree<bstitem>::inOrderPrintHelper(NodePtr root) {
	if (root != NULL) {
		inOrderPrintHelper(root->left);
		cout << root->data << " ";
		inOrderPrintHelper(root->right);
	}
}

template<class bstitem>
void BinarySearchTree<bstitem>::preOrderPrint() {
	if (root == NULL) {
		cout << "Empty tree.\n";
	} else
		preOrderPrintHelper(root);
	cout << "\n";
}

template<class bstitem>
void BinarySearchTree<bstitem>::preOrderPrintHelper(NodePtr root) {
	if (root != NULL) {
		cout << root->data << " ";
		preOrderPrintHelper(root->left);
		preOrderPrintHelper(root->right);
	}
}

template<class bstitem>
void BinarySearchTree<bstitem>::postOrderPrint() {
	if (root == NULL) {
		cout << "Empty tree.\n";
	} else {
		postOrderPrintHelper(root);
		cout << "\n";
	}
}

template<class bstitem>
void BinarySearchTree<bstitem>::postOrderPrintHelper(NodePtr root) {
	if (root != NULL) {
		postOrderPrintHelper(root->left);
		postOrderPrintHelper(root->right);
		cout << root->data << " ";
	}
}
