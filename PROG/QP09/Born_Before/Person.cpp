#include "Person.h"

Person::Person(){
    name_ = "NO_NAME";
    birth_date_ = Date();
}
Person::Person(const std::string& name, const Date& birth_date){
    name_ = name;
    birth_date_ = birth_date;
}

std::string Person::get_name() const{
    return this->name_;
}
Date Person::get_birth_date() const{
    return this->birth_date_;
}