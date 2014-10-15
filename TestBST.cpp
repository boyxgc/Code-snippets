
#include "BST.h"

int main(int argc, char const *argv[])
{
	
	BST bst;

	bst.insert(6);
	bst.insert(2);
	bst.insert(10);
	bst.insert(-1);
	bst.insert(4);
	bst.insert(3);
	bst.insert(5);
	bst.insert(11);
	bst.insert(12);

	bst.inorder_print();
	bst.preorder_print();
	cout << endl;
	
	bst.remove(2);
	cout << "= remove 2 :" << endl;
	bst.inorder_print();
	bst.preorder_print();
	cout << endl;

	bst.remove(3);
	cout << "= remove 3 :" << endl;
	bst.inorder_print();
	bst.preorder_print();
	cout << endl;

	bst.remove(4);
	cout << "= remove 4 :" << endl;
	bst.inorder_print();
	bst.preorder_print();
	cout << endl;

	bst.remove(-1);
	cout << "= remove -1 :" << endl;
	bst.inorder_print();
	bst.preorder_print();
	cout << endl;
	
	bst.remove(10);
	cout << "= remove 10 :" << endl;
	bst.inorder_print();
	bst.preorder_print();
	cout << endl;

	bst.remove(14);
	cout << "= remove 14 :" << endl;
	bst.inorder_print();
	bst.preorder_print();
	cout << endl;
	return 0;
}