#include "Complex.h"

COMPLEX_NUM::COMPLEX_NUM():real(0), imaginary(0)
{
  cout<<"Default Constructor"<<endl;
}

COMPLEX_NUM::COMPLEX_NUM(double real, double imaginary): real(real), imaginary(imaginary)
{
  cout<<"Constructor with parameters"<<endl;
}

COMPLEX_NUM::COMPLEX_NUM(const COMPLEX_NUM& other)
{
  cout<<"Copy COntructor called"<<endl;
  real = other.real;
  imaginary = other.imaginary;
}  

COMPLEX_NUM &COMPLEX_NUM::operator=(const COMPLEX_NUM& other)
{
  cout<<"Assignment Operator called"<<endl;
  real = other.real;
  imaginary = other.imaginary;
}

COMPLEX_NUM operator+(const COMPLEX_NUM& c1, const COMPLEX_NUM& c2)
{
  return COMPLEX_NUM(c1.getreal()+c2.getreal(), c1.getimaginary()+c2.getimaginary());
}

ostream &operator<<(ostream& out, const COMPLEX_NUM& c)
{
  cout<<c.getreal()<<"i + "<<c.getimaginary();
  return out;
}

double operator*(const COMPLEX_NUM& c)
{
  return c.getreal();
}