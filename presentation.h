#ifndef PRESENTATION_H
#define PRESENTATION_H

#include <iostream>

using std::cout;
using std::endl;
using std::cin;

#include "domain.h"

void Intro()
{
	string input;
	cout << "Enter a sentence ending with ';': ";
	getline(cin, input);

	size_t letterCounter{};
	string checksResult = Domain::checks(input, letterCounter);
	cout << "Checks: " << checksResult << endl;
	if (checksResult != "PASSED") { return; }

	Stack<char> stack;
	Domain::createStack(input, letterCounter, stack);

	cout << endl << endl;
	string bracketValidationResult = Domain::bracketValidation(stack);
	if (bracketValidationResult == "ERROR") { cout << "Error: "; Domain::print(input, letterCounter, stack); }
	else { cout << "The string matches the rules"; }
	cout << endl;
}

#endif