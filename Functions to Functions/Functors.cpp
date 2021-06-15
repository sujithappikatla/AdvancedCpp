#include <iostream>

using namespace std;

struct Test
{
  virtual bool operator()(string &text) = 0;
};

struct MatchTest : public Test
{
  bool operator()(string &text)
  {
    return text=="match";
  }
};

void check(string text,Test &t)
{
  if(t(text))
  {
    cout<<"Its a match"<<endl;
  }
  else
  {
    cout<<"Not a match"<<endl;
  }
}

int main()
{
  string mat = "match";
  string not_mat = "not_match";
  MatchTest m ;
  // eventhough calling same way as function pointer, this is not
  // function pointer. its calling () overloaded function, which basically
  // is functor
  cout<< m(mat) <<endl;

  check(mat, m);
  check(not_mat, m);

  return 0;
}