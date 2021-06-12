#include <iostream>
#include <string>

using namespace std;

class Test
{
  int id;
  string name;
public:
  Test():id(0), name("")
  {}
  Test(int id, string name):id(id), name(name)
  {}
  // const need to be declared as refernce passed
  // to overloaded function is const
  int getid() const
  {
    return id;
  }
  string getname() const
  {
    return name;
  }
  // using friend function here cause , we need access to private variables of this class
  // which can only be done using friend keyword.
  // if there are setters abd getters, we can define this function outside
  // without friend keyword
  /*
  friend ostream &operator<<(ostream &out,const Test &test)
  {
    out << test.id << " : "<<test.name;
    return out;
  }
  */
};


// if getters are available we can do this way too
ostream &operator<<(ostream &out,const Test &test)
  {
    out << test.getid() << " : "<<test.getname();
    return out;
  }


int main()
{
  Test test1(111, "Alex");
  Test test2(222, "Brad");

  cout<<test1<<endl;

  cout<< test1 << " " << test2 <<endl;

  return 0;
}