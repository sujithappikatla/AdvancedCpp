#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class COMPLEX_NUM
{
  double real;
  double imaginary;
public:
  COMPLEX_NUM();
  COMPLEX_NUM(double real, double imaginary);
  // copy constructor
  COMPLEX_NUM(const COMPLEX_NUM& other);
  // = operator overloaded
  COMPLEX_NUM &operator=(const COMPLEX_NUM& other);
  
  // getters
  double getreal() const { return real; }
  double getimaginary() const { return imaginary; }
};

// + operator overloaded
COMPLEX_NUM operator+(const COMPLEX_NUM& c1, const COMPLEX_NUM& c2);
// << operator overloaded
ostream &operator<<(ostream& c1, const COMPLEX_NUM& c);
// * operator overloaded
double operator*(const COMPLEX_NUM& c);

#endif