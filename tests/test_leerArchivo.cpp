#include <gtest/gtest.h>
#include "main.cpp"
#include <fstream>

TEST(LeerArchivoTest, ArchivoExistente) {
    std::ofstream testFile("testfile.txt");
    testFile << "Hola mundo";
    testFile.close();

    std::string contenido = leerArchivo("testfile.txt");
    EXPECT_EQ(contenido, "Hola mundo");

    std::remove("testfile.txt");
}
