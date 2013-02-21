//Author: Stephen Pryor
//A simple program for testing the bs_tree.cpp file.

#include <iostream>
#include <stdlib.h>
#include "bs_tree.cpp"

using namespace std;

void print(string msg) {
  cout << msg << endl;
}

int main()
{
  bs_tree<int> * myTree = new bs_tree<int>();
  string action;
  int value;
  cout << "The list is currently empty." << endl; 
  cout << ">> ";
  cin >> action;
  while(action != "quit" && action != "end" && action != "exit" && action != "stop")
  {      
    if(!(cin >> value)) // check for invalid types
    {
      cin.sync(); 
      cin.clear(); 
      cout << "Error: Type incorrect, expected an integer." << endl;
    }
    else
    {
      system("cls");
      if(action == "add" || action == "insert")
      {
        myTree->insert(value);
      } else if(action == "delete" || action == "del" || action == "remove") {
        myTree->remove(value);
      }
      if(action == "find" || action == "search") {
        if(myTree->search(value)){
          cout << "Found " << value << endl; 
        }else{
          cout << value << " not found" << endl; 
        }
      } else {
        if(myTree->empty()){
          cout << "It's empty" << endl; 
        }
        else
        {
          cout << "Size: " << myTree->size() << endl; 
          myTree->print_inorder();
        }
      } 
    }      
    cout << ">> ";
    cin >> action;
  }
  
  return 0;
}
