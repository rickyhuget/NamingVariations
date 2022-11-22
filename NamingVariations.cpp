#include "Name.h"
#include "library.h"
#include <vector>
#include <iostream>
#include <string>
using namespace std;

int main() {
  vector<Name> names;
  vector<string> sentences;
  string input;

  do {
    getline(cin, input);

    if (input == "exit") {
      break;
    }
  
    if (splitCommand(input)) {
      splitName(input);
      sentences.push_back(input);
      cout << sentences.back() << endl;
    }
    else if (combineCommand(input)) {
      names.push_back(Name(input, input[2]));
      names.back().createName();
      names.back().printName();
    }
    else { cout << "Incorrect input. Try again." << endl; }
    
  } while (input != "exit");

  exitMessage();
  return 0;
}
