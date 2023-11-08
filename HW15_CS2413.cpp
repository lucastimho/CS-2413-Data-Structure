//
// ========================================
// HW15: Implement Min Heap
// ========================================
//
// In this assignment, we will implement
// a Min Heap. You can choose to implement
// it based on linked-list or array.
//
// The provided template assumes array-based
// implementation, but feel free to modify
// it as needed. Just make sure to keep the
// in/output (format) of all functions that
// are tested in the main function.
//
// Your major task is to implement the heap
// class. In addition, in the main function,
// test mode 3, you need to implement an
// application of your heap to sort an array
// of nodes based on their keys.
//
#include <iostream>
using namespace std;

// The node class has been defined for you.
// If you do linked-list based implementation,
// feel free to add variables and functions.
class Node
{
private:
	int key;
	// satellite data
public:
	void Set_key(int x);
	int Get_key();
	Node();
};
void Node::Set_key(int x)
{
	key = x;
}
int Node::Get_key()
{
	return key;
}
Node::Node()
{
	key = -1;
}

// The MinHeap class has been structured for you.
// Please complete the functions and feel free
// to add variables or functions to facilitate
// your own designs and implementations.
//
// However, Add, Remove and Root functions must
// be implemented based on the given definitions
// (because we test them in the main function).
class MinHeap
{
private:
	Node *root;
	int ArraySize;
	int HeapSize;

public:
	// This function prints keys in the
	// heap based on breadth-first traverse
	// (do not add space between keys;
	//  do not change line at any time).
	// You may use a modified version of
	// the BS traverse function in HW10.
	void BSTraverse();

	// This function adds a node
	// at address p to the heap.
	void Add(Node *p);

	// This function removes root.
	void Remove();

	// This function returns root.
	Node *Root();

	// void Resize(int n);

	// You can design the constructor
	// in any way you like e.g., you
	// may initialize heap size to
	// zero or to some large enough
	// In the latter case, you should
	// properly mark unused array cells.
	MinHeap();
	// This function maintains heap structure
	void sort(int index);
};
MinHeap::MinHeap() // Initializes Min Heap
{
	this->HeapSize = 5;
	this->ArraySize = 0;
	root = new Node[HeapSize];
}
void MinHeap::BSTraverse() // Prints Min Heap in breadth first order
{
	for (int i = 0; i < ArraySize; ++i)
	{
		cout << root[i].Get_key();
	}
}
void MinHeap::Add(Node *p) // Adds Node* to Min Heap
{
	if (ArraySize == HeapSize)
	{
		return;
	}
	ArraySize++;
	int index = ArraySize - 1;
	root[index] = *p;
	while (index > 0 && root[(index - 1) / 2].Get_key() > root[index].Get_key())
	{
		std::swap(root[index], root[(index - 1) / 2]);
		index = (index - 1) / 2;
	}
}
void MinHeap::Remove() // Removes root and restructure Min Heap
{
	if (ArraySize <= 0)
	{
		return;
	}
	if (ArraySize == 1)
	{
		ArraySize--;
	}
	else
	{
		root[0] = root[ArraySize - 1];
		ArraySize--;
		sort(0);
	}
}
Node *MinHeap::Root() // Returns root
{
	return root;
}
void MinHeap::sort(int index) // Sorts Min Heap structure
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int small = index;

	if (left < ArraySize && root[left].Get_key() < root[small].Get_key())
	{
		small = left;
	}
	if (right < ArraySize && root[right].Get_key() < root[small].Get_key())
	{
		small = right;
	}
	if (small != index)
	{
		std::swap(root[index], root[small]);
		sort(small);
	}
}

int main()
{
	// mode:test mode
	// key: keys of nodes to be added to heap
	int mode, key;
	cin >> mode;

	// Adding nodes to heap.
	MinHeap heap;
	Node *temp;
	while (cin >> key)
	{
		temp = new Node;
		temp->Set_key(key);
		heap.Add(temp);
	}

	// Mode 0: test Add()
	if (mode == 0)
	{
		heap.BSTraverse();
	}
	// Mode 1: test Root()
	else if (mode == 1)
	{
		temp = heap.Root();
		cout << temp->Get_key();
	}
	// Mode 2: test Remove()
	else if (mode == 2)
	{
		heap.Remove();
		heap.BSTraverse();
	}
	// Mode 3: implement heap sort.
	else if (mode == 3)
	{

		// First construct an array of nodes.
		// The keys are 5, 4, 3, 2, 1 in "arr".
		// Do not modify this part.
		Node arr[5];
		for (int i = 0; i < 5; i++)
		{
			arr[i].Set_key(5 - i);
		}

		// Now, write codes that apply your
		// heap to sort the nodes in "arr"
		// in ascending order (and place them
		// back in "arr").
		// ......
		// ......
		// ......
		MinHeap tempHeap;
		for (int i = 0; i < 5; i++)
		{
			tempHeap.Add(&arr[i]);
		}
		for (int i = 0; i < 5; i++)
		{
			arr[i] = tempHeap.Root()[0];
			tempHeap.Remove();
		}

		// At last, we print keys in arr.
		// They should be 1, 2, 3, 4, 5.
		// Do not modify this part.
		for (int i = 0; i < 5; i++)
		{
			cout << arr[i].Get_key();
		}
	}

	return 0;
}
