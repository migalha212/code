#include <iostream>     // std::cout
#include <algorithm>    // std::count
#include <gtest/internal/gtest-string.h>

#include "exercises.h"

std::string hanoiDC(unsigned int n, char src, char dest) {
    if (n == 1) return std::string(1, src) + "->" + std::string(1, dest);

    char aux = 'A';
    if (src + dest == 'A' + 'B') aux = 'C';
    else if (src + dest == 'A' + 'C') aux = 'B';

    return hanoiDC(n - 1, src, aux) + "," + hanoiDC(1, src, dest) + "," + hanoiDC(n - 1, aux, dest);
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex2, testHanoi_height4) {
    std::string moves = hanoiDC(4, 'A', 'B');
    EXPECT_EQ(std::count(moves.begin(),moves.end(),','), 14); // there are 15 moves
    EXPECT_EQ(moves, "A->C,A->B,C->B,A->C,B->A,B->C,A->C,A->B,C->B,C->A,B->A,C->B,A->C,A->B,C->B");
}
