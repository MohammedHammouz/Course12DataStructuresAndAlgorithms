#pragma once
#include<iostream>

template<class T>
class clsMyDynamicArray
{
protected:
	int _Size;
	T* _TempArray;
public:
	
	T* OriginallArray;
	
	clsMyDynamicArray(int Size=0) {
		if (Size < 0) {
			Size = 0;
		}
		_Size = Size;
		OriginallArray = new T[_Size];
	}
	void Resize(int NewSize) {
		if (NewSize < _Size) {
			_Size = NewSize;
		}
		_TempArray = new T[NewSize];
		for (int i = 0; i < NewSize; i++) {
			_TempArray[i] = OriginallArray[i];
		}
		_Size = NewSize;
		delete[]OriginallArray;
		OriginallArray = _TempArray;
	}
	~clsMyDynamicArray() {
		delete[]OriginallArray;
	}
	bool SetItem(int Index, T value) {
		if (Index<0 || Index>_Size - 1) {
			return false;
		}
		OriginallArray[Index] = value;
		return true;
	}
	void PrintList() {
		for (int i = 0; i < _Size; i++) {
			std::cout << OriginallArray[i] << " ";
		}
	}
	int Size() {
		return _Size;
	}
	void IsEmpty() {
		return _Size == 0 ? true : false;
	}
	T GetItem(int Index) {
		return OriginallArray[Index];
	}
	void Reverse() {
		_TempArray = new T[_Size];
		int counter = 0;
		for (int i = _Size - 1; i >= 0; i--) {
			_TempArray[counter] = OriginallArray[i];
			counter++;
		}
		delete[]OriginallArray;
		OriginallArray = _TempArray;
	}
	void Clear() {
		_Size = 0;
		_TempArray = new T[0];
		delete[]OriginallArray;
		OriginallArray = _TempArray;
	}
	bool DeleteAtIndex(int Index) {
		if (Index > _Size || Index < 0) {
			return false;
		}
		_Size--;
		_TempArray = new T[_Size];
		for (int i = 0; i < Index; i++) {
			_TempArray[i] = OriginallArray[i];
		}
		for (int i = Index; i < _Size - 1; i++) {
			_TempArray[i + 1] = OriginallArray[i];
		}
		delete[]OriginallArray;
		OriginallArray = _TempArray;
		return true;
	}
	void DeleteFirstIndex() {
		DeleteAtIndex(0);
	}
	void DeleteLastIndex() {
		DeleteAtIndex(_Size - 1);
	}
	int Find(T value) {
		for (int i = 0; i <= _Size - 1; i++) {
			if (OriginallArray[i] == value) {
				return i;
			}
		}
		return -1;
	}
	bool DeleteItem(T value) {
		int ItemToDelete = Find(value);
		if (ItemToDelete == -1) {
			return false;
		}
		DeleteAtIndex(ItemToDelete);
		return true;
	}
	bool InsertAt(int Index, T value) {
		if (Index > _Size || Index < 0) {
			return false;
		}
		_Size++;
		_TempArray = new T[_Size];
		for (int i = 0; i < Index; i++) {
			_TempArray[i] = OriginallArray[i];
		}
		_TempArray[Index] = value;
		for (int i = Index; i < _Size - 1; i++) {
			_TempArray[i + 1] = OriginallArray[i];
		}
		delete[]OriginallArray;
		OriginallArray = _TempArray;
		return true;
	}
	void InsertAtBegining(T value) {
		InsertAt(0, value);
	}
	void InsertAtEnd(T value) {
		InsertAt(_Size, value);
	}
	bool InsertAfter(int Index, T value) {
		if (Index >= _Size) {
			return InsertAt(_Size - 1, value);
		}
		else {
			return InsertAt(Index + 1, value);
		}

	}
	bool InsertBefore(int Index, T value) {
		if (Index < 1) {
			return InsertAt(0, value);
		}
		else {
			return InsertAt(Index - 1, value);
		}
	}
};

