#include<iostream>
using namespace std;

template<class ElementType>
class SeqLIST
{
private:
	ElementType* list;
	int len;
	int maxlen;
public:
	SeqLIST(int m)
	{
		maxlen = m;
		len = 0;
		list = new ElementType[m];
	}
	~SeqLIST()
	{
		delete[] list;
	}
	bool IsEmpty();
	bool IsFull();
	bool SetElement(const int &pos, const ElementType &value);
	bool Insert(const int &pos, const ElementType &value);
	bool add(const ElementType &value);
	bool Delete(const int &pos);
	void ClearList();
	ElementType GetElement(const int &pos);
	ElementType PriorElement(const int &current_pos);
	ElementType NextElement(const int &current_pos);
};

struct node {
	int x;
	int y;
};

int main()
{
	struct node b;
	
	SeqLIST<int> a(10);
	cout << a.IsEmpty() << endl;
	a.add(0);
	a.add(1);
	a.Insert(2, 2);
	cout << a.PriorElement(1) << endl;
	cout << a.GetElement(1) << endl;
	cout << a.NextElement(1) << endl;
	a.ClearList();
	cout << a.NextElement(1) << endl;
	system("pause");
	return 0;
}

template<class ElementType>
bool SeqLIST<ElementType>::IsEmpty()
{
	return len == 0;
}

template<class ElementType>
bool SeqLIST<ElementType>::IsFull()
{
	return len == maxlen;
}

template<class ElementType>
bool SeqLIST<ElementType>::SetElement(const int &pos, const ElementType &value)
{
	if (pos>=len||pos<0)
		return false;
	list[pos] = value;
	return true;
}

template<class ElementType>
bool SeqLIST<ElementType>::Insert(const int &pos, const ElementType &value)
{
	if (pos>len||pos<0)
	{
		cout << "insert: out of range" << endl;
		return false;
	}
	if (pos<len)
	{
		for (int i = len; i > pos; i--)
			list[i] = list[i - 1];
	}
	list[pos] = value;
	len++;
	return true;
}

template<class ElementType>
bool SeqLIST<ElementType>::add(const ElementType & value)
{
	if (IsFull())
	{
		cout << "add: out of range" << endl;
		return false;
	}
	list[len] = value;
	len++;
	return true;
}

template<class ElementType>
bool SeqLIST<ElementType>::Delete(const int &pos)
{
	if (pos>=len||pos<0)
	{
		cout << "delete: out of range" << endl;
		return false;
	}
	if (pos<len-1)
	{
		for (int i = pos; i < len-1; i++)
			list[i] = list[i + 1];
	}
	len--;
	return true;
}

template<class ElementType>
void SeqLIST<ElementType>::ClearList()
{
	delete[] list;
	this->len = 0;
	this->maxlen = 0;
}


template<class ElementType>
ElementType SeqLIST<ElementType>::GetElement(const int &pos)
{
	if (pos >= len || pos < 0)
	{
		cout << "out of range" << endl;
		exit(0);
	}
	return list[pos];
}

template<class ElementType>
ElementType SeqLIST<ElementType>::PriorElement(const int & current_pos)
{
	if (current_pos>len||current_pos<=0)
	{
		cout << "PriorElement: out of range" << endl;
		exit(0);
	}
	return list[current_pos - 1];
}

template<class ElementType>
ElementType SeqLIST<ElementType>::NextElement(const int & current_pos)
{
	if (current_pos>=len||current_pos<0)
	{
		cout << "NextElement: out of range" << endl;
		exit(0);
	}
	return list[current_pos + 1];
}
