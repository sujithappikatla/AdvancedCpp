#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person
{
  string name;
  int age;
  public:
  // Default constructor with no parameters need to be defined, when used with maps
  // cause maps creates object internally using default constructor with no parameters
  // and assign object we passed to this internal object
  Person(){}
  Person(string name, int age): name(name), age(age)
  {}
  // const should be used cause for maps when object is used as keys, all functions should be const so that  
  // variables wont be changed while in map
  void print() const{
    cout<<"Name : "<<name<<" Age : "<<age << flush;
  }
  // < operator overloading is necessary cause when objects passed as keys to maps
  // that object must have a method for sorting . Maps sort using < operator.
  // so overloading this operator is necessary
  // This functions also says 
  bool operator<(const Person& other) const
  {
    return name < other.name;
  }
};

int main()
{
  map<int, Person> people;
  people[28] = Person("Suzy", 28);
  people[22] = Person("Somi", 22);
  people[30] = Person("Scar", 30);

  // All entries which are added to map are sorted automatically.
  cout<<endl<< "Iterating through map "<<endl;
  for(map<int, Person>::iterator itr = people.begin(); itr!=people.end(); itr++)
  {
    cout<<"Key : "<<itr->first<<" ";
    itr->second.print();
    cout<<endl;
  }

  // assigning using existing key will replace data of that key
  people[30] = Person("Scar Junior", 30);

  cout<<endl<< "Iterating through map After replacing "<<endl;
  for(map<int, Person>::iterator itr = people.begin(); itr!=people.end(); itr++)
  {
    cout<<"Key : "<<itr->first<<" "; 
    itr->second.print();
    cout<<endl;
  }

  // Now passing onjects as keys to map
  // if same onject is again used as key new entry will not be added, just data modifies
  map<Person, string> address;
  address[Person("Suzy", 28)] = "South korea";
  address[Person("Somi", 22)] = "Canada";
  address[Person("Scar", 30)] = "Japan";

  cout<<endl<< "Iterating through map with onjects as keys "<<endl;
  for(map<Person, string>::iterator itr = address.begin(); itr!=address.end(); itr++)
  {
    itr->first.print();
    cout<<" Data : "<<itr->second;
    cout<<endl;
  }

}