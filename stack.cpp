
#include <iostream>

using namespace std;

class MyStack
{

private:
	int *stack;

	int itop;

public:
	// This function pushes x into the stack.
	// Push should always be successful even
	// if the stack array is currently "full".
	void push(int x);

	// This function removes the top element
	// in the stack. It does nothing if the
	// stack is empty.
	void pop();

	// This function returns the top element
	// in the stack. It returns -1 if the stack
	// is empty.
	int top();

	// This function returns number of elements
	// in the stack. Note this means it should
	// return 0 if the stack is empty.
	int Ssize();

	// This function is given to you.
	// It initializes a small array.
	// Do not modify it.
	MyStack();
};

MyStack::MyStack()
{
	stack = new int[2];
	itop = -1;
};

void MyStack::push(int x)
{
	if (itop >= Ssize())
	{
		stack = new int[itop + 1];
	}
	itop++;
	stack[itop] = x;
}
void MyStack::pop()
{
	if (Ssize() != 0)
	{
		itop--;
		int *tempStack = new int[Ssize() - 1];
		for (int i = 0; i < Ssize(); i++)
		{
			tempStack[i] = stack[i];
		}
		stack = tempStack;
		delete[] tempStack;
	}
}
int MyStack::top()
{
	if (Ssize() == 0)
	{
		return -1;
	}
	else
	{
		return itop;
	}
}
int MyStack::Ssize()
{
	int size = 0;
	while (stack[size] != 0)
	{
		size++;
	}
	return size;
}

int main()
{
	MyStack x;

	int temp;

	while (cin >> temp)
	{

		x.push(temp);
	}

	for (int i = 0; i < x.Ssize(); i++)
	{

		cout << x.top() << '\n';

		x.pop();
	}

	return 0;
}
