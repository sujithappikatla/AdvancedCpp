#include <iostream>
#include <fstream>

using namespace std;

// structures  when allocated memory will sumup to 4(int size) multiples
// for example below struct created has size 18+4+8 = 30 but 32 bytes will be allocated
// to prevent thid from happening use pack(push, [smallest_size_to_padding])
#pragma pack(push,1)

struct PERSON{
  char name[18];
  int age;
  double height;
};

// after padding if we dont want to use anymore for further structures,
// we revert back to default 4 size
#pragma pop()

int main()
{
  PERSON person1 = {"spidy", 24, 0.76};

  string fileName = "test.bin";

  // when created instance of fstream, need to specifcally say read/write while opening
  // file like in/out
  fstream outFile;
  outFile.open(fileName, ios::binary | ios::out);
  if(outFile.is_open())
  {
    // while writing strcutures to file, first get pointer of that struct and
    // cast to char * and provide size of strcut for writing to file
    outFile.write(reinterpret_cast<char *>(&person1), sizeof(PERSON));
    outFile.close();
  }

  // Reading Data

  PERSON person2 = {};

  // no need specify in/out as this is ifstream
  ifstream inFile;
  inFile.open(fileName, ios::binary);
  if(inFile.is_open())
  {
    inFile.read(reinterpret_cast<char *>(&person2), sizeof(PERSON));
    inFile.close();
  }
  cout<<person2.name<<" "<<person2.age<<" "<<person2.height<<endl;

}