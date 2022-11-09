#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

// UTILITY FUNCTIONS

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

bool isUppercase(char c) {
  if ((65 <= c) && (c <= 90)) {
    return true;
  }
  return false;
}

char getSecondChar(string s) {
  return s[2];
}

char makeUppercase(char c) {
  if (isLowercase(c)) {
    c = char (c - 32);
  }
  return c;
}

char makeLowercase(char c) {
  if (isUppercase(c)) {
    c = char (c + 32);
  }
  return c;
}

string stripFirstFour(string input) {
  input.erase(0, 4);
  return input;
}

string stripLastTwo(string input) {
  input.erase(input.end() - 2, input.end());
    return input;
}

string stripLeadingSpaces(string input) {
  int index = 0;
  while (input[index] == ' ') {index++;}
  return input.substr(index);
}

string deleteRunningSpaces(string input, int index) {
  while (input[index] == ' ') {
    input.erase(index, 1);
  }
  return input;
}

string deleteSpacesAndMakeUppercase(string input) {
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == ' ') {
	  input = deleteRunningSpaces(input, i);
      input[i] = makeUppercase(input[i]);
    }
  }
  return input;
}

string addSpacesBeforeUppercase(string input) {
  for (int i = 1; i < input.size(); i++) {
    if (isUppercase(input[i])) {
      input = input.insert(i, " ");
      i++;
    }
  }
  return input;
}

string makeAllLowercase(string input) {
  for (int i = 0; i < input.size(); i++) {
      input[i] = makeLowercase(input[i]);
  }
  return input;
}

string makeFirstLetterUppercase(string input) {
  input[0] = makeUppercase(input[0]);
  return input;
}

string makeFirstLetterLowercase(string input) {
  input[0] = makeLowercase(input[0]);
  return input;
}

string splitName(string input) {
  if (isMethod(input)) {
    input = stripLastTwo(input);
  }
  input = stripFirstFour(input);
  input = makeFirstLetterLowercase(input);
  input = addSpacesBeforeUppercase(input);
  input = makeAllLowercase(input);

  return input;
}

// CLASSES

class MethodName {
  public:
    string name;

    MethodName(string input) {
      name = input;
    }

    void combineMethodName() {
      name = stripFirstFour(name);
	  name = stripLeadingSpaces(name);
      name = deleteSpacesAndMakeUppercase(name);
      name += "()";
    }
};

class ClassName {
  public:
    string name;

    ClassName(string input) {
      name = input;
    }

    void combineClassName() {
      name = stripFirstFour(name);
	  name = stripLeadingSpaces(name);
      name = makeFirstLetterUppercase(name);
      name = deleteSpacesAndMakeUppercase(name);
    }
};

class VariableName {
  public:
    string name;

    VariableName(string input) {
      name = input;
    }

    void combineVariableName() {
      name = stripFirstFour(name);
	  name = stripLeadingSpaces(name);
      name = deleteSpacesAndMakeUppercase(name);
    }
};

// ---MAIN---

int main() {
	
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
		cout << methods.back().name << endl;
      }
      else if (isClass(input)) {
        classes.push_back(ClassName(input));
        classes.back().combineClassName();
		cout << classes.back().name << endl;
      }
      else if (isVariable(input)) {
        variables.push_back(VariableName(input));
        variables.back().combineVariableName();
		cout << variables.back().name << endl;
      }
      else {cout << "Error1\n";}
    }
  } while (input != "exit");

  cout << "program terminated" << endl;
  return 0;
}