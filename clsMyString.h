#pragma once
#include<iostream>
#include"clsMyStackArray.h"
#include<stack>
class clsMyString
{
protected:
	
	std::stack<string> _Undo;
	std::stack<string> _Redo;
	std::string _value;
public:
	
	
	void SetValue(string value) {
		_Undo.push(_value);
		_value = value;
	}
	string GetValue() {
		return _value;
	}
	__declspec(property(get = GetValue, put = SetValue))string value;
	string Top() {
		return _Undo.top();
	}
	void Undo() {
		if (!_Undo.empty()) {
			_Redo.push(_value);
			_value = _Undo.top();
			_Undo.pop();
		}
	}
	void Redo() {
		if (!_Redo.empty()) {
			_Undo.push(_value);
			_value = _Redo.top();
			_Redo.pop();
		}
	}
};

