#ifndef METHODNAME_H
#define METHODNAME_H
#include "AbstractName.h"
#include "library.h"
#include <string>

class MethodName : public AbstractName {
  string combine(string name) {
    stripFirstFour(name);
	stripLeadingSpaces(name);
    deleteSpacesAndMakeUppercase(name);
	makeLowercase(name[0]);
    name += "()";
    return name;
  }
};

#endif