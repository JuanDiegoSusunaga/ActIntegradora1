#include <gtest/gtest.h>
#include "main.cpp"

TEST(ExpandirCentroTest, PalindromoCentral) {
    std::string s = "abacaba";
    int inicio = 0, maxLong = 0;

    expandirCentro(s, 3, 3, inicio, maxLong);

    EXPECT_EQ(inicio, 0);
    EXPECT_EQ(maxLong, 7);
}
