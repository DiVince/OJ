/* linked list without head node */
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
class LinkList
{
private:
	Node<ElementType>* head;
public:
	LinkList()
	{
		head = NULL;
	}
	~LinkList()
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
	LinkList<int> a;
	cout << a.IsEmpty() << endl;
	a.SetElement(0, 1);
	a.Insert(1, 2);
	a.Add(1);
	a.Insert(1, 2);
	a.Add(3);
	cout <<"len: "<< a.ListLength() << endl;
	cout << a.GetElement(1) << endl;
	cout << a.PriorElement(1) << endl;
	cout << a.NextElement(1) << endl;
	a.Delete(1);
	cout << a.GetElement(1) << endl;
	a.ClearList();
	cout << a.IsEmpty() << endl;
	cout << "len: " << a.ListLength() << endl;
	//cout << a.PriorElement(1) << endl;
	//cout << a.NextElement(1) << endl;
	cout << a.GetElement(1) << endl;

	return 0;
}
#endif

template<class ElementType>
int LinkList<ElementType>::ListLength()
{
	Node<ElementType>* pr = head;
	int len = 0;
	while (pr)
	{
		pr = pr->next;
		//pr = *pr->next;
		len++;
	}
	return len;
}

template<class ElementType>
bool LinkList<ElementType>::IsEmpty()
{
	return head == NULL;
}

template<class ElementType>
bool LinkList<ElementType>::SetElement(const int & pos, const ElementType & data)
{
	if (pos >= ListLength() || pos < 0)
	{
		cout << "set element: out of range" << endl;
		return false;
	}
	Node<ElementType>* pr = head;
	int index = 0;
	while (index < pos)
	{
		pr = pr->next;
		index++;
	}
	if (pr == NULL)
	{
		cout << "set element: element does not exist" << endl;
		return false;
	}
	pr->data = data;
	return true;
}

template<class ElementType>
bool LinkList<ElementType>::Insert(const int & pos, const ElementType & data)
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
	if (pos == 0)
	{
		p->next = head;
		head = p;
		return true;
	}
	int index = 0;
	Node<ElementType>* pr = head;
	while (index < pos-1)
	{
		pr = pr->next;
		index++;
	}
	p->next = pr->next;
	pr->next = p;
	return true;
}

template<class ElementType>
bool LinkList<ElementType>::Add(const ElementType & data)
{
	Node<ElementType>* p = new Node<ElementType>;
	if (!p)
	{
		cout << "insert: new error" << endl;
		return false;
	}
	p->data = data;
	p->next = NULL;
	Node<ElementType>*pr = this->head;
	if (pr==NULL)
	{
		head = p;
		return true;
	}
	int index = 0;
	while (index < ListLength() - 1)
	{
		pr = pr->next;
		index++;
	}
	pr->next = p;
	return true;
}

template<class ElementType>
bool LinkList<ElementType>::Delete(const int & pos)
{
	if (pos >= ListLength() || pos < 0)
	{
		cout << "delete: out of range" << endl;
		return false;
	}
	Node<ElementType>* pr = head;
	Node<ElementType>* p;
	int index = 0;
	if (pos == 0)
	{
		head = head->next;
		delete pr;
		pr = NULL;
		return true;
	}
	while (index < pos - 1)
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
void LinkList<ElementType>::ClearList()
{
	Node<ElementType>* pr = head;
	Node<ElementType>* p;
	while (pr)
	{
		p = pr;
		pr = pr->next;
		delete p;
	}
	p = NULL;
	pr = NULL;
	head = NULL;
}

template<class ElementType>
ElementType LinkList<ElementType>::GetElement(const int & pos)
{
	if (pos > ListLength() || pos < 0)
	{
		cout << "get element: out of range" << endl;
		exit(0);
	}
	int index = 0;
	Node<ElementType>* pr = head;
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
ElementType LinkList<ElementType>::PriorElement(const int & current_pos)
{
	if (current_pos - 1 >= ListLength() || current_pos < 0)
	{
		cout << "prior element: out of range" << endl;
		exit(0);
	}
	int index = 0;
	Node<ElementType>* pr = head;
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
ElementType LinkList<ElementType>::NextElement(const int & current_pos)
{
	if (current_pos + 1 > ListLength() || current_pos < 0)
	{
		cout << "next element: out of range" << endl;
		exit(0);
	}
	int index = 0;
	Node<ElementType>* pr = head;
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
