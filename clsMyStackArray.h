#pragma once
#include<iostream>
#include"clsMyQueueArray.h"

using namespace std;
template<class T>

class clsMyStackArray :public clsMyQueueArray<T>
{

public:

	void push(T value) {
		clsMyQueueArray <T>::_MyList.InsertAtBegining(value);

	}

	T Top() {
		
		return clsMyQueueArray <T>::front();
	}
	T bottom() {
		return clsMyQueueArray <T>::back();
	}
};

