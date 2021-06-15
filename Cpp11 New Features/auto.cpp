#include <iostream>
#include <typeinfo>
using namespace std;

template <class T, class S>
auto test(T val1, S val2) 
{
  return val1+val2;
}

string getstring()
{
  return "hay";
}

auto test2() 
{
  return getstring();
}

int main()
{
  auto value = 7;
  auto text = "Hello";

  cout << test(2,2.3) <<endl;

  auto new_var = test2();

  cout<< typeid(new_var).name()<<endl;

  return 0;
}