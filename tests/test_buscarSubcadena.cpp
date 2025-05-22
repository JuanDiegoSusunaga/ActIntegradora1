#include <gtest/gtest.h>
#include "main.cpp"

TEST(BuscarSubcadenaTest, SubcadenaPresente) {
    std::string texto = "Este es un mensaje secreto";
    std::string patron = "mensaje";
    int pos = buscarSubcadena(texto, patron);
    EXPECT_EQ(pos, 11);
}

TEST(BuscarSubcadenaTest, SubcadenaAusente) {
    std::string texto = "Este es un mensaje secreto";
    std::string patron = "clave";
    int pos = buscarSubcadena(texto, patron);
    EXPECT_EQ(pos, -1);
}
