#pragma once
#include<iostream>
#include"clsDblLinkedList.h"
template<class T>
class clsMyQueue
{
protected:
	clsDblLinkedList<T>_MyList;
public:
	void push(T value) {
		_MyList.InsertAtEndList(value);
	}
	void pop() {
		_MyList.DeleteFirstNode();
	}
	bool IsEmpty() {
		return _MyList.IsEmpty();
	}
	int Size() {
		return  _MyList.Size();
	}
	T front() {
		return _MyList.GetItem(0);
	}
	T back() {
		return _MyList.GetItem(Size() - 1);
	}
	T GetItem(int Index) {
		return _MyList.GetItem(Index);
	}
	void Print() {
		_MyList.PrintLLinkedList();
	}
	void Reverse() {
		_MyList.Reverse();
	}
	bool UpdateItem(int Index, T value) {
		return _MyList.UpdateItem(Index, value);
	}
	bool InsertAfter(int Index, T value) {
		return _MyList.InsertAfter(Index, value);
	}
	void InsertAtFront(T value) {
		_MyList.InsertAtBeiginList(value);
	}
	void InsertAtBack(T value) {
		_MyList.InsertAtEndList(value);
	}
	void Clear() {
		_MyList.Clear();
	}
};

