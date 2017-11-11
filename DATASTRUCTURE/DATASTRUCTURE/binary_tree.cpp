#include<iostream>
#include<queue>
using namespace std;

template <class ElementType>
class Node
{
public:
	ElementType data;
	Node<ElementType>* parent;
	Node<ElementType>* left_child;
	Node<ElementType>* right_child;
	Node(ElementType data, Node<ElementType>* parent, Node<ElementType>* left_child, Node<ElementType>* right_child)
	{
		this->data = data;
		this->parent = parent;
		this->left_child = left_child;
		this->right_child = right_child;
	}
	~Node() {};
};

template<class ElementType>
class BinTree
{
public:
	BinTree()
	{
		root = NULL;
	}
	~BinTree()
	{
		ClearBinTree(root);
	}
	int Depth(Node<ElementType>* e);
	int NodesCount(Node<ElementType>* e);
	ElementType GetNode(Node<ElementType>* e);
	ElementType GetParent(Node<ElementType>* e);
	ElementType GetLeftChild(Node<ElementType>* e);
	ElementType GetRightChild(Node<ElementType>* e);
	Node<ElementType>* Root();
	bool CreateBinTree(ElementType* data_array, int array_length);
	bool IsEmpty();
	bool InsertRoot(ElementType data);
	bool InsertLeftChild(Node<ElementType>* e, ElementType data);
	bool InsertRightChild(Node<ElementType>* e, ElementType data);
	void SetNode(Node<ElementType>* e, ElementType data);
	void PreOrderTraverse(Node<ElementType>* e);
	void InOrderTraverse(Node<ElementType>* e);
	void PostOrderTraverse(Node<ElementType>* e);
	void LevelOrderTraverse(Node<ElementType>* e);
	void ClearBinTree(Node<ElementType>* e);
private:
	Node<ElementType>* root;
};

#if 0
int main()
{
	BinTree<int> bt;
	int a[10];
	for (int i = 0; i < 10; i++)
	{
		a[i] = i;
	}
	bt.CreateBinTree(a, 10);
	cout << "is empty? " << bt.IsEmpty() << endl;
	bt.SetNode(bt.Root(), 10);
	cout << "root: " << bt.GetNode(bt.Root()) << endl;
	cout << "root -> left child: " << bt.GetLeftChild(bt.Root()) << endl;
	cout << "root -> Right child: " << bt.GetRightChild(bt.Root()) << endl;

	cout << endl << endl;
	bt.PreOrderTraverse(bt.Root());
	cout << endl << endl;
	bt.InOrderTraverse(bt.Root());
	cout << endl << endl;
	bt.PostOrderTraverse(bt.Root());
	cout << endl << endl;
	bt.LevelOrderTraverse(bt.Root());
	cout << endl << endl;

	cout << bt.Depth(bt.Root()) << endl;
	cout << bt.NodesCount(bt.Root()) << endl;

	return 0;
}
#endif

template<class ElementType>
void BinTree<ElementType>::PreOrderTraverse(Node<ElementType>* e)
{
	if (e != NULL)
	{
		cout << e->data << endl;
		PreOrderTraverse(e->left_child);
		PreOrderTraverse(e->right_child);
	}
}

template<class ElementType>
void BinTree<ElementType>::InOrderTraverse(Node<ElementType>* e)
{
	if (e != NULL)
	{
		InOrderTraverse(e->left_child);
		cout << e->data << endl;
		InOrderTraverse(e->right_child);
	}
}

template<class ElementType>
void BinTree<ElementType>::PostOrderTraverse(Node<ElementType>* e)
{
	if (e != NULL)
	{
		PostOrderTraverse(e->left_child);
		PostOrderTraverse(e->right_child);
		cout << e->data << endl;
	}
}

template<class ElementType>
void BinTree<ElementType>::LevelOrderTraverse(Node<ElementType>* e)
{
	queue<Node<ElementType>*> q;
	Node<ElementType>* p = root;
	if (p != NULL)
	{
		q.push(p);
	}
	while (!q.empty())
	{
		cout << (q.front())->data << endl;
		if ((q.front())->left_child != NULL)
		{
			q.push((q.front())->left_child);
		}
		if ((q.front())->right_child != NULL)
		{
			q.push((q.front())->right_child);
		}
		q.pop();
	}
}

template<class ElementType>
void BinTree<ElementType>::ClearBinTree(Node<ElementType>* e)
{
	if (e != NULL)
	{
		if (e->left_child != NULL)
		{
			ClearBinTree(e->left_child);
		}
		if (e->right_child != NULL)
		{
			ClearBinTree(e->right_child);
		}
		delete e;
	}

}

template<class ElementType>
bool BinTree<ElementType>::IsEmpty()
{
	return root == NULL;
}

template<class ElementType>
int BinTree<ElementType>::Depth(Node<ElementType>* e)
{
	if (e == NULL)
	{
		return 0;
	}
	else
	{
		int dep_L = Depth(e->left_child);
		int dep_R = Depth(e->right_child);
		return (dep_L > dep_R) ? dep_L + 1 : dep_R + 1;
	}
}

template<class ElementType>
int BinTree<ElementType>::NodesCount(Node<ElementType>* e)
{
	if (e == NULL)
	{
		return 0;
	}
	else
	{
		int count = 1;
		count += (NodesCount(e->left_child) + NodesCount(e->right_child));
		return count;
	}
}

template<class ElementType>
void BinTree<ElementType>::SetNode(Node<ElementType>* e, ElementType data)
{
	e->data = data;
}

template<class ElementType>
bool BinTree<ElementType>::InsertRoot(ElementType data)
{
	root = new Node<ElementType>(data, NULL, NULL, NULL);
	if (!root)
	{
		return false;
	}
	return true;
}

template<class ElementType>
bool BinTree<ElementType>::InsertLeftChild(Node<ElementType>* e, ElementType data)
{
	if (e->left_child!=NULL)
	{
		cout << "insert left child error: left child existed" << endl;
		return false;
	}
	Node<ElementType>* p = new Node<ElementType>(data, e, NULL, NULL);
	if (!p)
	{
		return false;
	}
	e->left_child = p;
	return true;
}

template<class ElementType>
bool BinTree<ElementType>::InsertRightChild(Node<ElementType>* e, ElementType data)
{
	if (e->right_child != NULL)
	{
		cout << "insert right child error: right child existed" << endl;
		return false;
	}
	Node<ElementType>* p = new Node<ElementType>(data, e, NULL, NULL);
	if (!p)
	{
		return false;
	}
	e->right_child = p;
	return true;
}

template<class ElementType>
ElementType BinTree<ElementType>::GetNode(Node<ElementType>* e)
{
	if (e == NULL)
	{
		cout << "get node error: node doesn't exist" << endl;
		exit(0);
	}
	return e->data;
}

template<class ElementType>
ElementType BinTree<ElementType>::GetParent(Node<ElementType>* e)
{
	if (e==root)
	{
		cout << "get parent error: root has no parent" << endl;
		exit(0);
	}
	return (e->parent)->data;
}

template<class ElementType>
ElementType BinTree<ElementType>::GetLeftChild(Node<ElementType>* e)
{
	if (e->left_child == NULL)
	{
		cout << "get left child error: no left child" << endl;
		exit(0);
	}
	return (e->left_child)->data;
}

template<class ElementType>
ElementType BinTree<ElementType>::GetRightChild(Node<ElementType>* e)
{
	if (e->right_child==NULL)
	{
		cout << "get right child error: no right child" << endl;
		exit(0);
	}
	return (e->right_child)->data;
}

template<class ElementType>
Node<ElementType>* BinTree<ElementType>::Root()
{
	return root;
}

template<class ElementType>
bool BinTree<ElementType>::CreateBinTree(ElementType * data_array, int array_length)
{
	InsertRoot(data_array[0]);
	queue<Node<ElementType>*> q;
	q.push(root);
	for (int i = 1; i < array_length; i++)
	{
		Node<ElementType>* p = q.front();
		InsertLeftChild(p, data_array[i]);
		q.push(p->left_child);
		++i;
		if (i < array_length)
		{
			InsertRightChild(p, data_array[i]);
			q.push(p->right_child);
		}
		q.pop();
	}
}
