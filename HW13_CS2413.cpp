//
// ========================================
// HW13: Implement a Binary Search Tree
// which can be converted to AVL Tree
// ========================================
//
// In this assignment, we will implement
// an AVL tree which can also do standard
// Binary Search Tree adding and removal.
//
// The Node class and AVL class are both
// partly defined for you.
//
// ***************************************
// You can add new variables and functions
// in both classes. However, you should
// implement the following given functions
// because they will be called in the main
// function to test part of your implementation.
// (Check "main" function for more details.)
// 1. PreTraverse()
// 2. GetRoot()
// 3. Add()
// 4. Remove()
// 5. Add_AVL()
// 6. Remove_AVL()
// 7. Height()
// Other given functions are only recommended.
// ***************************************
//
#include <iostream>
using namespace std;
class Node
{
private:
  int key;
  Node *p_left;
  Node *p_right;
  Node *p_parent;

public:
  void Set_key(int x);
  int Get_key();
  void Set_left(Node *p);
  void Set_right(Node *p);
  void Set_parent(Node *p);
  Node *Get_left();
  Node *Get_right();
  Node *Get_parent();
  Node();
};
void Node::Set_key(int x) // Sets Node key
{
  key = x;
}
int Node::Get_key() // Returns Node key
{
  return key;
}
void Node::Set_left(Node *p) // Sets Left Node child
{
  p_left = p;
}
void Node::Set_right(Node *p) // Sets Right Node child
{
  p_right = p;
}
void Node::Set_parent(Node *p) // Sets Node parent
{
  p_parent = p;
}
Node *Node::Get_left() // Returns Left Node child
{
  return p_left;
}
Node *Node::Get_right() // Returns Right Node child
{
  return p_right;
}
Node *Node::Get_parent() // Returns Node parent
{
  return p_parent;
}
Node::Node() // Initializes Node
{
  key = 0;
  p_left = NULL;
  p_right = NULL;
  p_parent = NULL;
}
class AVL
{
private:
  // This is root of the AVL
  Node *root;

public:
  // This function implements pre-order
  // traverse, starting from the root,
  // and prints the traveres sequence
  // (with no space between nodes).
  // You can use the function you implemented
  // in HW10 (by slightly modifying it).
  // This function is only used to test
  // if your updated AVL/BST is correct.
  void PreTraverse();
  // This function returns the root node.
  // Normally we don't need it. Here we
  // just using it to evaluate your Height function.
  // See main function test case 5 for details.
  Node *GetRoot();
  // This function performs search
  // on the current AVL with "key".
  // It returns address of a matching
  // node, or returns NULL if no
  // matching node is found.
  Node *Search(int key);
  // This function adds a new node at
  // "p" to AVL without considering
  // any violation of AVL property.
  // (So just standard BST adding.)
  // It can return a proper address.
  Node *Add(Node *p);
  // This function removes a node with
  // "key" from AVL without considering
  // any violation of AVL property.
  // (So just standard BST removal.)
  // For simplicty, to fill holes, let
  // us only use the recursive algorithm
  // that looks for the max/min node in
  // the left/right subtress of the hole.
  // It can return a proper address.
  Node *Remove(int key);
  // This function adds a new node
  // stored at "p" to AVL and performs
  // necessary rotations to restore
  // the AVL property.
  void Add_AVL(Node *p);
  // This function removes a node
  // with "key" from AVL and performs
  // necessary rotations to restore
  // the AVL property.
  void Remove_AVL(int key);
  // This function returns height
  // of a subtree rooted at "p".
  int Height(Node *p);
  // This function performs clock-wise
  // rotation at node "p". It only does
  // rotation and does not consider
  // the type of violation scenario.
  // It can return a proper address.
  Node *Rotate_cw(Node *p);
  // This function performs counter
  // clock-wise rotation at node "p".
  // It only does rotation and does
  // not consider the type of violation
  // scenario. It can return a proper address.
  Node *Rotate_cc(Node *p);
  // This function checks if there
  // is a violation at a node p, and
  // return the violation scenario.
  // It returns a string of
  // - "NO" if no violation
  // - "LL" if it is left-left violation
  // - "RR" if it is right-right violation
  // - "LR" if it is left-right violation
  // - "RL" if it is right-left violation
  string CheckViolation(Node *p);
  // This function intiailizes root = NULL.
  AVL();
  // This function does pre-order traversal given a node parameter
  void PreTraverse(Node *p);
  // This function does search taking a Node* and key parameter
  Node *Search(Node *p, int key);
  // This function adds a Node given two Node*
  Node *Add(Node *q, Node *p);
  // This function removes a Node given a Node* and key parameter
  Node *Remove(Node *p, int key);
  // This function adds a Node given two Node* while abiding to AVL properties
  Node *Add_AVL(Node *q, Node *p);
  // This function removes a Node given a Node* and key parameter while abiding to AVL properties
  Node *Remove_AVL(Node *p, int key);
  // This function finds the minimum node for a subtree
  Node *Min(Node *p);
  // This functions determines the difference in height between the left and right subtrees
  int balanceFactor(Node *p);
};
void AVL::PreTraverse(Node *p) // Prints the Pre-order traverse of a given root
{
  if (p == NULL || p->Get_key() == 0)
  {
    return;
  }
  cout << p->Get_key();
  PreTraverse(p->Get_left());
  PreTraverse(p->Get_right());
}
void AVL::PreTraverse() // Prints the Pre-order traverse of the root
{
  PreTraverse(root);
}
Node *AVL::GetRoot() // Returns the root
{
  return root;
}
Node *AVL::Search(Node *p, int key) // Returns the Node* from a given root using a key
{
  if (p == NULL || p->Get_key() == key)
  {
    return p;
  }
  if (key < p->Get_key())
  {
    return Search(p->Get_left(), key);
  }
  return Search(p->Get_right(), key);
}
Node *AVL::Search(int key) // Returns the Node* from the root using a key
{
  return Search(root, key);
}
Node *AVL::Add(Node *q, Node *p) // Returns the added Node* to a given root using standard BST properties
{
  if (q == NULL)
  {
    return p;
  }
  if (p->Get_key() < q->Get_key())
  {
    q->Set_left(Add(q->Get_left(), p));
  }
  else if (p->Get_key() > q->Get_key())
  {
    q->Set_right(Add(q->Get_right(), p));
  }
  else
  {
    return q;
  }
  return q;
}
Node *AVL::Add(Node *p) // Returns the added Node* to the root using standard BST properties
{
  if (root == NULL)
  {
    root = p;
    return p;
  }
  return Add(root, p);
}
Node *AVL::Min(Node *p) // Returns the minimum value from a given root
{
  Node *temp = p;
  while (temp->Get_left() != NULL)
  {
    temp = temp->Get_left();
  }
  return temp;
}
Node *AVL::Remove(Node *p, int key) // Returns the given root after removing a node by its key
{
  if (p == NULL)
  {
    return p;
  }
  if (key < p->Get_key())
  {
    p->Set_left(Remove(p->Get_left(), key));
  }
  else if (key > p->Get_key())
  {
    p->Set_right(Remove(p->Get_right(), key));
  }
  else
  {
    if (p->Get_left() == NULL)
    {
      Node *temp = p->Get_right();
      delete p;
      return temp;
    }
    else if (p->Get_right() == NULL)
    {
      Node *temp = p->Get_left();
      delete p;
      return temp;
    }
    Node *temp = Min(p->Get_right());
    p->Set_key(temp->Get_key());
    p->Set_right(Remove(p->Get_right(), temp->Get_key()));
  }
  return p;
}
Node *AVL::Remove(int key) // Returns the root after removing a node by its key
{
  return Remove(root, key);
}
Node *AVL::Add_AVL(Node *q, Node *p) // Returns a given root after adding a Node* while abiding to AVL properties
{
  if (q == NULL)
  {
    return p;
  }
  if (p->Get_key() < q->Get_key())
  {
    q->Set_left(Add_AVL(q->Get_left(), p));
  }
  else if (p->Get_key() > q->Get_key())
  {
    q->Set_right(Add_AVL(q->Get_right(), p));
  }
  else
  {
    return q;
  }

  int balance = balanceFactor(q);

  if (balance > 1 && p->Get_key() < q->Get_left()->Get_key())
  {
    return Rotate_cw(q);
  }
  if (balance < -1 && p->Get_key() > q->Get_right()->Get_key())
  {
    return Rotate_cc(q);
  }
  if (balance > 1 && p->Get_key() > q->Get_left()->Get_key())
  {
    q->Set_left(Rotate_cc(q->Get_left()));
    return Rotate_cw(q);
  }
  if (balance < -1 && p->Get_key() < q->Get_right()->Get_key())
  {
    q->Set_right(Rotate_cw(q->Get_right()));
    return Rotate_cc(q);
  }
  return q;
}
void AVL::Add_AVL(Node *p) // Returns the root after adding a Node* while abiding to AVL properties
{
  if (root == NULL)
  {
    root = p;
    return;
  }
  root = Add_AVL(root, p);
}
Node *AVL::Remove_AVL(Node *p, int key) // Returns a given root after removing a Node* by its key while abiding to AVL properties
{
  if (p == NULL)
  {
    return p;
  }
  if (key < p->Get_key())
  {
    p->Set_left(Remove(p->Get_left(), key));
  }
  else if (key > p->Get_key())
  {
    p->Set_right(Remove(p->Get_right(), key));
  }
  else
  {
    if (p->Get_left() == NULL || p->Get_right() == NULL)
    {
      Node *temp = (p->Get_left()) ? p->Get_left() : p->Get_right();
      if (temp == NULL)
      {
        temp = p;
        p = NULL;
      }
      else
      {
        *p = *temp;
      }
      delete temp;
    }
    else
    {
      Node *temp = Min(p->Get_right());
      p->Set_key(temp->Get_key());
      p->Set_right(Remove(p->Get_right(), temp->Get_key()));
    }
  }
  if (p == NULL)
  {
    return p;
  }

  int balance = balanceFactor(p);

  if (balance > 1 && balanceFactor(p->Get_left()) >= 0)
  {
    return Rotate_cw(p);
  }
  if (balance > 1 && balanceFactor(p->Get_left()) < 0)
  {
    p->Set_left(Rotate_cc(p->Get_left()));
    return Rotate_cw(p);
  }
  if (balance < -1 && balanceFactor(p->Get_right()) <= 0)
  {
    return Rotate_cc(p);
  }
  if (balance < -1 && balanceFactor(p->Get_right()) > 0)
  {
    p->Set_right(Rotate_cw(p->Get_right()));
    return Rotate_cc(p);
  }

  return p;
}
void AVL::Remove_AVL(int key) // Returns the root after removing a Node* by its key while abiding to AVL properties
{
  root = Remove_AVL(root, key);
}
int AVL::Height(Node *p) // Returns the height of the tree by a given root
{
  if (p == NULL || p->Get_key() == 0)
  {
    return -1;
  }
  else
  {
    int leftHeight = Height(p->Get_left());
    int rightHeight = Height(p->Get_right());
    return 1 + std::max(leftHeight, rightHeight);
  }
}
Node *AVL::Rotate_cw(Node *p) // Returns the new root of the subtree after rotating clockwise
{
  Node *a = p->Get_left();
  Node *b = a->Get_right();

  a->Set_right(p);
  p->Set_left(b);

  return a;
}
Node *AVL::Rotate_cc(Node *p) // Returns the new root of the subtree after rotating counterclockwise
{
  Node *a = p->Get_right();
  Node *b = a->Get_left();

  a->Set_left(p);
  p->Set_right(b);

  return a;
}
int AVL::balanceFactor(Node *p) // Returns the difference in heights of the the two subtrees of a given root
{
  if (p == NULL)
  {
    return 0;
  }
  return Height(p->Get_left()) - Height(p->Get_right());
}
AVL::AVL() // Initializes the root to NULL
{
  root = NULL;
}
// --------------
// Main Function
// --------------
int main()
{
  // mode_test: indicate which function to test
  // model_avl: if 1, we do adding with AVL property
  // if 0, we do adding without AVL property
  // (so just standard bst adding)
  // key_temp: keys of nodes to add to AVL initially
  // key_search:key of node for search/remove
  int mode_test, mode_avl, key_temp, key_search;
  Node *temp;
  // This is our AVL tree object.
  AVL tree;
  cin >> mode_test >> mode_avl >> key_search;
  while (cin >> key_temp)
  {
    temp = new Node;
    temp->Set_key(key_temp);
    if (mode_avl == 0)
    {
      tree.Add(temp);
    }
    else if (mode_avl == 1)
    {
      tree.Add_AVL(temp);
    }
  }
  // Mode 0: test "Add" function.
  if (mode_test == 0)
  {
    tree.PreTraverse();
  }
  // Mode 1: test "Add_AVL" function
  else if (mode_test == 1)
  {
    tree.PreTraverse();
  }
  // Mode 2: test "Search" function
  else if (mode_test == 2)
  {
    temp = tree.Search(key_search);
    if (temp == NULL)
    {
      cout << -1;
    }
    else
    {
      cout << temp->Get_key();
    }
  }
  // Mode 3: test "Remove" function
  else if (mode_test == 3)
  {
    tree.Remove(key_search);
    tree.PreTraverse();
  }
  // Mode 4: test "Remove_AVL" function
  else if (mode_test == 4)
  {
    tree.Remove_AVL(key_search);
    tree.PreTraverse();
  }
  // Mode 5: test "Height" function
  else if (mode_test == 5)
  {
    cout << tree.Height(tree.GetRoot());
  }
  return 0;
}
