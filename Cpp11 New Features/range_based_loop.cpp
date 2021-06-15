#include <iostream>
#include <vector>
using namespace std;


int main()
{
  // same as 
  // char texts[] = {"..", "..", ".."} --> from cpp11 no need for brackets
  // can also write
  // char texts = {"..", "..", ".."}
  auto texts = {"one", "two", "three"};

  for(auto text : texts)
    cout<< text <<endl;

  vector<int> numbers;
  numbers.push_back(5);
  numbers.push_back(2);
  numbers.push_back(9);

  for(auto num:numbers)
    cout<<num<<endl;

  string hello = "Hello";
  for(auto c:hello)
    cout<< c << endl;
  
  return 0;
}