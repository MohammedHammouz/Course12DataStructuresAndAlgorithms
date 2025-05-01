#pragma once
#include<iostream>
#include"clsMyDynamicArray.h"
using namespace std;
template <class T>


class clsMyQueueArray
{
protected:
	clsMyDynamicArray <T> _MyList;

public:

	void push(T value) {
		_MyList.InsertAtEnd(value);
	}
	void pop() {
		_MyList.DeleteLastIndex();
	}
	void print() {
		_MyList.PrintList();
	}
	int Size() {
		return _MyList.Size();
	}
	bool IsEmpty() {
		return _MyList.IsEmpty();
	}
	T front()
	{
		return _MyList.GetItem(0);
	}

	T back()
	{
		return _MyList.GetItem(Size() - 1);
	}

	T GetItem(int Index)
	{
		return _MyList.GetItem(Index);

	}

	void Reverse()
	{

		_MyList.Reverse();

	}

	void UpdateItem(int Index, T NewValue)
	{
		_MyList.SetItem(Index, NewValue);

	}

	void InsertAfter(int Index, T NewValue)
	{
		_MyList.InsertAt(Index, NewValue);
	}


	void InsertAtFront(T Value)
	{
		_MyList.InsertAtBegining(Value);

	}

	void InsertAtBack(T Value)
	{
		_MyList.InsertAtEnd(Value);


	}
	


	void Clear()
	{
		_MyList.Clear();
	}

};


