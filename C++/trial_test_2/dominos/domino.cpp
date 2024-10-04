#include "Domino.h"

using namespace std;

//* Piece implementations
bool Piece::can_be_left_to(const Piece& other) const{
    return other.get_left() == right_;
}
bool Piece::can_be_right_to(const Piece& other) const{
    return other.get_right() == left_;
}

//* Domino implementations
const Piece& Domino::left() const{
    return pieces_.front();
}
const Piece& Domino::right() const{
    return pieces_.back();
}

bool Domino::place_left(const Piece& p){
    if(p.can_be_left_to(this->left())){
        pieces_.push_front(p);
        return true;
    }
    return false;
}

bool Domino::place_right(const Piece& p){
    if(p.can_be_right_to(this->right())){
        pieces_.push_back(p);
        return true;
    }
    return false;
}