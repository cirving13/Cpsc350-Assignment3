#include "Finder.h"

int main(int argc, char **argv)
{
  GenStack<char> stack; //doesnt work if inside the try statement, idk why
  try
  {
    Finder find;
    string name;
    if(argv[1]!=NULL)
    {
      name = argv[1];
      find.setFileName(name);
      find.syntaxCheck();
    }
    char choice = 'y';
    while(choice == 'y')
    {
      cout << "Do you want to check a file? (y or n) " << endl;
      cin >> choice;
      if(choice != 'y') //breaks loop if user makes any choice other than yes
      {
        break;
      }
      cout << "what is the name of the file you want checked? " << endl;
      cin >> name;
      find.setFileName(name);
      find.syntaxCheck(); //completes everything
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
