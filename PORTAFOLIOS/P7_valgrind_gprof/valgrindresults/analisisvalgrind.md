# Análisis de Rendimiento y Memoria Usando Valgrind

**Herramientas utilizadas:** Valgrind 3.22.0 (Memcheck, Callgrind, Cachegrind)  

**Sistema:** Linux WSL2 (Ubuntu)

El programa lambert_battin.cpp ha sido sometido aun análisis completo de memoria y rendimiento usando Valgrind. Los resultados muestran un codigo limpio sin errores de memoria ni memory leaks, con un comportamiento de ejecucion eficiente.

## Análisis de Memoria (Memcheck)

### Estado General
- **Errores detectados:** 0
- **Memory leaks:** Ninguno
- **Gestión de memoria:** Correcta

### Detalles del Heap
```
Heap Summary:
- Bloques en uso al finalizar: 0 bytes en 0 bloques
- Uso total del heap: 2 allocaciones, 2 liberaciones
- Memoria total asignada: 74,752 bytes
```

**Interpretación:** El programa gestiona correctamente la memoria dinamica. Todas las asignaciones de memoria son liberadas apropiadamente, no hay leaks ni accesos a memoria invalida.

## Análisis de Rendimiento (Callgrind)

### Métricas de Ejecución
- **Instrucciones totales ejecutadas:** 1,948,101
- **Llamadas al sistema:** 84
- **Tiempo de sistema:** 101 unidades

### Funciones con Mayor Coste Computacional

| Función | Instrucciones | % del Total | Ubicación |
|---------|--------------|-------------|-----------|
| `do_lookup_x` | 499,552 | 25.64% | ld-linux-x86-64.so.2 |
| `_dl_lookup_symbol_x` | 492,086 | 25.26% | sysdeps/generic/dl-new-hash.h |
| `_dl_lookup_symbol_x` | 184,685 | 9.48% | ld-linux-x86-64.so.2 |
| `_dl_relocate_object` | 146,417 | 7.52% | ld-linux-x86-64.so.2 |
| `check_match` | 112,346 | 5.77% | ld-linux-x86-64.so.2 |

**Observación importante:** La mayoría del tiempo de ejecucion se consume en funciones del dynamic linker (ld-linux), no en el codigo del programa propiamente dicho. Esto sugiere que el overhead principal viene del proceso de carga de bibliotecas y resolución de símbolos.

## Análisis de Cache (Cachegrind)

### Comportamiento de Cache
- **Instrucciones totales analizadas:** 1,956,569
- **Patron de acceso:** Eficiente

La diferencia mínima entre las instrucciones reportadas por Callgrind (1,948,101) y Cachegrind (1,956,569) indica consistencia en las mediciones.

## Interpretación Técnica

### Rendimiento del Código de Usuario
El programa lambert_battin muestra un comportamiento excelente desde el punto de vista de optimización:

1. **Gestión de memoria limpia:** Sin leaks ni errores de acceso
2. **Footprint pequeño:** Solo 74KB de memoria heap utilizada
3. **Overhead mínimo:** La mayor parte del coste computacional proviene del sistema, no del algoritmo

### Cuellos de Botella Identificados
Los principales costes vienen del dynamic linking, lo cual es normal en programas pequeños donde el overhead de inicialización del sistema puede ser proporcionalmente alto comparado con la lógica del programa.