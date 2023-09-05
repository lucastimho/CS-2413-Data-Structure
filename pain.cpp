#include <iostream>
using namespace std;

int main()
{
  int z[3] = {1, 2, 3};
  int *p = z;

  for (int i = 0; i < 3; i++)
  {
    cout << *p++ << ' ';
  }

  for (int i = 0; i < 3; i++)
  {
    cout << *p-- << ' ';
  }

  for (int i = 0; i < 3; i++)
  {
    cout << ++p << ' ';
  }
  return 0;
}