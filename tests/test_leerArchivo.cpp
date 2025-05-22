#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "main.cpp"

TEST_CASE("leerArchivo - contenido correcto") {
    ofstream archivo("test_temp.txt");
    archivo << "Hola mundo";
    archivo.close();

    string contenido = leerArchivo("test_temp.txt");
    CHECK(contenido == "Hola mundo");

    remove("test_temp.txt");
}
