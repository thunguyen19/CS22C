#include "BinarySearchTree.h"
#include <cstddef>
#include <assert.h>

using namespace std;

/*Constructors & Destructors*/

BinarySearchTree y, a, c;
int most = 0;
int mostcon = 0;
string au;
string con;
//BST Constructor
BinarySearchTree::BinarySearchTree() :
		root(NULL) {
}

//BST Destructor
BinarySearchTree::~BinarySearchTree() {
	DestructorHelper(root);
}

/**Private helper functions*/

//BST private helper function for Destructor
void BinarySearchTree::DestructorHelper(NodePtr root) {
	//destroy bst during a postorder traversal
	if (root != NULL) {
		DestructorHelper(root->left);
		DestructorHelper(root->right);
		delete root;
	}
}

//BST private helper function for insert()
void BinarySearchTree::insertHelper(NodePtr root, Haiku h) {
	if (h.get_title() == root->data.get_title())
		//return if value is a duplicate
		return;
	//insert in left subtree
	else if (h.get_title() < root->data.get_title()) {
		if (root->left == NULL)
			root->left = new Node(h);
		else
			insertHelper(root->left, h);
	}
	//insert in right subtree
	else {
		if (root->right == NULL)
			root->right = new Node(h);
		else
			insertHelper(root->right, h);
	}
}

void BinarySearchTree::insertHelper_year(NodePtr root, Haiku h) {
	if (h.get_year() == root->data.get_year()) {
		return;
	} else if (h.get_year() < root->data.get_year()) {
		if (root->left == NULL)
			root->left = new Node(h);
		else
			insertHelper_year(root->left, h);
	}

	else {
		if (root->right == NULL)
			root->right = new Node(h);
		else
			insertHelper_year(root->right, h);
	}
}

void BinarySearchTree::insert_year(Haiku h) {
	if (root == NULL) {
		root = new Node(h);
	} else {
		insertHelper_year(root, h);
	}
}

void BinarySearchTree::insertHelper_author(NodePtr root, Haiku h) {
	if (h.get_author() == root->data.get_author())
	//return if value is a duplicate
			{
		most++;
		return;
	}
	//insert in left subtree
	else if (h.get_author() < root->data.get_author()) {
		if (root->left == NULL)
			root->left = new Node(h);
		else
			insertHelper_author(root->left, h);
	}
	//insert in right subtree
	else {
		if (root->right == NULL)
			root->right = new Node(h);
		else
			insertHelper_author(root->right, h);
	}
}

void BinarySearchTree::insert_author(Haiku h) {
	if (root == NULL) {
		root = new Node(h);
	} else {
		insertHelper_author(root, h);
	}
}

//BST private helper function for find()
bool BinarySearchTree::findHelper(NodePtr root, Haiku h) {
	if (h.get_title() == root->data.get_title())
		return true;
	else if (h.get_title() < root->data.get_title()) {
		if (root->left == NULL)
			return false;
		else
			return findHelper(root->left, h);
	} else {
		if (root->right == NULL)
			return false;
		else
			return findHelper(root->right, h);
	}
}

//BST private helper function for minimum()
Haiku BinarySearchTree::minimumHelper(NodePtr root) {
	if (root->left == NULL)
		return root->data;
	else
		return minimumHelper(root->left);
}

//BST private helper function for getSize()
int BinarySearchTree::getSizeHelper(NodePtr root) {
	if (root == NULL)
		return 0;
	else
		return 1 + (getSizeHelper(root->left) + getSizeHelper(root->right));
}

//BST private helper function for remove()
typename BinarySearchTree::NodePtr BinarySearchTree::removeHelper(NodePtr root,
		Haiku h) {
	if (root == NULL) {
		return root;
	} else if (h.get_title() < root->data.get_title()) {
		root->left = removeHelper(root->left, h);
	} else if (h.get_title() > root->data.get_title()) {
		root->right = removeHelper(root->right, h);
	} else {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			root = NULL;
		} else if (root->right == NULL) {
			NodePtr temp = root;
			root = root->left;
			delete temp;
		} else if (root->left == NULL) {
			NodePtr temp = root;
			root = root->right;
			delete temp;
		} else {
			Haiku minimumRightValue = minimumHelper(root->right);
			root->data = minimumRightValue;
			root->right = removeHelper(root->right, minimumRightValue);
		}
	}
	return root;
}

/**Public access functions*/

//BST public isEmpty() function
bool BinarySearchTree::isEmpty() {
	return (root == NULL);
}

//BST public getRoot() function
Haiku BinarySearchTree::getRoot() {
	assert(root != NULL);
	return root->data;
}

//BST public find() function
bool BinarySearchTree::find(Haiku h) {
	assert(root != NULL);

	if (h.get_title() == getRoot().get_title())
		return true;
	else
		return findHelper(root, h);
}

//BST public minimum() function
Haiku BinarySearchTree::minimum() {
	assert(root != NULL);
	return minimumHelper(root);
}

//BST public access getSize() function
int BinarySearchTree::getSize() {
	return getSizeHelper(root);
}

/**Public manipulation functions*/

//BST public insert() function
void BinarySearchTree::insert(Haiku h) {
	y.insert_year(h);
	a.insert_author(h);
	c.insert_country(h);
	if (root == NULL) {
		root = new Node(h);
	} else {
		insertHelper(root, h);
	}

}
void BinarySearchTree::insertHelper_country(NodePtr root, Haiku h) {
	if (h.get_country() == root->data.get_country())
	//return if value is a duplicate
			{
		mostcon++;
		return;
	}
	//insert in left subtree
	else if (h.get_country() < root->data.get_country()) {
		if (root->left == NULL)
			root->left = new Node(h);
		else
			insertHelper_country(root->left, h);
	}
	//insert in right subtree
	else {
		if (root->right == NULL)
			root->right = new Node(h);
		else
			insertHelper_country(root->right, h);
	}
}

void BinarySearchTree::insert_country(Haiku h) {
	if (root == NULL) {
		root = new Node(h);
	} else {
		insertHelper_country(root, h);
	}
}
void BinarySearchTree::remove(Haiku h) {
	assert(root != NULL);
	root = removeHelper(root, h);
	  y.removeHelper(root, h);
	    a.removeHelper(root, h);
	    c.removeHelper(root, h);
}

/**Additional functions*/

//BST public inOrderPrint() function
void BinarySearchTree::inOrderPrint(ostream &strm) {
	inOrderPrintHelper(root, strm, 1);
}

//BST private helper function for inOrderPrint()
void BinarySearchTree::inOrderPrintHelper(NodePtr root, ostream &strm,
		int counter) {
	if (counter == 0) {
		return;
	} else {
		if (root != NULL) {
			inOrderPrintHelper(root->left, strm, counter);
			strm << counter++ << "." << root->data.get_title() << endl;
			strm << "   " << "by " << root->data.get_author() << endl;
			strm << endl;
			inOrderPrintHelper(root->right, strm, counter);
		}
	}
}
Haiku BinarySearchTree::maximum()
//finds the minimum value in the Binary Search Tree and returns it

{
	assert(!isEmpty());
	return maximumHelper(root);

}
Haiku BinarySearchTree::maximumHelper(NodePtr root) {
	while (root->right != NULL) {
		root = root->right;
	}
	return root->data;
}

void BinarySearchTree::statistic() {
	cout << "There are " << getSize() << " haiku in the table" << endl;
	cout << "The oldest haiku is from: " << y.minimum().get_year() << endl;
	cout << "Title: " << y.minimum().get_title() << endl;
	cout << "By: " << y.minimum().get_author() << endl;
	cout << "The newest haiku is from: " << y.maximum().get_year() << endl;
	cout << "Title: " << y.maximum().get_title() << endl;
	cout << "By: " << y.maximum().get_author() << endl;
}
