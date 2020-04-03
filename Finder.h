#include <iostream>
#include <fstream>
#include "GenStack.h"
#include "FileNotFoundException.h"
using namespace std;

class Finder
{
public:
  //the only method
  void syntaxCheck();
  //some variable stuff
  string fileName;
  char first;

private:
  int line;
};
