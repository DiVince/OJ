/*  */
#include<iostream>
using namespace std;

template <class ElementType>
class Node
{
public:
	int i, j;	
	ElementType data;
	Node<ElementType>* next_row;
	Node<ElementType>* next_col;
	Node()
	{
		next_col = NULL;
		next_row = NULL;
	}
};

template <class ElementType>
class OrtList
{
private:
	Node<ElementType> head;
public:
	OrtList(const int & m, const int & n)
	{
		head = Node<ElementType>();
		head.i = m;
		head.j = n;
		head.next_row = new Node<ElementType>[m];
		if (!head.next_row)
		{
			cout << "initial: new error (row)" << '\n';
			exit(0);
		}
		head.next_col = new Node<ElementType>[n];
		if (!head.next_col)
		{
			cout << "initial: new error (col)" << '\n';
			exit(0);
		}
	}
	~OrtList()
	{
		this->ClearList();
	}
	int RowLength(const int & i);
	int ColLength(const int & j);
	bool IsEmpty();
	bool Insert(const int & i, const int & j, const int & v);
	bool RowTraversal();
	bool ColTraversal();
	bool ClearList();
	ElementType GetElement(const int & i, const int & j);
	ElementType GetMatrixElement(const int & i, const int & j);
	void PrintMatrix();
	void APlusAT();
	void AMultiplyAT();


};

#if 0
int main()
{
	OrtList<int> a(3, 3);
	a.PrintMatrix();

	a.Insert(0, 0, 1);
	a.Insert(0, 1, 2);
	a.Insert(1, 1, 2);
	a.Insert(2, 2, 3);
	cout << '\n';
	a.PrintMatrix();

	cout << '\n';
	cout << a.GetMatrixElement(0, 0) << "  " << a.GetMatrixElement(0, 1) << "  " << a.GetMatrixElement(0, 2) << '\n';
	cout << '\n';
	a.RowTraversal();
	a.ColTraversal();
	cout << '\n' << '\n';
	a.APlusAT();
	cout << '\n' << '\n';
	cout << '\n' << '\n';
	a.AMultiplyAT();
	cout << '\n' << '\n';
	a.ClearList();
	cout << a.IsEmpty() << '\n';
	return 0;
}
#endif


#if 1
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int m, n, l;
	int i, j, v;
	cin >> m >> n >> l;
	OrtList<int> a(m, n);
	for (int count = 0; count < l; count++)
	{
		cin >> i >> j >> v;
		if (v != 0)
		{
			a.Insert(i, j, v);
		}
	}
	a.ColTraversal();
	a.APlusAT();
	a.AMultiplyAT();
	return 0;
}
#endif

template<class ElementType>
int OrtList<ElementType>::RowLength(const int & i)
{
	if (i >= head.i || i < 0)
	{
		cout << "row length: out of range" << '\n';
		exit(0);
	}
	Node<ElementType>* pr = head.next_row + i;
	int len = 0;
	while (pr->next_col)
	{
		pr = pr->next_col;
		len++;
	}
	return len;
}

template<class ElementType>
int OrtList<ElementType>::ColLength(const int & j)
{
	if (j >= head.j || j < 0)
	{
		cout << "col length: out of range" << '\n';
		exit(0);
	}
	Node<ElementType>* pr = head.next_col + j;
	int len = 0;
	while (pr->next_row)
	{
		pr = pr->next_row;
		len++;
	}
	return len;
}

template<class ElementType>
bool OrtList<ElementType>::IsEmpty()
{
	Node<ElementType>* pr;
	for (int row_index = 0; row_index < head.i; row_index++)
	{
		pr = head.next_row + row_index;
		if (pr->next_col != NULL)
			return false;
	}
	for (int col_index = 0; col_index < head.j; col_index++)
	{
		pr = head.next_col + col_index;
		if (pr->next_row != NULL)
			return false;
	}
	return true;
}

template<class ElementType>
bool OrtList<ElementType>::Insert(const int & i, const int & j, const int & v)
{
	if (i >= head.i || j >= head.j || i < 0 || j < 0)
	{
		cout << "insert: out of range" << '\n';
		return false;
	}
	Node<ElementType>* p = new Node<ElementType>;
	if (!p)
	{
		cout << "insert: new error" << '\n';
		return false;
	}
	p->i = i;
	p->j = j;
	p->data = v;

	Node<ElementType>* pr_row = head.next_row + i;
	Node<ElementType>* pr_col = head.next_col + j;
	Node<ElementType>* ppr;
	// TODO:
	ppr = pr_row->next_col;
	while (ppr&&ppr->j < j)
	{
		pr_row = ppr;
		ppr = pr_row->next_col;
	}
	p->next_col = ppr;
	pr_row->next_col = p;
	// END
	// TODO:
	ppr = pr_col->next_row;
	while (ppr&&ppr->i < i)
	{
		pr_col = ppr;
		ppr = pr_col->next_row;
	}
	p->next_row = ppr;
	pr_col->next_row = p;
	// END
	return true;
}

template<class ElementType>
bool OrtList<ElementType>::RowTraversal()
{
	Node<ElementType>* pr;
	for (int index = 0; index < head.i; index++)
	{
		pr = head.next_row + index;
		while (pr->next_col)
		{
			pr = pr->next_col;
			//cout << "{ i , j , v } = " << "{ " << pr->i << " " << pr->j << " " << pr->data << " }" << '\n';
			cout << pr->i << " " << pr->j << " " << pr->data << '\n';
		}
	}
	return true;
}

template<class ElementType>
bool OrtList<ElementType>::ColTraversal()
{
	Node<ElementType>* pr;
	for (int index = 0; index < head.j; index++)
	{
		pr = head.next_col + index;
		while (pr->next_row)
		{
			pr = pr->next_row;
			//cout << "{ i , j , v } = " << "{ " << pr->j << " " << pr->i << " " << pr->data << " }" << '\n';
			cout << pr->j << " " << pr->i << " " << pr->data << '\n';
		}
	}
	return true;
}

template<class ElementType>
bool OrtList<ElementType>::ClearList()
{
	Node<ElementType>* pr;
	Node<ElementType>* p;
	for (int index = 0; index < head.j; index++)
	{
		pr = head.next_col + index;
		p = pr->next_row;
		while (p)
		{
			pr = p->next_row;
			delete p;
			p = pr;
		}
		head.next_col[index].next_row = NULL;
	}
	for (int index = 0; index < head.i; index++)
	{
		head.next_row[index].next_col = NULL;
	}
	return true;
}

template<class ElementType>
ElementType OrtList<ElementType>::GetElement(const int & i, const int & j)
{
	if (i > head.i || j > head.j || i < 0 || j < 0)
	{
		cout << "get element: out of range" << '\n';
		exit(0);
	}
	if (RowLength(i) == 0 || ColLength(j) == 0)
	{
		cout << "get element: element doesn't exist" << '\n';
		exit(0);
	}
	Node<ElementType>* pr = head.next_col + j;
	Node<ElementType>* p = pr->next_row;
	while (p->i<i)
	{
		p = p->next_row;
	}
	if (p->i != i)
	{
		cout << "get element: error" << '\n';
		exit(0);
	}
	return p->data;
}
template<class ElementType>
ElementType OrtList<ElementType>::GetMatrixElement(const int & i, const int & j)
{
	if (i > head.i || j > head.j || i < 0 || j < 0)
	{
		cout << "get element: out of range" << '\n';
		exit(0);
	}
	ElementType temp = 0;
	if ((head.next_row[i]).next_col && (head.next_col[j]).next_row)
	{
		Node<ElementType>* pr = (head.next_row[i]).next_col;
		while (pr && (pr->j)<j)
		{
			pr = pr->next_col;
		}
		if (pr && (pr->j) == j)
		{
			temp = pr->data;
		}
	}
	return temp;
}
template<class ElementType>
void OrtList<ElementType>::PrintMatrix()
{
	Node<ElementType>* pr;
	ElementType temp;
	for (int i = 0; i < head.i; i++)
	{
		pr = (head.next_row[i]).next_col;
		for (int j = 0; j < head.j; j++)
		{
			temp = 0;
			if (pr && (pr->j) == j)
			{
				temp = pr->data;
				pr = pr->next_col;
			}
			cout << temp << "  ";
		}
		cout << '\n';
	}
}

template<class ElementType>
void OrtList<ElementType>::APlusAT()
{
	Node<ElementType>* A;
	Node<ElementType>* AT;
	for (int i = 0; i < head.i; i++)
	{
		A = (head.next_row[i]).next_col;
		AT = (head.next_col[i]).next_row;
		while (A || AT)
		{
			if (A)
			{
				if (AT)
				{
					if ((A->j) == (AT->i))
					{
						cout << A->i << " " << A->j << " " << (A->data) + (AT->data) << '\n';
						A = A->next_col;
						AT = AT->next_row;
					}
					else if ((A->j) > (AT->i))
					{
						cout << A->i << " " << AT->i << " " << (AT->data) << '\n';
						AT = AT->next_row;
					}
					else
					{
						cout << A->i << " " << A->j << " " << (A->data) << '\n';
						A = A->next_col;
					}
				}
				else
				{
					cout << A->i << " " << A->j << " " << (A->data) << '\n';
					A = A->next_col;
				}
			}
			else
			{
				cout << AT->j << " " << AT->i << " " << (AT->data) << '\n';
				AT = AT->next_row;
			}
		}
	}
}

template<class ElementType>
void OrtList<ElementType>::AMultiplyAT()
{
	Node<ElementType>* A;
	Node<ElementType>* AT;
	int temp;
	for (int i = 0; i < head.i; i++)
	{
		for (int j = 0; j < head.j; j++)
		{
			temp = 0;
			A = (head.next_row[i]).next_col;
			AT = (head.next_row[j]).next_col;
			while (A && AT)
			{
				if ((A->j) == (AT->j))
				{
					temp += (A->data * AT->data);
					A = A->next_col;
					AT = AT->next_col;
				}
				else if ((A->j) < (AT->j))
				{
					A = A->next_col;
				}
				else
				{
					AT = AT->next_col;
				}
			}
			if (temp != 0)
			{
				cout << i << " " << j << " " << temp << '\n';
			}
		}
	}
}
