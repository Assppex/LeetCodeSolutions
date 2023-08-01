// Valid Parentheses.cpp: определяет точку входа для приложения.
//

#include <iostream>
using namespace std;
//Вместо include <stack> пишем свой стек
class Stack_char {
private:
	char* stack;
	int size;
public:
	Stack_char() {
		this->stack = NULL;
		this->size = 0;
	}
	~Stack_char() {
		if (this->size == 0 && this->stack) {
			delete this->stack;
		}
		else if (this->size != 0 && this->stack) {
			delete[] this->stack;
		}
		cout << "Stack deleted" << endl;
	}
	void push(char entity_to_push) {
		if (this->size != 0) {
			char* new_stack = new char[this->size + 1];
			for (int i = 0; i < this->size; i++) {
				new_stack[i] = this->stack[i];
			}
			new_stack[this->size - 1] = entity_to_push;
			delete[] this->stack;
			this->stack = new_stack;
			this->size++;
		}
		else {
			this->stack = new char;
			*(this->stack) = entity_to_push;
			this->size++;
		}
	}

	void pop() {
		if(this->size != 1){
			char* new_stack = new char[this->size - 1];
			for (int i = 0; i < this->size - 1; i++) {
				new_stack[i] = this->stack[i];
			}
			cout << "hi" << endl;
			delete[] this->stack;
			this->stack = new_stack;
			this->size--;
		}
		else {
			delete this->stack;
			this->stack = NULL;
			this->size--;
		}
	}
	void print_stack() {
		for (int i = 0; i < this->size; i++) {
			cout << "Value with ind: " << i << " is " << *(this->stack + i) << endl;
		}
	}

	char get_top_element() {
		return *(this->stack + this->size - 1);
	}

	bool is_empty() {
		if (this->size == 0) {
			return true;
		}
		else {
			return false;
		}
	}
};

class Solution {
public:
	bool isValid(string s) {
		Stack_char stack_open;
		bool res = false;
		if (s.length() <= 10000) {

			for (int i = 0; i < s.length(); i++) {
				if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
					stack_open.push(s[i]);
					stack_open.print_stack();
					cout << stack_open.is_empty() << endl;
				}
				else {
					if (stack_open.is_empty() == true || (s[i] == ')' && stack_open.get_top_element() != '(') || (s[i] == ']' && stack_open.get_top_element() != '[') || (s[i] == '}' && stack_open.get_top_element() != '{')) {
						return false;
					}
					stack_open.pop();
				}
			}
			if (stack_open.is_empty() == true) {
				return true;
			}

		}
		return res;
	}
};

int main()
{
	Solution a;
	cout << a.isValid("()[]{}") << endl;
	return 0;
}
