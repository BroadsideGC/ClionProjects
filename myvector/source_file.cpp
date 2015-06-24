//
// Created by Big Z on 20.06.2015.
//
#include <string>

class Person {

    virtual std::string name() const;
    virtual int age() = 0;
};

class Student : virtual Person{
std::string name() const{
    return "FFF";
}
    int age(){
        return 30;
    };
};
