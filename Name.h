#ifndef NAME_H
#define NAME_H
#include "AbstractName.h"
#include "MethodName.h"
#include "VariableName.h"
#include "ClassName.h"
#include "library.h"
#include <string>
using namespace std;

class Name {
  private:
    AbstractName* createdName_;
    string name_;
    char type_;
  public:
    Name(string input, char c) {
	  createdName_ = NULL;
      this->type_ = c;
      this->name_ = input;
    }
    void assign() {
      if (createdName_ != NULL) { delete createdName_; createdName_ = NULL; }
      if (isMethod(type_)) { createdName_ = (AbstractName*)new MethodName(); }
      else if (isClass(type_)) { createdName_ = (AbstractName*)new ClassName(); }
      else if (isVariable(type_)) { createdName_ = (AbstractName*)new VariableName(); }
      else { cout << "error in combine();" << endl; }
    }
    void createName() {
      assign();
      name_ = createdName_->createName(name_);
    }
    void printName() {
      cout << name_ << endl;
    }
};

#endif