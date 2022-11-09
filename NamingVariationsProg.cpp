#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// UTILITY FUNCTIONS

char getSecondChar(string s) {
  return s[2];
}

string stripFirstFour(string input) {
  input.erase(0, 4);
  return input;
}

string stripParentheses(string input) {
  input.erase(input.end() - 2, input.end());
    return input;
}

// utility functions, bool

bool isSplit(string input) {
  if (input[0] == 'S') {
    return true;
  }
    return false;
}

bool isMethod(string input) {
  if (input[2] == 'M') {
    return true;
  }
    return false;
}

bool isClass(string input) {
  if (input[2] == 'C') {
    return true;
  }
    return false;
}

bool isVariable(string input) {
  if (input[2] == 'V') {
    return true;
  }
    return false;
}

bool isLowercase(char c) {
  if ((97 <= c) && (c <= 122)) {
    return true;
  }
  return false;
}

string makeUppercase(string input, int index) {
  if (isLowercase(input[index])) {
    input[index] = char (input[index] - 32);
  }
  return input;
}

string deleteSpacesAndMakeUppercase(string input) {
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == ' ') {
      input.erase(i, 1);
      input = makeUppercase(input, i);
    }
  }
  return input;
}

bool isUppercase(char c) {
  if ((65 <= c) && (c <= 90)) {
    return true;
  }
  return false;
}

string addSpaces(string input) {
  for (int i = 1; i < input.size(); i++) {
    if (isUppercase(input[i])) {
      input = input.insert(i, " "); // at position i, insert a space
      i++;
    }
  }
  return input;
}

char makeLowercase(char c) {
  if (isUppercase(c)) {
    c = char (c + 32);
  }
  return c;
}

string makeAllLowercase(string input) {
  for (int i = 0; i < input.size(); i++) {
      input[i] = makeLowercase(input[i]);
  }
  return input;
}

string makeFirstLettersUppercase(string input) {
  input = makeUppercase(input, 0);
  return input;
}

string makeFirstLettersLowercase(string input) {
  input[0] = makeLowercase(input[0]);
  return input;
}

string splitName(string input) {
  if (isMethod(input)) {
    input = stripParentheses(input);
  }
  input = stripFirstFour(input);
  input = makeFirstLettersLowercase(input);
  input = addSpaces(input);
  input = makeAllLowercase(input);

  return input;
}

void printName(string name) {
  cout << name << endl;
}

class Name {

};

class MethodName: public Name {
  public:
    string name;

    MethodName(string input) {
      name = input;
    }

    void combineMethodName() {
      name = stripFirstFour(name);
      name = deleteSpacesAndMakeUppercase(name);
      name += "()";
    }
};

class ClassName: public Name {
  public:
    string name;

    ClassName(string input) {
      name = input;
    }

    void combineClassName() {
      name = stripFirstFour(name);
      name = makeFirstLettersUppercase(name);
      name = deleteSpacesAndMakeUppercase(name);
    }
};

class VariableName: public Name {
  public:
    string name;

    VariableName(string input) {
      name = input;
    }

    void combineVariableName() {
      name = stripFirstFour(name);
      name = deleteSpacesAndMakeUppercase(name);
    }
};

int main() {

  //vector<Name> names;
  vector<MethodName> methods;
  vector<ClassName> classes;
  vector<VariableName> variables;
  vector<string> splitNames;
  string input;

  do {
    getline(cin, input);
  
    if (isSplit(input)) {
      input = splitName(input);
      splitNames.push_back(input);
      cout << splitNames.back() << endl;
    }
    else {
      if (input == "exit") {
        break;
      }
      else if (isMethod(input)) {
        methods.push_back(MethodName(input));
        methods.back().combineMethodName();
        printName(methods.back().name);
      }
      else if (isClass(input)) {
        classes.push_back(ClassName(input));
        classes.back().combineClassName();
        printName(classes.back().name);
      }
      else if (isVariable(input)) {
        variables.push_back(VariableName(input));
        variables.back().combineVariableName();
        printName(variables.back().name);
      }
      else {cout << "Error1\n";}
    }
  } while (input != "exit");

  cout << "program terminated" << endl;
  return 0;
}