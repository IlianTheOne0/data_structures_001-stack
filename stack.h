#ifndef STACK_H
#define STACK_H

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
	Stack(const size_t& maxSize) : _maxSize(maxSize), Stack() {}
	Stack(const Stack& other)
		: _maxSize(other._maxSize), _counter(other._counter)
	{ _stack = new TValue[_maxSize]; for (size_t i = 0; i < _counter; i++) { _stack[i] = other._stack[i]; } }
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

#endif