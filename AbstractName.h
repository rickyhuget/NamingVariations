#ifndef ABSTRACTNAME_H
#define ABSTRACTNAME_H
#include <string>
using namespace std;

class AbstractName {
  private:
    virtual string combine(string n) = 0;
  public:
    string createName(string n) {
      return combine(n);
    }
};

#endif