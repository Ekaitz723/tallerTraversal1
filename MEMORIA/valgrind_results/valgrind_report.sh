#!/bin/bash

# Script para análisis completo de memoria y rendimiento 
# Proyecto: Librería Astrodynamica MATLAB->C++

echo "=== ANÁLISIS COMPLETO CON VALGRIND ==="
echo "Proyecto: Librería Astrodynamica"
echo

# Verificar que existen los ejecutables
if [ ! -f "Main" ] && [ ! -f "tests_unitarios" ]; then
   echo "Error: No se encuentran los ejecutables. Compilando..."
   make clean
   make all
   if [ $? -ne 0 ]; then
       echo "Error en compilación"
       exit 1
   fi
fi

# Crear directorio para resultados
mkdir -p valgrind_results
cd valgrind_results

echo "=== ANÁLISIS DEL PROGRAMA PRINCIPAL ==="
echo
echo "1. Ejecutando análisis de memoria (Memcheck) - Main..."
valgrind --tool=memcheck \
        --leak-check=full \
        --show-leak-kinds=all \
        --track-origins=yes \
        --verbose \
        --log-file=main_memcheck.log \
        ../Main

echo "✓ Análisis de memoria Main completado"
echo

echo "2. Ejecutando análisis de rendimiento (Callgrind) - Main..."
valgrind --tool=callgrind \
        --callgrind-out-file=main_callgrind.out \
        --collect-jumps=yes \
        --collect-systime=yes \
        ../Main

echo "✓ Análisis de rendimiento Main completado"
echo

echo "=== ANÁLISIS DE TESTS UNITARIOS ==="
echo
echo "3. Ejecutando análisis de memoria (Memcheck) - Tests..."
valgrind --tool=memcheck \
        --leak-check=full \
        --show-leak-kinds=all \
        --track-origins=yes \
        --verbose \
        --log-file=tests_memcheck.log \
        ../tests_unitarios

echo "✓ Análisis de memoria Tests completado"
echo

echo "4. Ejecutando análisis de rendimiento (Callgrind) - Tests..."
valgrind --tool=callgrind \
        --callgrind-out-file=tests_callgrind.out \
        --collect-jumps=yes \
        --collect-systime=yes \
        ../tests_unitarios

echo "✓ Análisis de rendimiento Tests completado"
echo

echo "5. Ejecutando análisis de cache (Cachegrind) - Tests..."
valgrind --tool=cachegrind \
        --cachegrind-out-file=tests_cachegrind.out \
        ../tests_unitarios

echo "✓ Análisis de cache completado"
echo

echo "6. Generando resúmenes..."

# Resumen completo
echo "=== ANÁLISIS VALGRIND - LIBRERÍA ASTRODYNAMICA ===" > resumen_completo.txt
echo "Fecha: $(date)" >> resumen_completo.txt
echo "Sistema: $(uname -a)" >> resumen_completo.txt
echo >> resumen_completo.txt

# Resumen de memoria - Main
echo "=== MEMORIA - PROGRAMA PRINCIPAL ===" >> resumen_completo.txt
grep -E "(ERROR SUMMARY|definitely lost|indirectly lost|possibly lost|still reachable)" main_memcheck.log >> resumen_completo.txt
echo >> resumen_completo.txt

# Resumen de memoria - Tests
echo "=== MEMORIA - TESTS UNITARIOS ===" >> resumen_completo.txt
grep -E "(ERROR SUMMARY|definitely lost|indirectly lost|possibly lost|still reachable)" tests_memcheck.log >> resumen_completo.txt
echo >> resumen_completo.txt

# Resumen de rendimiento - Tests (más completo)
echo "=== RENDIMIENTO - TESTS UNITARIOS ===" >> resumen_completo.txt
if command -v callgrind_annotate &> /dev/null; then
   callgrind_annotate tests_callgrind.out | head -40 >> resumen_completo.txt
else
   echo "callgrind_annotate no disponible. Instalar valgrind-tools." >> resumen_completo.txt
fi
echo >> resumen_completo.txt

# Resumen de cache
echo "=== CACHE - TESTS UNITARIOS ===" >> resumen_completo.txt
if command -v cg_annotate &> /dev/null; then
   cg_annotate tests_cachegrind.out | head -25 >> resumen_completo.txt
else
   echo "cg_annotate no disponible. Instalar valgrind-tools." >> resumen_completo.txt
fi

# Resumen rápido para errores críticos
echo "=== ERRORES CRÍTICOS ===" > errores_criticos.txt
echo "MAIN:" >> errores_criticos.txt
grep -E "ERROR|LEAK|Invalid|Uninitialised" main_memcheck.log >> errores_criticos.txt || echo "No se encontraron errores críticos en Main" >> errores_criticos.txt
echo >> errores_criticos.txt
echo "TESTS:" >> errores_criticos.txt
grep -E "ERROR|LEAK|Invalid|Uninitialised" tests_memcheck.log >> errores_criticos.txt || echo "No se encontraron errores críticos en Tests" >> errores_criticos.txt

echo "✓ Resúmenes generados"
echo

echo "=== RESULTADOS GENERADOS ==="
echo "Directorio: valgrind_results/"
echo
echo "ARCHIVOS PRINCIPALES:"
echo "- resumen_completo.txt: Resumen de todos los análisis"
echo "- errores_criticos.txt: Solo errores importantes"
echo
echo "ARCHIVOS DETALLADOS:"
echo "- main_memcheck.log: Memoria del programa principal"
echo "- tests_memcheck.log: Memoria de tests unitarios"
echo "- main_callgrind.out: Rendimiento programa principal"
echo "- tests_callgrind.out: Rendimiento tests unitarios"
echo "- tests_cachegrind.out: Análisis de cache"
echo

echo "=== COMANDOS ÚTILES ==="
echo "Ver solo errores críticos:"
echo "  cat valgrind_results/errores_criticos.txt"
echo
echo "Ver resumen completo:"
echo "  cat valgrind_results/resumen_completo.txt"
echo
echo "Análisis gráfico (si tienes kcachegrind):"
echo "  kcachegrind valgrind_results/tests_callgrind.out"
echo
echo "Buscar memory leaks específicos:"
echo "  grep -A5 -B5 'definitely lost' valgrind_results/tests_memcheck.log"

cd ..