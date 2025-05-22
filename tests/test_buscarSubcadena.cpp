#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "main.cpp"

TEST_CASE("buscarSubcadena - subcadena presente") {
    string texto = "Este es un mensaje secreto";
    CHECK(buscarSubcadena(texto, "mensaje") == 10);
}

TEST_CASE("buscarSubcadena - subcadena ausente") {
    string texto = "Texto limpio";
    CHECK(buscarSubcadena(texto, "virus") == -1);
}
