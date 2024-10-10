#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"

class Student : public Person{
private: 
    string course_;
public:
    Student(int id, const string& name, const string& course) : Person(id,name), course_(course){}
    const string& course() const { return course_;}
    string to_string() const{
        ostringstream out;
        out << Person::to_string() <<'/' << course_;
        return out.str();
    }
};
#endif