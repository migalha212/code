// By: Gonçalo Leão
// Updated by DA 24/25 Team

#include <algorithm>
#include <cmath>

bool subsetSumBF(unsigned int A[], unsigned int n, unsigned int T, unsigned int subset[], unsigned int &subsetSize) {

    subsetSize = 0;  // This variable is defined for the unit test to work. You should update it in your implementation.

    if (T == 0) return true; //the empty subset
    if (n == 0 && T > 0) return false; //A is empty so no subsets can be found
    std::sort(A, A + n);
    const int upper = std::upper_bound(A, A + n, T) - A;
    for (unsigned int i = 0;i < 1 << upper; i++) {
        subsetSize = 0;
        unsigned int currsum = 0;

        for (int m = 0; m < upper; m++) {
            if (i & 1 << m) {
                if (currsum + A[m] > T) break;
                subset[subsetSize++] = A[m];
                currsum += A[m];
            }
        }

        if (currsum == T)
            return true;
    }
    return false;
}

/// TESTS ///
#include <gtest/gtest.h>

unsigned int sum(unsigned int A[], unsigned int n) {
    unsigned int sum = 0;
    for(unsigned int i = 0; i < n; i++) {
        sum += A[i];
    }
    return sum;
}

// Checks if A is a subset of B
bool isSubset(unsigned int A[], unsigned int nA, unsigned int B[], unsigned int nB) {
    for(unsigned int i = 0; i < nA; i++) {
        bool foundNum = false;
        for(unsigned int j = 0; j < nB; j++) {
            if(A[i] == B[j]) {
                foundNum = true;
                break;
            }
        }
        if(!foundNum) return false;
    }
    return true;
}

TEST(TP2_Ex2, testSubsetSum) {
    unsigned int A[] = {3, 34, 4, 12, 5, 2};
    unsigned int subset[6];
    unsigned int subsetSize;

    unsigned int T = 9;
    EXPECT_EQ(subsetSumBF(A,6,T,subset,subsetSize), true);
    EXPECT_EQ(sum(subset, subsetSize), T);
    EXPECT_EQ(isSubset(subset, subsetSize, A,6), true);

    T = 20;
    EXPECT_EQ(subsetSumBF(A,6,T,subset,subsetSize), true);
    EXPECT_EQ(sum(subset, subsetSize), T);
    EXPECT_EQ(isSubset(subset, subsetSize, A,6), true);

    T = 30;
    EXPECT_EQ(subsetSumBF(A,6,T,subset,subsetSize), false);
}