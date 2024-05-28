#ifndef TASK1_OUT_OF_LIST_H
#define TASK1_OUT_OF_LIST_H

#include <string>
#include <memory>

using namespace std;

class out_of_list {
protected:
    unique_ptr<string> sr;
public:
    ~out_of_list(){};
    out_of_list(string &&obj): sr{make_unique<string>(obj)}{};
};

#endif //TASK1_OUT_OF_LIST_H
