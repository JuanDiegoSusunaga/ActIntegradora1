#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/main.cpp"

TEST_CASE("lcs - caso común") {
    string X = "abcde";
    string Y = "abfce";
    auto [sx, ex, sy, ey, substr] = lcs(X, Y);
    CHECK(substr == "ab");
}

TEST_CASE("lcs - sin coincidencias") {
    string X = "abc";
    string Y = "xyz";
    auto [sx, ex, sy, ey, substr] = lcs(X, Y);
    CHECK(substr == "");
}
