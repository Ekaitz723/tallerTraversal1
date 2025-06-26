# Análisis del Output de Gprof Usando Gprof

El programa ejecutado es muy rápido: no se acumuló tiempo medible durante la ejecución. Esto significa que todas las funciones ejecutaron en menos de 0.01 segundos, que es la granularidad mínima de gprof.

## Funciones más llamadas

Las funciones que más se ejecutaron fueron:

- **`std::array<double, 21ul>::operator[]`** 83 llamadas
- **`std::abs(double)`** 83 llamadas  
- **`std::pow<double, int>`** 23 llamadas

Estas están relacionadas con acceso a arrays y operaciones matemáticas básicas.

## Estructura del Call Graph

El programa sigue esta jerarquía principal:

1. **`test_lambert_battin()`** función principal de prueba
2. **`LambertBattin::solve()`** algoritmo principal que llama a:
   - `seebatt()` y `seebattk()` (5 veces cada una)
   - Múltiples operaciones con `Vector3D`
   - Funciones matemáticas como `pow()` y `abs()`

## Observaciones Técnicas

- **Overhead de C++**: Gran parte de las llamadas son de la librería estándar (constructores, operadores, manejo de strings)
- **Vectores 3D**: Se crean 9 objetos `Vector3D` durante la ejecución
- **Operaciones matemáticas**: El algoritmo Lambert-Battin es muy pesado en calculos

## Limitaciones del Análisis

El análisis sugiere que el código está bien optimizado o que el caso de prueba es demasiado simple para revelar cuellos de botella.