#include <gtest/gtest.h>
#include "main.cpp"

TEST(LCSTest, CoincidenciaParcial) {
    std::string a = "mensaje secreto";
    std::string b = "secreto cifrado";
    auto [sx, ex, sy, ey, substr] = lcs(a, b);
    EXPECT_EQ(substr, "secreto");
}

TEST(LCSTest, SinCoincidencia) {
    std::string a = "abc";
    std::string b = "xyz";
    auto [sx, ex, sy, ey, substr] = lcs(a, b);
    EXPECT_EQ(substr, "");
}
