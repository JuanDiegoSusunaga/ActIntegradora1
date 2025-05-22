#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "../src/main.cpp"

TEST_CASE("expandirCentro - palíndromo central") {
    string s = "abacaba";
    int inicio = 0, maxLong = 0;
    expandirCentro(s, 3, 3, inicio, maxLong);
    CHECK(inicio == 0);
    CHECK(maxLong == 7);
}
