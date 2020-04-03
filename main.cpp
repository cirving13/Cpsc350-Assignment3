#include "Finder.h"

int main(int argc, char **argv)
{
  GenStack<char> stack; //doesnt work if inside the try statement, idk why
  try
  {
    Finder find;
    char choice = 'y';
    while(choice == 'y')
    {
      find.syntaxCheck(); //completes everything
      cout << "Do you want to check another file? (y or n) " << endl;
      cin >> choice;
    }
  }
  //error catching
  catch(EmptyStackException e)
  {
    cout << e.what() << endl;
  }
  catch(FileNotFoundException e)
  {
    cout << e.what() << endl;
  }
  stack.~GenStack();
  exit(0);
  return 0;
}
