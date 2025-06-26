# Análisis de Rendimiento y Memoria Usando Valgrind

**Herramientas utilizadas:** Valgrind 3.22.0 (Memcheck, Callgrind, Cachegrind)  

**Sistema:** Linux WSL2 (Ubuntu 24.04.2)

El programa ha sido sometido a un análisis completo de memoria y rendimiento usando Valgrind. Los resultados revelan un memory leak menor en el programa principal, mientras que los tests unitarios muestran un comportamiento limpio.

## Análisis de Memoria (Memcheck)

### Estado General del Programa Principal
- **Errores detectados:** 1 error (memory leak)
- **Memory leaks:** 176 bytes perdidos (64 directos + 112 indirectos)
- **Gestión de memoria:** Mayormente correcta con una falla menor

### Detalles del Heap - Main
```
Heap Summary:
- Bloques en uso al finalizar: 176 bytes en 9 bloques
- Uso total del heap: 69 allocaciones, 60 liberaciones
- Memoria total asignada: 84,930 bytes
```

### Desglose de Memory Leaks
- **64 bytes definitivamente perdidos:** 1 bloque en `EKF_GEOS3()`
- **112 bytes indirectamente perdidos:** 8 bloques relacionados con `Matrix::initMatrix()`
- **Origen:** Todas las pérdidas se originan en la función `EKF_GEOS3()` llamada desde `main()`

### Estado de Tests Unitarios
- **Errores detectados:** 0
- **Memory leaks:** Ninguno
- **Gestión de memoria:** Perfecta

**Interpretación:** El problema de memoria está localizado específicamente en la función `EKF_GEOS3()` del programa principal. Los tests unitarios funcionan perfectamente, lo que sugiere que el issue está en la lógica específica del filtro de Kalman extendido, no en las funciones base de la librería.

## Análisis de Rendimiento (Callgrind/Cachegrind)

### Observaciones de Rendimiento
- Los archivos de análisis de rendimiento no pudieron ser procesados completamente
- Se requiere instalación de herramientas adicionales (`callgrind_annotate`, `cg_annotate`)

## Ubicación Específica del Memory Leak

El memory leak se origina en tres ubicaciones dentro de `EKF_GEOS3()`:

1. **Línea 0x121DBC:** Allocación de objeto con `operator new`
2. **Línea 0x121DD1:** Creación de matrices con `Matrix::initMatrix()`  
3. **Línea 0x11E5FE:** Allocación principal que causa el problema

## Interpretación Técnica

### Impacto del Memory Leak
- **Severidad:** Baja (solo 176 bytes)
- **Frecuencia:** Una vez por ejecución del programa
- **Impacto operacional:** Mínimo para ejecuciones cortas

### Calidad del Código
- **Tests unitarios:** Excelente gestión de memoria (0 leaks)
- **Funciones core:** La clase Matrix y algoritmos base funcionan correctamente
- **Problema localizado:** El problema está específicamente en el flujo principal del EKF
