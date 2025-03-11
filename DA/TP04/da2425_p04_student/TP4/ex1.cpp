#include "exercises.h"
#include "cmath"

int maxSubAux(int A[], int mid, int &i, int &j,int start, int end) {
    int maxlsum = INT_MIN;
    int currlsum = 0;
    for (int k = mid; k >= start; k--) {
        currlsum += A[k];
        if (currlsum > maxlsum) {
            maxlsum = currlsum;
            i = k;
        }
    }

    int currrsum = 0;
    int maxrsum = INT_MIN;
    for (int k = mid + 1; k <= end; k++) {
        currrsum += A[k];
        if (currrsum > maxrsum) {
            maxrsum = currrsum;
            j = k;
        }
    }
    return maxrsum + maxlsum;
}

int maxSubsequenceRC(int A[], int &i, int &j) {
    if (i > j) return -1; //invalid
    if (i == j) return A[i]; //only one element
    int mid = i + (j - i) / 2; // find middle point
    // auxiliary variables used to keep the reference calls in check
    int i1 = i, i2 = mid + 1, j1 = mid, j2 = j;
    int lsum = maxSubsequenceRC(A, i1, j1);
    int rsum = maxSubsequenceRC(A, i2, j2);
    int cross = maxSubAux(A, mid, i, j,i,j);

    if (lsum >= rsum && lsum >= cross) {
        i = i1;
        j = j1;
        return lsum;
    } else if (rsum >= lsum && rsum >= cross) {
        i = i2;
        j = j2;
        return rsum;
    } else {
        return cross;
    }
}

int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j) {
    i = 0;
    j = n - 1;
    return maxSubsequenceRC(A, i, j);
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP4_Ex1, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    int i, j;
    EXPECT_EQ(maxSubsequenceDC(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    EXPECT_EQ(maxSubsequenceDC(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    EXPECT_EQ(maxSubsequenceDC(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    EXPECT_EQ(maxSubsequenceDC(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}
