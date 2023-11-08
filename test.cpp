#include <iostream>

// Definition of a simple singly linked list node
struct Node
{
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};

// Function to create a single linked list of null nodes with a given size
Node *createNullList(int size)
{
  if (size <= 0)
  {
    return nullptr; // Return nullptr for an empty list
  }

  Node *head = new Node(0); // Create the head node
  Node *current = head;

  // Create the remaining null nodes
  for (int i = 1; i < size; ++i)
  {
    current->next = new Node(0);
    current = current->next;
  }

  return head; // Return the head of the list
}

// Function to print the elements of a linked list
void printList(Node *head)
{
  Node *current = head;
  while (current != nullptr)
  {
    std::cout << current->data << " -> ";
    current = current->next;
  }
  std::cout << "nullptr" << std::endl;
}

int main()
{
  int size = 5; // Change this to the desired size
  Node *nullList = createNullList(size);

  std::cout << "Created a null list of size " << size << ":" << std::endl;
  printList(nullList);

  // Don't forget to free the memory when you're done with the list.
  // In practice, you'd want to delete the nodes and the list itself.

  return 0;
}
