#include <iostream>
#include <string>

using namespace std;

struct Test
{
  string name;
  int age;
  Test():name(""), age(0) {}
  Test(string name, int age):name(name), age(age) {}

  void print()
  {
    cout<<"Name : "<<name<<" Age : "<<age<<endl;
  }
  // = operator overloaded
  // this called when one object assigned to other
  const Test& operator=(const Test& other)
  {
    cout << "Assignment operator running"<< endl;
    name = other.name;
    age = other.age;
    // after assigning return reference so that refernce can be used in chaining 
    return *this;
  }
  // copy construtor called when intializing variable with other object
  Test(const Test& other)
  {
    cout << "Copy constructor called"<< endl;
    // This line will called above operator overloaded function
    *this = other;
  }

};

int main()
{
  Test test1("Suzy", 28);
  Test test2("Somi", 22);

  // this calls Assignment overloaded function
  test2 = test1;
  test2.print();

  // This calls copy constructor
  Test test3 = test1;
  test3.print();

  Test test4("Scar", 30);

  // assignment overloaded function called.
  // refernce returned in this function is for this chaining feature
  test1 = test2 = test3 = test4;

  cout<<"Printing after chaining"<< endl;
  test1.print();
  test2.print();
  test3.print();
  test4.print();


}