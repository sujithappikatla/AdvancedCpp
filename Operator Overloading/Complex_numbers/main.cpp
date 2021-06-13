#include "Complex.h"

int main()
{
  // default constructor
  COMPLEX_NUM c1;
  cout << c1 << endl;
  // parameterizes constructor
  COMPLEX_NUM c2(2,4);
  cout<< c2 <<endl;
  // Assignment operator
  c1 = c2;
  cout<< c1 <<endl;
  // + operator overloaded
  COMPLEX_NUM c3;
  c3 = c1 + c2;
  cout << c3 <<endl;
  // * operator overloaded
  cout << *c3 <<endl;

  return 0;
}