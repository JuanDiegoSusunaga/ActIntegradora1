#include <gtest/gtest.h>
#include "main.cpp"

TEST(PalindromoMasLargoTest, ConPalindromo) {
    std::string s = "abcxyzyxdef";
    auto [inicio, fin, pal] = palindromoMasLargo(s);
    EXPECT_EQ(pal, "xyzyx");
    EXPECT_EQ(inicio, 4);
    EXPECT_EQ(fin, 8);
}

TEST(PalindromoMasLargoTest, SinPalindromo) {
    std::string s = "abcde";
    auto [inicio, fin, pal] = palindromoMasLargo(s);
    EXPECT_EQ(pal.length(), 1);
}
