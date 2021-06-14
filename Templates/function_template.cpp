#include <iostream>

using namespace std;

template<class T>
T add(T num1, T num2)
{
  cout<<"Template Function --> "<<num1<<" + "<<num2<<" : ";
  return num1 + num2;
}

// when int datatype is used this function is given priority
// unless template function with int specifier used, in which case template function called 
int add(int num1, int num2)
{
  cout<<"Normal Function --> "<<num1<<" + "<<num2<<" : ";
  return num1+num2;
}

int main()
{
  // template function usage
  cout<< add<int>(2,3) <<endl;
  cout<< add<double>(2.2, 3.2) <<endl;
  // specified int but passed double, internally typecasted to int
  cout<< add<int>(2.2, 3.2) <<endl;
  cout<< add<string>("Hell ", "World!!") <<endl;

  // function called without any template specifier, still works
  cout<< add(2.2,3.0) <<endl;

  // int datatypes passed without template definition, so normal function is given
  // high priority
  cout<< add(2,3) <<endl;
  return 0;
}