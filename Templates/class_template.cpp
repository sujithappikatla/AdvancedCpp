#include <iostream>
#include <string>

using namespace std;

// while compiling different classes for different datatypes are created
// depending on data types used in code.
// multiple data types can be passed like <class T1. class T2,..>
template<class T>
class Test
{
  T param1;
  T param2;
  public:
  Test(T p1, T p2): param1(p1), param2(p2)
  {}
  void add()
  {
    cout<<param1 + param2 <<endl;
  }
};

int main()
{
  // template class of int datatype
  Test<int> t1(2,3);
  t1.add();
  // template class of double datatype
  Test<double> t2(2.3,3.3);
  t2.add();
  // template class of string datatype
  Test<string> t3("new"," world");
  t3.add();

  return 0;
}