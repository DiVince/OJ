/* linked list with head node */
#include<iostream>
using namespace std;

template <class ElementType>
class Node
{
public:
	ElementType data;
	Node<ElementType>* next;
};

template <class ElementType>
class LinkList_WHN
{
private:
	Node<ElementType> head;
public:
	LinkList_WHN()
	{
		head = Node<ElementType>();
		head.next = NULL;
		head.data = 128;
	}
	~LinkList_WHN()
	{
		this->ClearList();
	}
	int ListLength();
	bool IsEmpty();
	bool SetElement(const int &pos, const ElementType &data);
	bool Insert(const int &pos, const ElementType &data);
	bool Add(const ElementType &data);
	bool Delete(const int &pos);
	void ClearList();
	ElementType GetElement(const int &pos);
	ElementType PriorElement(const int &current_pos);
	ElementType NextElement(const int &current_pos);
};


#if 0
int main()
{
	LinkList_WHN<int> a;
	cout << a.IsEmpty() << endl;
	a.SetElement(0, 1);
	a.Insert(1, 1);
	a.Add(1);

	a.Insert(1, 2);

	a.Insert(1,2);

	a.Add(3);
	cout << "len: " << a.ListLength() << endl;
	cout << a.GetElement(0) << endl;
	cout << a.GetElement(1) << endl;
	cout << a.GetElement(2) << endl;
	cout << "prior: " << a.PriorElement(1) << endl;
	cout << "next: " << a.NextElement(1) << endl;
	cout <<"prior: "<< a.PriorElement(1) << endl;
	cout <<"next: "<< a.NextElement(1) << endl;
	a.Delete(1);
	cout << a.GetElement(1) << endl;
	a.ClearList();
	cout << a.IsEmpty() << endl;
	cout << "len: " << a.ListLength() << endl;
	cout << a.GetElement(1) << endl;
	return 0;
}
#endif

template<class ElementType>
int LinkList_WHN<ElementType>::ListLength()
{
	Node<ElementType>* pr = &head;
	int len = 0;
	while (pr->next)
	{
		pr = pr->next;
		len++;
	}
	return len;
}

template<class ElementType>
bool LinkList_WHN<ElementType>::IsEmpty()
{
	return head.next == NULL;
}

template<class ElementType>
bool LinkList_WHN<ElementType>::SetElement(const int & pos, const ElementType & data)
{
	if (pos >= ListLength() || pos < 0)
	{
		cout << "set element: out of range" << endl;
		return false;
	}
	int index = -1;
	Node<ElementType>* pr = &head;
	while (index < pos)
	{
		pr = pr->next;
		index++;
	}
	pr->data = data;
	return true;
}

template<class ElementType>
bool LinkList_WHN<ElementType>::Insert(const int & pos, const ElementType & data)
{
	if (pos > ListLength() || pos < 0)
	{
		cout << "insert: out of range" << endl;
		return false;
	}
	Node<ElementType>* p = new Node<ElementType>;
	if (!p)
	{
		cout << "insert: new error" << endl;
		return false;
	}
	p->data = data;
	int index = 0;
	Node<ElementType>* pr = &head;
	while (index < pos)
	{
		pr = pr->next;
		index++;
	}
	p->next = pr->next;
	pr->next = p;
	return true;
}

template<class ElementType>
bool LinkList_WHN<ElementType>::Add(const ElementType & data)
{
	Node<ElementType>* p = new Node<ElementType>;
	if (!p)
	{
		cout << "add: new error" << endl;
		return false;
	}
	p->data = data;
	p->next = NULL;
	int index = 0;
	Node<ElementType>* pr = &head;
	while (index < ListLength())
	{
		pr = pr->next;
		index++;
	}
	pr->next = p;
	return true;
}

template<class ElementType>
bool LinkList_WHN<ElementType>::Delete(const int & pos)
{
	if (pos >= ListLength() || pos < 0)
	{
		cout << "delete: out of range" << endl;
		return false;
	}
	int index = 0;
	Node<ElementType>* pr = &head;
	Node<ElementType>* p;
	while (index < pos)
	{
		pr = pr->next;
		index++;
	}
	p = pr->next;
	pr->next = p->next;
	delete p;
	p = NULL;
	return true;
}

template<class ElementType>
void LinkList_WHN<ElementType>::ClearList()
{
	Node<ElementType>* pr = head.next;
	Node<ElementType>*p;
	while (pr)
	{
		p = pr;
		pr = pr->next;
		delete p;
	}
	pr = NULL;
	p = NULL;
	head.next = NULL;
}

template<class ElementType>
ElementType LinkList_WHN<ElementType>::GetElement(const int & pos)
{
	if (pos > ListLength() || pos < 0)
	{
		cout << "get element: out of range" << endl;
		exit(0);
	}
	int index = -1;
	Node<ElementType>* pr = &head;
	while (index < pos)
	{
		pr = pr->next;
		index++;
	}
	if (pr == NULL)
	{
		cout << "get element: NULL" << endl;
		exit(0);
	}
	return pr->data;
}

template<class ElementType>
ElementType LinkList_WHN<ElementType>::PriorElement(const int & current_pos)
{
	if (current_pos - 1 > ListLength() || current_pos < 0)
	{
		cout << "prior element: out of range" << endl;
		exit(0);
	}
	int index = -1;
	Node<ElementType>*pr = &head;
	while (index < current_pos - 1)
	{
		pr = pr->next;
		index++;
	}
	if (pr == NULL)
	{
		cout << "prior element: NULL" << endl;
		exit(0);
	}
	return pr->data;
}

template<class ElementType>
ElementType LinkList_WHN<ElementType>::NextElement(const int & current_pos)
{
	if (current_pos + 1 >= ListLength() || current_pos < 0)
	{
		cout << "next element: out of range" << endl;
		exit(0);
	}
	int index = -1;
	Node<ElementType>*pr = &head;
	while (index < current_pos + 1)
	{
		pr = pr->next;
		index++;
	}
	if (pr == NULL)
	{
		cout << "next element: NULL" << endl;
		exit(0);
	}
	return pr->data;
}
