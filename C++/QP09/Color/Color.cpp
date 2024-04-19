#include "Color.h"
using namespace std;

Color::Color(unsigned char red, unsigned char green, unsigned char blue){
    this->r = red; this->b = blue; this->g = green;
}

Color::Color(const Color& c){
    this->r = c.r; this->b = c.b; this->g = c.g;
}

unsigned char Color::red() const{
    return this->r;
}
unsigned char Color::green() const{
    return this->g;
}
unsigned char Color::blue() const{
    return this->b;
}

const Color Color::RED = {255,0,0};
const Color Color::GREEN = {0,255,0};
const Color Color::BLUE = {0,0,255};
const Color Color::WHITE = {255,255,255}; 
const Color Color::BLACK = {0,0,0};

bool Color::equal_to(const Color& other) const{
    if(this->r == other.r && this->g == other.g && this->b == other.b){
        return true;
    }
    return false;
}

void Color::invert(){
    this->r = 255 - r; this->b = 255 - b; this->g = 255 - g;
}



