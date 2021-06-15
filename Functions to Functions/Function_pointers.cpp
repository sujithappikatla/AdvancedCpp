#include <iostream>
#define INFO 0
#define DEBUG 1
#define ERROR 2

using namespace std;

void info_logger(string text)
{
  cout<<"INFO LOG : " << text <<endl;
}

void error_logger(string text)
{
  cout<<"ERROR LOG : " << text << endl;
}

// second argument is function pointer  
// syntax - return_type (*function_name)(parameters...)
void log(string text, void (*logger)(string))
{
  logger(text);
}

int main()
{
  log("Download Fail", error_logger);

  log("Download Succeed", info_logger);

  return 0;
}