#include "Student.h"
#include <iostream>
using namespace std;

Student::Student(const std::string& id){
    this->id_ = id;
}

std::string Student::get_id() const{
    return this->id_;
}

void Student::add(const course& c){
    this->courses_.push_back(c);
}

double Student::avg() const{
    double res = 0;
    double credit = 0;
    for(course c : this->courses_){
        if(c.grade < 10) continue;
        res += c.credits * c.grade;
        credit += c.credits;
    }
    
    return res == 0 ? res : res / credit;
}