#pragma once
#include<iostream>
#include"clsMyQueue.h"
template<class T>
class clsMyStack :public clsMyQueue<T>
{

public:
	void push(T value) {
		clsMyQueue<T>::_MyList.InsertAtBack(value);

	}

	T Top() {
		return clsMyQueue<T>::_MyList.front();
	}
	T bottom() {
		return clsMyQueue<T>::_MyList.back();
	}

};
