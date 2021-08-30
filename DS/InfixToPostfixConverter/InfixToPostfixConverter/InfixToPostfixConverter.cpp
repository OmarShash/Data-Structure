// InfixToPostfixConverter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "linkedStack.cpp"

using namespace std;

Stack<char> converter;
Stack<int> solver;

bool isLowerPrecedence(char token)
{
	return (
		(token == '+' && (converter.top() == '-' || converter.top() == '*' || converter.top() == '/'))
		|| (token == '-' && (converter.top() == '+' || converter.top() == '*' || converter.top() == '/'))
		|| (token == '*' && (converter.top() == '/'))
		|| (token == '/' && (converter.top() == '*'))
		);
}

string infixToPostfixConverter(string infix)
{
	string postfix = "";
	for (int i = 0; i < infix.length(); i++)
	{
		char token = infix[i];
		if (isdigit(token))
		{
			int j = i;
			do {
				postfix += infix[j];
				i = j;
				j++;
			} while (isdigit(infix[j]));
			postfix += ' ';
		}
		else if (token == ' ')
		{
			continue;
		}
		else if (token == '(')
		{
			converter.push(token);
		}
		else if (token == ')')
		{
			while (converter.top() != '(')
			{
				postfix += converter.pop(), postfix += ' ';
			}
			converter.pop();
		}
		else
		{
			while (!converter.empty() && isLowerPrecedence(token))
			{
				postfix += converter.pop(), postfix += ' ';
			}
			converter.push(token);
		}
	}
	while (!converter.empty())
	{
		postfix += converter.pop(), postfix += ' ';
	}
	return postfix;
}

int solve(string infix)
{
	string postfix = infixToPostfixConverter(infix);
	for (int i = 0; i < postfix.length(); i++)
	{
		char token = postfix[i];
		if (isdigit(token))
		{
			int j = i;
			string s = "";
			do {
				s += postfix[j];
				i = j;
				j++;
			} while (isdigit(postfix[j]));
			solver.push(stoi(s));
		}
		else if (token == '+')
		{
			int y = solver.pop();
			int x = solver.pop();
			solver.push(x + y);
		}
		else if (token == '-')
		{
			int y = solver.pop();
			int x = solver.pop();
			solver.push(x - y);
		}
		else if (token == '*')
		{
			int y = solver.pop();
			int x = solver.pop();
			solver.push(x * y);
		}
		else if (token == '/')
		{
			int y = solver.pop();
			int x = solver.pop();
			if (y == 0)
				cout << "You Can't divide by zero";
			else
				solver.push(x / y);
		}
		else
			continue;
	}
	return solver.pop();
}

int main()
{
	string infix;
	getline(cin, infix);
	cout << infixToPostfixConverter(infix) << endl;
	cout << solve(infix) << "\n";
	system("pause");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
