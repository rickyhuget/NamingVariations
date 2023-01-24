#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <string>
using namespace std;

bool splitCommand(string s) {
  return (s[0] == 'S' || s[0] == 's');
}

bool combineCommand(string s) {
  return (s[0] == 'C' || s[0] == 'c');
}

bool isMethod(char c) {
  return (c == 'M' || c == 'm');
}

bool isClass(char c) {
  return (c == 'C' || c == 'c');
}

bool isVariable(char c) {
  return (c == 'V' || c == 'v');
}

bool isLowercase(char c) {
  if ((97 <= c) && (c <= 122));
}

bool isUppercase(char c) {
  return ((65 <= c) && (c <= 90));
}

char getSecondChar(string s) {
  return s[2];
}

void makeUppercase(char &c) {
  if (isLowercase(c)) { c = char (c - 32); }
}

void makeLowercase(char &c) {
  if (isUppercase(c)) { c = char (c + 32); }
}

void stripFirstFour(string &input) {
  input.erase(0, 4);
}

void stripLastTwo(string &input) {
  input.erase(input.end() - 2, input.end());
}

void stripLeadingSpaces(string &input) {
  int index = 0;
  while (input[index] == ' ') { index++; }
}

void deleteRunningSpaces(string &input, int index) {
  while (input[index] == ' ') { input.erase(index, 1); }
}

void deleteSpacesAndMakeUppercase(string &input) {
  for (int i = 0; i < input.length(); i++) {
    if (input[i] == ' ') {
      deleteRunningSpaces(input, i);
      makeUppercase(input[i]);
    }
  }
}

void addSpacesBeforeUppercase(string &input) {
  for (int i = 1; i < input.size(); i++) {
    if (isUppercase(input[i])) {
      input.insert(i, " ");
      i++;
    }
  }
}

void makeAllLowercase(string &input) {
  for (int i = 0; i < input.size(); i++) {
    makeLowercase(input[i]);
  }
}

void makeFirstLetterUppercase(string &input) {
  makeUppercase(input[0]);
}

void makeFirstLetterLowercase(string &input) {
  makeLowercase(input[0]);
}

void splitName(string &input) {
  if (isMethod(input[2])) {
    stripLastTwo(input);
  }
  stripFirstFour(input);
  makeFirstLetterLowercase(input);
  addSpacesBeforeUppercase(input);
  makeAllLowercase(input);
}

void exitMessage() {
  cout << "program finished" << endl;
}

#endif
