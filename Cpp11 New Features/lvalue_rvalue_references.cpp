#include <iostream>

using namespace std;

class Test
{
public:
  Test()
  {
    cout<<"No parameter Constructor"<<endl;
  }
  Test(int i)
  {
    cout<<"Parameterized Constructor" <<endl;
  }
  Test(const Test& other)
  {
    cout<<"Copy Constructor"<<endl;
  }
  Test& operator=(const Test& other)
  {
    cout<<"Assignment operator"<<endl;
    return *this;
  }
  ~Test()
  {
    cout<<"destructor Called"<<endl;
  }
};

Test newTest()
{
  return Test();
}

// lvalue reference
void check(const Test& val)
{
  cout<<"lvalue refernce called"<<endl;
}

// rvalue refernce
void check(Test&& val)
{
  cout<<"rvalue refernce called"<<endl;
}


// lvalue reference
void check(int& val)
{
  cout<<"lvalue refernce called"<<endl;
}

// rvalue refernce
void check(int&& val)
{
  cout<<"rvalue refernce called"<<endl;
}

int main()
{
  {
    Test test1 = newTest();

    // lvalue - variables which are usally on left side of expression, vraiable which holds something
    // This function calls lvalue refernce as test1 passed is lvalue
    check(test1);
    // rvalue - which are temporary values, which usally on rigth side of expressions, 
    // newTest() retuns temporary value, which is rvalue
    // Test() also returns rvalue 
    check(newTest());
    check(Test());
  }
  cout<<endl<<"$$$$$$$$$$$$$$$$$$$$$$$$$"<<endl<<endl;

  {
    int value = 5;
    // value is lvalue, so lvalue refernce parameter function called
    check(value);
    // 5 is temp rvalue variable, so rvalue refernce paramter function called
    check(5);

    // ++value increases value of variable value and that variable value is used, so lvaue is considered
    check(++value);
    // value++ returns temp rvalue constant and then increments variable value, so rvalue function called
    check(value++);
  }

  return 0;
}