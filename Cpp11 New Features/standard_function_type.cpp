#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>

using namespace std;

bool func(string &name)
{
  return name.length() == 3;
}

// class with operator () overloaded 
class classFunctor
{
public:
  bool operator()(string &name)
  {
    return name.length() == 5;
  }
}classcheck; // can call directly with this name

// function from <functional> is a standard function type
void common(function<bool(string &)> ptr)
{
  string str = "six";
  cout << ptr(str) <<endl;
}

int main()
{
  int size = 5;
  vector<string> names{"one", "two", "three"}; // Initalizing values using initialization lists concept of cpp11

  // adding mutable to lambda function can make us use catch variables as function parameters
  // just by value
  [size]() mutable {
    size = 8;
    cout << "size : " << size <<endl;
  }();

  cout << "size : " << size <<endl;

  // lambda statement
  auto lambda = [size](string &name){
    return name.length() == size;
  };

  // count_if algo takes iterators and function ptr 
  // passing lambda function as comparision condition of count if
  int count = count_if(names.begin(), names.end(), lambda);
  cout<< count <<endl;

  count = count_if(names.begin(), names.end(), func);
  cout<< count <<endl;

  count = count_if(names.begin(), names.end(), classcheck);
  cout<< count <<endl;

  // passing lamdba function , normal function, class functor to function<> standard type
  common(lambda);
  common(func);
  common(classcheck);

  return 0;
}
