#ifndef CLASSNAME_H
#define CLASSNAME_H
#include "AbstractName.h"
#include "library.h"
#include <string>

class ClassName : public AbstractName {
  string combine(string name) {
    stripFirstFour(name);
	stripLeadingSpaces(name);
    makeFirstLetterUppercase(name);
    deleteSpacesAndMakeUppercase(name);
    return name;
  }
};

#endif