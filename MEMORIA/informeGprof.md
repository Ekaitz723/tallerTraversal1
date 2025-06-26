# Análisis de Rendimiento usando Gprof

El programa ejecutado tiene un tiempo total de ejecución de **0.72 segundos**. El análisis revela los principales cuellos de botella y patrones de uso.

## Funciones más Costosas (Tiempo de CPU)

Las funciones que más tiempo consumen son:

- **`IERS()`** - 26.39% del tiempo total (0.19s) con 4,988 llamadas
- **`Matrix::operator()(int) const`** - 15.28% (0.11s) con 64,445,860 llamadas
- **`AccelHarmonic()`** - 15.28% (0.11s) con 19,182 llamadas  
- **`Legendre()`** - 13.89% (0.10s) con 19,182 llamadas
- **`Matrix::operator()(int, int) const`** - 6.94% (0.05s) con 77,455,943 llamadas

## Funciones más Llamadas

Las operaciones matriciales dominan completamente:

- **`Matrix::operator()(int) const`** - **64,445,860 llamadas** (acceso a elementos 1D)
- **`Matrix::operator()(int, int) const`** - **77,455,943 llamadas** (acceso a elementos 2D)
- **`Matrix::initMatrix()`** - 552,022 llamadas
- **`Matrix::~Matrix()`** - 552,005 llamadas

## Estructura del Call Graph

El programa sigue esta jerarquía principal:

1. **`main()`** → `EKF_GEOS3()` (98.6% del tiempo total)
2. **`EKF_GEOS3()`** ejecuta:
   - `DEInteg()` - 94 veces (91% del tiempo)
   - Filtro de Kalman con `MeasUpdate()` y `TimeUpdate()`
3. **`DEInteg()`** llama intensivamente a:
   - `VarEqn()` - 2,374 veces 
   - `Accel()` - 2,564 veces

## Cuellos de Botella Identificados

### 1. Acceso a Matrices (21.22% tiempo total)
- 141+ millones de accesos a elementos de matriz
- Overhead significativo de la indexación base-1

### 2. Transformaciones Astronómicas (26.39%)
- `IERS()` para correcciones Earth Orientation Parameters
- Cálculos repetitivos de precesión/nutación

### 3. Cálculos Gravitacionales (29.17%)
- `AccelHarmonic()` + `Legendre()` para el modelo gravitacional
- 19,182 evaluaciones de polinomios de Legendre

## Observaciones Técnicas

- **Overhead de la clase Matrix**: La implementación de matrix hecha para asemejarse al funcionamiento de matlab genera muchas llamadas
- **Algoritmos astronómicos**: Muy intensivos computacionalmente pero necesarios para precisión
- **Gestión de memoria**: 552K creaciones/destrucciones de matrices sin memory leaks aparentes
- **Filtro de Kalman**: Funcionando correctamente con 138 actualizaciones de medidas

## Limitaciones del Análisis

El análisis muestra un sistema bien estructurado donde el tiempo se gasta apropiadamente en cálculos científicos complejos, no en ineficiencias obvias del código, aparte de Matrix.