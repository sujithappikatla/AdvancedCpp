#include <iostream>
#include <list>

using namespace std;

int main()
{
  list<int> years;

  years.push_back(1996);
  years.push_back(2000);
  years.push_back(2021);
  years.push_back(1990);

  cout<<"Iterating through values of list.."<< endl;
  for(list<int>::iterator itr = years.begin() ; itr!=years.end() ; itr++)
    cout<<*itr<<endl;

  cout<<endl;
  /////////////////  insert()
  list<int>::iterator insertitr = years.begin();
  insertitr++;
  cout<<"insertitr points current on second element of list : "<<*insertitr<<endl;

  // insert() will insert new value to list before value pointed by iterator
  years.insert(insertitr, 2007);
  cout<<"Iterating through values of list.."<< endl;
  for(list<int>::iterator itr = years.begin() ; itr!=years.end() ; itr++)
    cout<<*itr<<endl;

  /////////////////////

  cout<<endl;
  /////////////////  erase()
  list<int>::iterator eraseitr = years.end();
  eraseitr--;
  cout<<"ErasePtr points current on second last element of list : "<<*eraseitr<<endl;
  // erase() function removes value passed by iterator from list
  // and returns next element in list. If no next element in list ::end() is returned
  eraseitr = years.erase(eraseitr);
  if(eraseitr==years.end())
    cout<<"end() of list"<<endl;

  /////////////////////


  return 0;
}