#ifndef VARIABLENAME_H
#define VARIABLENAME_H
#include "AbstractName.h"
#include "library.h"
#include <string>

class VariableName : public AbstractName {
  string combine(string name) {
    stripFirstFour(name);
    stripLeadingSpaces(name);
    deleteSpacesAndMakeUppercase(name);
    makeLowercase(name[0]);
    return name;
  }
};

#endif
