#ifndef _myAvlTree_
#define _myAvlTree_
#include<iostream>
using namespace std;

template <class T>
class AvlTreeNode
{
public:
	AvlTreeNode<T> *left;
	AvlTreeNode<T> *right;
	AvlTreeNode<T> *parent;
	int balanceFactor;
	T date;
	AvlTreeNode(const T& item, AvlTreeNode<T>* lptr = NULL, AvlTreeNode<T>* rptr = NULL, AvlTreeNode<T>* pr = NULL, int balfac = 0) :date(item), left(lptr), right(rptr), parent(pr), balanceFactor(balfac)
	{}
};

template <class T>
class AvlTree
{
public:
	AvlTreeNode<T>* root;
	AvlTreeNode<T>* current;
	int size;
	AvlTree<T>();
	~AvlTree<T>();
	bool insert(T);
	bool RotateSubTree(AvlTreeNode<T>*);
	AvlTreeNode<T>* LL(AvlTreeNode<T>*);
	AvlTreeNode<T>* LR(AvlTreeNode<T>*);
	AvlTreeNode<T>* RR(AvlTreeNode<T>*);
	AvlTreeNode<T>* RL(AvlTreeNode<T>*);
	void buildParent(AvlTreeNode<T>*);
	void Destory(AvlTreeNode<T>*);
	AvlTreeNode<T>* Search(T);
	AvlTreeNode<T>* getRoot();
	bool Delete(T);
	void show(AvlTreeNode<T>*);
	AvlTreeNode<T>* mostLeft();
	AvlTreeNode<T>* mostRight();
};

template <class T>
AvlTree<T>::AvlTree()
{
	root = current = NULL;
	size = 0;
}

template <class T>
AvlTreeNode<T>* AvlTree<T>::getRoot()
{
	return root;
}

template <class T>
bool AvlTree<T>::insert(T item)
{
	AvlTreeNode<T>* pre = root;
	AvlTreeNode<T>* tempPosition = root;
	while (1)
	{
		if (tempPosition == NULL)
		{
			AvlTreeNode<T>* newNode = new AvlTreeNode<T>(item);
			if (pre == NULL)
			{
				root = newNode;
				size++;
				return 1;
			}
			else if (item<pre->date)
			{
				pre->left = newNode;
				tempPosition = newNode;
				newNode->parent = pre;
				size++;
				break;
			}
			else if (item>pre->date)
			{
				pre->right = newNode;
				tempPosition = newNode;
				newNode->parent = pre;
				size++;
				break;
			}
		}
		else if (item<tempPosition->date)
		{
			pre = tempPosition;
			tempPosition = tempPosition->left;
		}
		else if (item>tempPosition->date)
		{
			pre = tempPosition;
			tempPosition = tempPosition->right;
		}
		else
		{
			return 0;
		}
	}
	int bf = 0;
	while (pre)
	{
		if (pre->left == tempPosition) bf = 1;
		else if (pre->right == tempPosition) bf = -1;
		tempPosition = pre;
		pre = pre->parent;
		tempPosition->balanceFactor += bf;
		if (bf == 0) return 1;
		else if (bf == 2 || bf == -2)
		{
			RotateSubTree(tempPosition);
			buildParent(root);
			root->parent = NULL;
		}
	}
	return 1;
}

template <class T>
bool AvlTree<T>::RotateSubTree(AvlTreeNode<T>* tree)
{
	bool flag = 1;
	current = tree;
	int bf = current->balanceFactor;
	AvlTreeNode<T>* newRoot = NULL;
	if (bf == 2)
	{
		int lbf = current->left->balanceFactor;
		if (lbf == -1) newRoot = LR(tree);
		else if (lbf == 1) newRoot = LL(tree);
		else
		{
			newRoot = LL(tree);
			flag = 0;
		}
	}
	else if (bf == -2)
	{
		int rbf = current->right->balanceFactor;
		if (rbf == -1) newRoot = RR(tree);
		else if (rbf == 1) newRoot = RL(tree);
		else
		{
			newRoot = RR(tree);
			flag = 0;
		}
	}
	if (current->parent != NULL)
	{
		if (current->date<(current->parent->date))
		{
			current->parent->left = newRoot;
		}
		else if (current->date>(current->parent->date))
		{
			current->parent->right = newRoot;
		}
	}
	else
	{
		root = newRoot;
	}
	return flag;
}

template <class T>
AvlTreeNode<T>* AvlTree<T>::LL(AvlTreeNode<T>* tree)
{
	AvlTreeNode<T>* nextTree = tree->left;
	tree->left = nextTree->right;
	nextTree->right = tree;
	if (nextTree->balanceFactor == 1)
	{
		nextTree->balanceFactor = 0;
		tree->balanceFactor = 0;
	}
	else
	{
		tree->balanceFactor = 1;
		nextTree->balanceFactor = -1;
	}
	return nextTree;
}

template <class T>
AvlTreeNode<T>* AvlTree<T>::LR(AvlTreeNode<T>* tree)
{
	AvlTreeNode<T>* nextTree = tree->left;
	AvlTreeNode<T>* newRoot = nextTree->right;
	tree->left = newRoot->right;
	nextTree->right = newRoot->left;
	newRoot->left = nextTree;
	newRoot->right = tree;
	switch (newRoot->balanceFactor)
	{
	case 0:
		tree->balanceFactor = 0;
		nextTree->balanceFactor = 0;
		break;
	case 1:
		tree->balanceFactor = -1;
		nextTree->balanceFactor = 0;
		break;
	case -1:
		tree->balanceFactor = 0;
		nextTree->balanceFactor = 1;
		break;
	}
	newRoot->balanceFactor = 0;
	return newRoot;
}

template <class T>
AvlTreeNode<T>* AvlTree<T>::RR(AvlTreeNode<T>* tree)
{
	AvlTreeNode<T>* nextTree = tree->right;
	tree->right = nextTree->left;
	nextTree->left = tree;
	if (nextTree->balanceFactor == -1)
	{
		nextTree->balanceFactor = 0;
		tree->balanceFactor = 0;
	}
	else
	{
		tree->balanceFactor = -1;
		nextTree->balanceFactor = 1;
	}
	return nextTree;
}

template <class T>
AvlTreeNode<T>* AvlTree<T>::RL(AvlTreeNode<T>* tree)
{
	AvlTreeNode<T>* nextTree = tree->right;
	AvlTreeNode<T>* newRoot = nextTree->left;
	tree->right = newRoot->left;
	nextTree->left = newRoot->right;
	newRoot->right = nextTree;
	newRoot->left = tree;
	switch (newRoot->balanceFactor)
	{
	case 0:
		tree->balanceFactor = 0;
		nextTree->balanceFactor = 0;
		break;
	case 1:
		tree->balanceFactor = 0;
		nextTree->balanceFactor = -1;
		break;
	case -1:
		tree->balanceFactor = 1;
		nextTree->balanceFactor = 0;
		break;
	}
	newRoot->balanceFactor = 0;
	return newRoot;
}

template <class T>
void AvlTree<T>::buildParent(AvlTreeNode<T>* tree)
{
	if (tree == NULL) return;
	if (tree->left != NULL)
	{
		tree->left->parent = tree;
	}
	if (tree->right != NULL)
	{
		tree->right->parent = tree;
	}
	buildParent(tree->left);
	buildParent(tree->right);
}

template <class T>
AvlTreeNode<T>* AvlTree<T>::Search(T item)
{
	current = root;
	while (1)
	{
		if (current == NULL) return NULL;
		else if (item == current->date) return current;
		else if (item<current->date) current = current->left;
		else if (item>current->date) current = current->right;
	}
}

template <class T>
AvlTreeNode<T>* AvlTree<T>::mostLeft()
{
	AvlTreeNode<T>* tempPosition = root;
	if (tempPosition == NULL) return NULL;
	while (tempPosition->left != NULL)
		tempPosition = tempPosition->left;
	return tempPosition;
}

template <class T>
AvlTreeNode<T>* AvlTree<T>::mostRight()
{
	AvlTreeNode<T>* tempPosition = root;
	if (tempPosition == NULL) return NULL;
	while (tempPosition->right != NULL) tempPosition = tempPosition->right;
	return tempPosition;
}

template <class T>
bool AvlTree<T>::Delete(T item)
{
	AvlTreeNode<T>* deleteNode = Search(item);
	if (deleteNode == NULL) return 0;
	AvlTreeNode<T>* tempPosition = NULL;
	AvlTreeNode<T>* pre = tempPosition;
	AvlTreeNode<T>* tureDeleteNode;
	if (deleteNode->left != NULL&&deleteNode->right != NULL)
	{
		tempPosition = deleteNode->left;
		while (tempPosition->right != NULL)
		{
			tempPosition = tempPosition->right;
		}
		deleteNode->date = tempPosition->date;
		if (tempPosition->parent == deleteNode)
		{
			tempPosition->parent->left = tempPosition->left;
		}
		else
		{
			tempPosition->parent->right = tempPosition->left;
		}
		tureDeleteNode = tempPosition;
	}
	else
	{
		pre = deleteNode->parent;
		tempPosition = deleteNode->left;
		if (tempPosition == NULL) tempPosition = deleteNode->right;
		if (deleteNode != root)
		{
			if (deleteNode->parent->left == deleteNode)
			{
				deleteNode->parent->left = tempPosition;
			}
			else
			{
				deleteNode->parent->right = tempPosition;
			}
		}
		else
		{
			root = tempPosition;
		}
		tureDeleteNode = deleteNode;
	}
	if (tureDeleteNode == NULL) pre = NULL;
	else
	{
		pre = tureDeleteNode->parent;
	}
	while (pre)
	{
		int bf = 0;
		if (tureDeleteNode->date<pre->date) bf = -1;
		else bf = 1;
		pre->balanceFactor += bf;
		tempPosition = pre;
		pre = pre->parent;
		bf = tempPosition->balanceFactor;
		if (bf != 0)
		{
			if (bf == 1 || bf == -1 || !RotateSubTree(tempPosition))
			{
				break;
			}
		}
	}
	buildParent(root);
	if (root != NULL) root->parent = NULL;
	delete tureDeleteNode;
	size--;
	return 1;
}

template <class T>
void AvlTree<T>::Destory(AvlTreeNode<T>* tree)
{
	if (tree == NULL)
		return;
	if (tree->left != NULL || tree->right != NULL)
	{
		if (tree->left != NULL)
		{
			Destory(tree->left);
			tree->left = NULL;
		}
		if (tree->right != NULL)
		{
			Destory(tree->right);
			tree->right = NULL;
		}
	}
	delete tree;
}

template <class T>
void AvlTree<T>::show(AvlTreeNode<T>* tree)
{
	if (tree == NULL) return;
	show(tree->left);
	cout << tree->date << " ";
	show(tree->right);
}

template <class T>
AvlTree<T>::~AvlTree()
{
	Destory(root);
}

#endif