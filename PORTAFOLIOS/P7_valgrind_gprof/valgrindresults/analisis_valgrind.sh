#!/bin/bash

# Script para análisis completo de memoria y rendimiento con Valgrind
# Archivo: lambert_battin.cpp

PROGRAMA="lambert_battin"
CPP_FILE="${PROGRAMA}.cpp"

echo "=== ANÁLISIS COMPLETO CON VALGRIND ==="
echo "Archivo: $CPP_FILE"
echo

# Verificar que existe el archivo
if [ ! -f "$CPP_FILE" ]; then
    echo "Error: No se encuentra $CPP_FILE"
    exit 1
fi

# Compilar con símbolos de debug
echo "1. Compilando con símbolos de debug..."
g++ -g -O0 -o $PROGRAMA $CPP_FILE
if [ $? -ne 0 ]; then
    echo "Error en compilación"
    exit 1
fi
echo "✓ Compilado correctamente"
echo

# Crear directorio para resultados
mkdir -p valgrind_results
cd valgrind_results

echo "2. Ejecutando análisis de memoria (Memcheck)..."
valgrind --tool=memcheck \
         --leak-check=full \
         --show-leak-kinds=all \
         --track-origins=yes \
         --verbose \
         --log-file=memcheck.log \
         ../$PROGRAMA

echo "✓ Análisis de memoria completado"
echo

echo "3. Ejecutando análisis de rendimiento (Callgrind)..."
valgrind --tool=callgrind \
         --callgrind-out-file=callgrind.out \
         --collect-jumps=yes \
         --collect-systime=yes \
         ../$PROGRAMA

echo "✓ Análisis de rendimiento completado"
echo

echo "4. Ejecutando análisis de cache (Cachegrind)..."
valgrind --tool=cachegrind \
         --cachegrind-out-file=cachegrind.out \
         ../$PROGRAMA

echo "✓ Análisis de cache completado"
echo

echo "5. Generando resúmenes..."

# Resumen de memoria
echo "=== RESUMEN DE MEMORIA ===" > resumen.txt
echo "Fecha: $(date)" >> resumen.txt
echo >> resumen.txt
grep -E "(ERROR SUMMARY|definitely lost|indirectly lost|possibly lost)" memcheck.log >> resumen.txt
echo >> resumen.txt

# Resumen de rendimiento
echo "=== RESUMEN DE RENDIMIENTO ===" >> resumen.txt
callgrind_annotate callgrind.out | head -30 >> resumen.txt
echo >> resumen.txt

# Resumen de cache
echo "=== RESUMEN DE CACHE ===" >> resumen.txt
cg_annotate cachegrind.out | head -20 >> resumen.txt

echo "✓ Resúmenes generados"
echo

echo "=== RESULTADOS ==="
echo "Directorio: valgrind_results/"
echo "- memcheck.log: Análisis detallado de memoria"
echo "- callgrind.out: Datos de rendimiento"
echo "- cachegrind.out: Datos de cache"
echo "- resumen.txt: Resumen de todos los análisis"
echo

echo "Para visualizar gráficamente:"
echo "kcachegrind valgrind_results/callgrind.out"
echo
echo "Para ver solo errores críticos:"
echo "grep -E 'ERROR|LEAK' valgrind_results/memcheck.log"