#include "TestFramework.h"
#include <iostream>

void TestFramework::runAllTests() {
    int tests_passed = 0;
    int tests_failed = 0;
    
    std::cout << "=== EJECUTANDO TESTS UNITARIOS ===" << std::endl << std::endl;
    
    for (const auto& test : tests) {
        try {
            std::cout << "Ejecutando " << test.name << "... ";
            test.func();
            std::cout << "✓ PASADO" << std::endl;
            tests_passed++;
        }
        catch (const std::exception& e) {
            std::cout << "✗ FALLO: " << e.what() << std::endl;
            tests_failed++;
        }
    }
    
    std::cout << std::endl << "=== RESUMEN ===" << std::endl;
    std::cout << "Tests pasados: " << tests_passed << std::endl;
    std::cout << "Tests fallidos: " << tests_failed << std::endl;
    
    if (tests_failed == 0) {
        std::cout << "¡Todos los tests pasaron correctamente!" << std::endl;
    } else {
        std::cout << "Algunos tests fallaron." << std::endl;
    }
}