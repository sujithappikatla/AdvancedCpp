#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
  string var1="value";
  cout<<"Variable : var1 , Type : "<< typeid(var1).name() << " Value : "<<var1<<endl;

  // decltype creates new variables with datatype of variable passed as parameter 
  // to function
  decltype(var1) var2;
  var2 = "new_value";
  cout<<"Variable : var2 , Type : "<< typeid(var2).name() << " Value : "<<var2<<endl;

  return 0;
}