#include <iostream>
#include <cmath>
using namespace std;

class Fraction{
    public:
    Fraction();
    Fraction(int numerator,int denominator);

    int get_numerator() const;
    int get_denominator() const;

    int gcd(int right, int b);
    void normalise();
    void write() const;

    Fraction sum(const Fraction& right);
    Fraction sub(const Fraction& right);
    Fraction mul(const Fraction& right);
    Fraction div(const Fraction& right);

    private:
    int numerator;
    int denominator;
};

void Fraction::write() const {
  cout << numerator << '/' << denominator;
}

int Fraction::gcd(int right, int b) {
  while (b != 0) {
    int tmp = right;
    right = b;
    b = tmp % b;
  }
  return right;
}

void Fraction::normalise() {
  int g = gcd(numerator, denominator);
  numerator /= g;
  denominator /= g;
  if (denominator < 0) {
    numerator = - numerator;
    denominator = - denominator;
  }
}

Fraction::Fraction(){ numerator = 0; denominator = 1;}
Fraction::Fraction(int numerator, int denominator){
    this->numerator = numerator; 
    this->denominator = denominator;
    (*this).normalise();
}
int Fraction::get_numerator() const{
    return this->numerator;
}
int Fraction::get_denominator() const{
    return this->denominator;
}

Fraction Fraction::sum(const Fraction& right){
    int n = right.get_numerator() * denominator + numerator * right.get_denominator();
    int d = right.get_denominator() * denominator;
    Fraction res(n,d); res.normalise();
    return res;
}

Fraction Fraction::sub(const Fraction& right){
    int n = numerator * right.get_denominator() - right.get_numerator() * denominator ;
    int d = right.get_denominator() * denominator;
    Fraction res(n,d); res.normalise();
    return res;
}

Fraction Fraction::mul(const Fraction& right){
    int n = right.get_numerator() * numerator ;
    int d = right.get_denominator() * denominator;
    Fraction res(n,d); res.normalise();
    return res;
}

Fraction Fraction::div(const Fraction& right){
    int n = right.get_denominator() * numerator ;
    int d = right.get_numerator() * denominator;
    Fraction res(n,d); res.normalise();
    return res;
}
