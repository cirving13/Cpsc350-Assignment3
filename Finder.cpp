#include "Finder.h"

void Finder::syntaxCheck()
{
  cout << "what is the name of the file you want checked? " << endl;
  cin >> fileName;
  GenStack<char> stack;
  ifstream inFile;
  inFile.open(fileName);
  char c;
  int line = 1;

  if(!inFile)
  {
    throw FileNotFoundException();
  }
  while(!inFile.eof())
  {
    inFile >> noskipws >> c;
    if(c == '{' || c == '[' || c == '(') //loads all the opening delimiters into the stack
    {
      stack.push(c); //adds the opening values to the stack
    }
    else if(c == '\n') //increases line number to output to screen error location
    {
      ++line;
    }
    else if (c == '}' || c == ']' || c == ')') //checks if the delimiter at the top of the stack to see if it is the same as the closing delimiter
    {                                          //if not, then there is an error in the code
      first = stack.topStack(); //gets the top of the stack to compare with the closing delimiter read
      if(stack.isEmpty())
      {
        cout << "Nothing in the stack" << endl;
        throw EmptyStackException();
      }
      if (first == '{' && c != '}')
      {
        cout << "On line " << line << ": expected } and found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      else if (first == '[' && c != ']')
      {
        cout << "On line " << line << ": expected ] and found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      else if (first == '(' && c != ')')
      {
        cout << "On line " << line << ": expected ) and found " << c << endl;
        stack.~GenStack();
        exit(0);
      }
      stack.pop(); //removes the opening delimiter tested and continues on with the code
    }
  }
  inFile.close();
  if(stack.isEmpty()) //finished the code all the way, will continue the loop
  {
    cout << "there are no errors in the code" << endl;
  }
  else if(!stack.isEmpty()) //each situation of an end of file error
  {
    first = stack.topStack(); //needed to be redefined here because it wont read if there are 0 closing delimiters
    if(first == '{')
    {
      cout << "end of file reached, expected }" << endl;
      exit(0);
    }
    else if(first == '(')
    {
      cout << "end of file reached, expected )" << endl;
      exit(0);
    }
    else if(first == '[')
    {
      cout << "end of file reached, expected ]" << endl;
      exit(0);
    }
  }
}
