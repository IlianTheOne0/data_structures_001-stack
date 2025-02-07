#include <iostream>
#include <conio.h>

using std::cout;
using std::endl;
using std::cin;

#define DEFAULT_STACK_SIZE 3

template<typename TValue>
class Stack
{
private:
	size_t _maxSize;
	TValue* _stack;
	size_t _counter{ 0 };

	void _resize()
	{
		_maxSize += DEFAULT_STACK_SIZE;

		TValue* newStack = new TValue[_maxSize];
		for (size_t i = 0; i < _counter; i++) { newStack[i] = _stack[i]; }
		delete[] _stack; _stack = newStack;
	}
public:
	Stack() : _maxSize(DEFAULT_STACK_SIZE) { _stack = new TValue[_maxSize]; }
	Stack(const size_t& maxSize) : _maxSize(maxSize) { _stack = new TValue[_maxSize]; }
	~Stack() { delete[] _stack; }

	void push(TValue element) { if (_counter == _maxSize) { _resize(); } _stack[_counter++] = element; }
	TValue pop() { if (_counter > 0) { return _stack[--_counter]; } return TValue(); }
	TValue top() { return (_counter != 0) ? _stack[_counter - 1] : TValue(); }
	TValue clear() { _counter = 0; return TValue(); }

	bool isEmpty() { return _counter == 0; }
	bool isFull() { return _counter == _maxSize; }
	size_t getSize() { return _maxSize; }
	size_t getCounter() { return _counter; }
};

int main()
{
	Stack<char> stack;
	cout << "Adding a character to the stack:" << endl;
	cout << "  Push 'a'. Result: "; stack.push('a'); cout << stack.top() << endl;
	cout << "  Push 'b'. Result: "; stack.push('b'); cout << stack.top() << endl;
	cout << "  Push 'c'. Result: "; stack.push('c'); cout << stack.top() << endl;
	cout << "  Push 'd'. Result: "; stack.push('d'); cout << stack.top() << endl;
	cout << endl;
	
	cout << "Checks: " << endl;
	cout << "  Max size. Result: " << stack.getSize() << endl;
	cout << "  Counting the number of characters in the stack. Result: " << stack.getCounter() << endl;
	cout << "  isEmpty. Result: "; (stack.isEmpty()) ? cout << "true" : cout << "false"; cout << endl;
	cout << "  isFull. Result: "; (stack.isFull()) ? cout << "true" : cout << "false"; cout << endl;
	cout << endl;

	cout << "Deleting a character from the stack + getting without deleting the top character in the stack:" << endl;
	cout << "  Pop + top. Result: "; stack.pop(); cout << stack.top() << endl;
	cout << "  Pop + top. Result: "; stack.pop(); cout << stack.top() << endl;
	cout << "  Pop + top. Result: "; stack.pop(); cout << stack.top() << endl;
	cout << endl;


	cout << "Checks: " << endl;
	cout << "  isEmpty. Result: "; (stack.isEmpty()) ? cout << "true" : cout << "false"; cout << endl;
	cout << "  isFull. Result: "; (stack.isFull()) ? cout << "true" : cout << "false"; cout << endl;
	cout << endl;

	cout << "Adding a character to the stack:" << endl;
	cout << "  Push 'a'. Result: "; stack.push('a'); cout << stack.top() << endl;
	cout << "  Push 'b'. Result: "; stack.push('b'); cout << stack.top() << endl;
	cout << "  Counting the number of characters in the stack. Result: " << stack.getCounter() << endl;
	cout << "  Push 'c'. Result: "; stack.push('c'); cout << stack.top() << endl;
	cout << "  Push 'd'. Result: "; stack.push('d'); cout << stack.top() << endl;
	cout << "  Push 'e'. Result: "; stack.push('e'); cout << stack.top() << endl;
	cout << "  Push 'f'. Result: "; stack.push('f'); cout << stack.top() << endl;
	cout << "  Push 'g'. Result: "; stack.push('g'); cout << stack.top() << endl;
	cout << "  Push 'h'. Result: "; stack.push('h'); cout << stack.top() << endl;
	cout << "  Push 'j'. Result: "; stack.push('j'); cout << stack.top() << endl;
	cout << endl;

	cout << "Max size. Result: " << stack.getSize() << endl;
	cout << "Counting the number of characters in the stack. Result: " << stack.getCounter() << endl;
	cout << "Clear the stack. Result (isEmpty): "; stack.clear(); (stack.isEmpty()) ? cout << "true" : cout << "false"; cout << endl;
	cout << "Max size. Result: " << stack.getSize() << endl;
	cout << "Counting the number of characters in the stack. Result: " << stack.getCounter() << endl;
	cout << endl;

	char ch = _getch();
	return 0;
}