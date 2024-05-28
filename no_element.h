#ifndef TASK1_NO_ELEMENT_H
#define TASK1_NO_ELEMENT_H

#include <string>
#include <memory>

using namespace std;

class no_element{
protected:
    unique_ptr<string> sr;
public:
    ~no_element(){};
    no_element(string &&obj): sr{make_unique<string>(obj)}{};

};

#endif //TASK1_NO_ELEMENT_H
