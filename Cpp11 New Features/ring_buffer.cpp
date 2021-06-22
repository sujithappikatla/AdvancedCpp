#include<iostream>

using namespace std;

template <typename T>
class ring
{
private:
  T* m_arr;
  int m_size;
  int m_pos;
public:
  class iterator;

public:
  ring(int size):m_size(size), m_arr(nullptr), m_pos(0)
  {
    m_arr = new T[m_size];
  }
  ~ring()
  {
    delete [] m_arr;
  }
  void add(T value)
  {
    m_arr[m_pos%m_size] = value;
    m_pos++;
  }
  T &get(int ind)
  {
    return m_arr[ind];
  }
  int size()
  {
    if(m_pos > m_size)
      return m_size;
    return m_pos;
  }

  iterator begin()
  {
    return iterator(0, *this);
  }
  iterator end()
  {
    return iterator(m_size, *this);
  }

};

template<typename T>
class ring<T>::iterator
{
private:
  int m_pos;
  ring &m_r;
public:
  iterator(int pos, ring& r): m_pos(pos), m_r(r)
  {
  }
  bool operator!=(const iterator& other) const
  {
    return m_pos!=other.m_pos;
  }
  // postfix operator overload
  iterator& operator++(int)
  {
    m_pos++;
    return *this;
  }
  // prefic operator overload
  iterator& operator++()
  {
    m_pos++;
    return *this;
  }
  T& operator*()
  {
    return m_r.get(m_pos);
  }


};

int main()
{
  ring<string> r(3);
  r.add("One");
  r.add("Two");
  r.add("Three");
  r.add("Four");

  for(int i=0;i<r.size();i++)
    cout<<r.get(i)<<endl;
  
  cout<<endl;

  for(ring<string>::iterator itr = r.begin(); itr!=r.end(); itr++)
    cout<<*itr<<endl;

  cout<<endl;

  for(auto val:r)
    cout<< val<<endl;

  cout<<endl;

}