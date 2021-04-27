#include <iostream>
#include <vector>

using namespace std;

struct NODE{
  string name;
  int age;
};

int main()
{
  // while vector creating need to mention type of data that vector going to hold
  // number of elements to hold is optional
  vector<NODE> v(3);
  // Vector elements can be accessed using array style index
  v[0].name = "john";
  v[0].age = 21;

  NODE p = {"alex", 19};

  v[1] = p;
  v[2] = p;

  v[2].age = 20;

  cout<<"Iterating vector using array style indices"<<endl;
  for(int i=0;i<v.size();i++)
    cout<<"#"<<i<<"  "<<v[i].name<<"  "<<v[i].age<<endl;

  cout<<endl;
  cout<<"Iterating vector using iterator"<<endl;
  for(vector<NODE>::iterator itr = v.begin() ; itr!=v.end() ; itr++)
    cout<<"#  "<<(*itr).name<<"   "<<(*itr).age<<endl;

  NODE new_node = {"lily", 23};
  // push_back method adds new element at end of vector
  // if exceeds current capicity vector automatically doubles size of array and copies all elements
  v.push_back(new_node);

  cout<<endl;
  cout<<"Added new node using puah_back"<<endl;
  for(vector<NODE>::iterator itr = v.begin() ; itr!=v.end() ; itr++)
    cout<<"#  "<<itr->name<<"   "<<itr->age<<endl;

  // size defines number of elements currently inserted to vector
  // capacity defines current captity of array
  cout<<endl<<"Size :"<<v.size()<<endl;
  cout<<"Capicity : "<<v.capacity()<<endl;

  v.reserve(10);
  cout<<endl<<"Size :"<<v.size()<<endl;
  cout<<"Capicity : "<<v.capacity()<<endl;

  // 2d vector with 3 rows and 4 colums
  vector< vector<NODE> > v2d(3, vector<NODE>(4));
  v2d[0][0] = v[0];
  v2d[1][1] = v[1];
  v2d[2][2] = v[2];

  cout<<endl;
  cout<<"Itearting 2d vector"<<endl;
  int i=0,j=0;
  for(vector< vector<NODE> >::iterator itr=v2d.begin(); itr!=v2d.end(); itr++)
  {
    j=0;
    for(vector< NODE >::iterator itr2 = itr->begin(); itr2!=itr->end(); itr2++ )
    {
      cout<<"["<<i<<"]["<<j<<"]  "<<itr2->name << "  "<<itr2->age<<endl;
      j++;
    }
    i++;
  }

}