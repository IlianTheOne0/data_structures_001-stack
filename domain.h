#ifndef DOMAIN_H
#define DOMAIN_H

#include <string>

using std::string;
using std::to_string;
using std::move;

#include "stack.h"

class Domain
{
public:
	static string checks(const string& value, size_t& counter)
	{		
		for (; value[counter] != ';'; counter++)
		{ if (value[counter] == '\0') { return "Missing semicolon"; } }

		if (counter == 0) { return "Nothing was entered!"; }

		return "PASSED";
	}

	static void createStack(const string& value, const size_t& counter, Stack<char>& stack) { Stack<char> newStack; for (size_t i = counter; i > 0; i--) { stack.push(value[i - 1]); } }

	static void print(const Stack<char>& stack)
	{
		Stack<char> stack0{ move(stack) };

		for (size_t i = 0; i < stack0.getSize(); i++) { cout << stack0.top(); stack0.pop(); } cout << endl;
	}
	static void print(const string& value, const size_t counter, Stack<char>& stack) { for (size_t i = 0; i < counter - stack.getCounter(); i++) { cout << value[i]; } }

	static string bracketValidation(Stack<char>& stack)
	{
		Stack<char> newStack;

		for (size_t i = 0; i < stack.getCounter(); i++)
		{
			char top = stack.top();

			if (top == '(' || top == '{' || top == '[') { newStack.push(top); }
			else if (top == ')' || top == '}' || top == ']')
			{
				if (stack.isEmpty()) { return "ERROR"; }

				char newTop = newStack.top();
				if (
					(newTop == '(' && top == ')') ||
					(newTop == '{' && top == '}') ||
					(newTop == '[' && top == ']')
					)
				{ newStack.pop(); }
				else { return "ERROR"; }
			}

			stack.pop();
		}
		
		return "PASSED";
	}
};

#endif