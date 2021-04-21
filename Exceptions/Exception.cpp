#include <iostream>

using namespace std;

// "exception" is parent class for all other inbuilt exceptions
// "exception" has what method which can be used to get text description of thrown exception
// Custom class inheriting exception and defining what method
class MyException:public exception{
public:
  virtual const char* what() const throw(){
    return "My Custom Exception";
  }
};

// function used to simulate exception throwing
void goneWrong()
{
  bool val = false;
  bool val2 = true;
  if(val)
    throw MyException();
  if(val2)
    throw bad_alloc();
}

int main()
{
  try{
    goneWrong();
  }
  catch(char* e)
  {
    cout<<"Exception code : "<<e<<endl;
  }
  // type of exception order plays role in catch statments
  // if parent class "exception" is catched before all other child exception types, then parent "eception" catch will be executed.
  catch(MyException &e)
  {
    cout<<"Exception : "<<e.what()<<endl;
  }
  catch(exception &e)
  {
    cout<<"Ëxception caught by parent class : "<<e.what()<<endl;
  }

  cout<<"IS running "<<endl;
  return 0;
}