#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "main.cpp"

TEST_CASE("palindromoMasLargo - caso normal") {
    auto [inicio, fin, pal] = palindromoMasLargo("abcddcba");
    CHECK(inicio == 1);
    CHECK(fin == 8);
    CHECK(pal == "abcddcba");
}

TEST_CASE("palindromoMasLargo - sin palíndromos largos") {
    auto [inicio, fin, pal] = palindromoMasLargo("abc");
    CHECK(pal == "a");
}
