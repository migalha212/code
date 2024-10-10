#ifndef ErasmusStudent_H
#define ErasmusStudent_H

#include "Student.h"

class ErasmusStudent : public Student{
private:
    string country_;
public:
ErasmusStudent(int id, const string& name, const string& course, const string& country) : Student(id,name,course),country_(country) {}
const string& country() const{ return country_;}
string to_string() const{
    ostringstream out;
    out << Student::to_string() << '/' << country_;
    return out.str();
}
};
#endif