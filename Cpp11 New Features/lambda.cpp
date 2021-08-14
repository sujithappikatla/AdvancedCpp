#include <iostream>

using namespace std;

// passing lamba function to parameter of function as function pointer
void Greet(void (*greet)(string) )
{
  greet("Tim");
}

// passing lamba function with return value to parameter of function as function pointer 
void Divide(double (*divide)(double, double))
{
  cout << divide(9,3) << endl;
}


class LambdaCatchTest{
private:
  int one{1}; // in cpp11 you can use initialization method {}, almost for evrything
  int two{2};
public:
  void run()
  {
    int three{3};
    int four{4};
    // you can capture local variables three, four by mentionig names in [], but not class variables one, two
    // for accessing class variables use 'this', which is refernce object
    auto ptr = [three, this, four](){
      this->one = 9;
      cout<< one << "," << two << "," << three << "," << four <<endl;

    };

    ptr();
  } 


};

int main()
{
  // Creating lamba function with parameter
  auto pGreet = [](string name){ cout<<"Hello "<<name<<endl;};

  // lambda function can be called directly like this
  pGreet("Bob");

  Greet(pGreet);

  // lambda function with return type."-> double" if not specified complier cant decide return type as int or double
  auto pDivide = [](double a, double b) -> double {
    if(b==0)
    {
      return 0; // return integer data type
    }
    return a/b; // returns double data type
  };

  cout<< pDivide(10.0,5.0) << endl;
  cout<< pDivide(10.0,0) << endl;

  Divide(pDivide);

  // Capturing varaibles in lambda function
  int one = 1;
  int two = 2;
  int three = 3;

  // can Call lambda directly by adding () at end
  [](){cout<<"heloo"<<endl;}();

  // Capturing variables by value
  [two, three](){ cout<<two<<","<< three <<endl; }();

  // capturing variables by reference
  [&one, two](){ one = 0; cout<<one<<","<<two<<endl;}();

  // capturing all variables by value, except three as reference
  [=, &three](){ three = 9; cout << one <<","<< two << "," << three <<endl; }();

  // capturing all variables by reference, except two by value
  [&, two](){ cout << one <<","<< two << "," << three <<endl; }();



  // Catching class variables in lambda functions
  LambdaCatchTest obj;
  obj.run();


  return 0;
}