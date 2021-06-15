#include <iostream>
#include <typeinfo>
using namespace std;

class new_data_type
{

};

int main()
{
  int value1;
  // cpp11 maps each datatype with certain string, which can be printed using
  // typeid
  cout<< typeid(value1).name()<<endl;

  double value2;
  cout<< typeid(value2).name()<<endl;

  string value3;
  cout<< typeid(value3).name()<<endl;

  new_data_type value4;
  cout<< typeid(value4).name()<<endl;

  return 0;
}
