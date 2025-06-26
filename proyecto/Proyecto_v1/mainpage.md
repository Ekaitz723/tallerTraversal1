# Initial Orbit Determination (Extended Kalman Filter) C++

## Descripción General

Este proyecto implementa una librería completa de algoritmos de astrodynamica y mecánica orbital, migrando código original de MATLAB hacia C++ manteniendo precisión numérica y compatibilidad funcional.

## Funcionalidades Principales

La librería incluye algoritmos fundamentales para:

- **Determinación orbital inicial**: Método de Gibbs para calcular velocidad orbital apartir de tres vectores posición
- **Cálculo de elementos orbitales**: Conversión entre vectores estado (posición/velocidad) y elementos keplerianos
- **Transformaciones de coordenadas**: Conversiones geodésicas entre sistemas de referencia terrestres e inerciales  
- **Determinación angular**: Algoritmos de triangulación para determinar órbitas desde observaciones angulares

## Arquitectura del Sistema

### Clase Matrix
El núcleo del proyecto es una clase Matrix personalizada que replica el comportamiento matricial de MATLAB:
- Indexación base-1 para compatibilidad directa
- Operaciones vectoriales (producto cruz, producto escalar, normas)
- Concatenación y extracción de vectores manteniendo orientacion
- Funciones matriciales estándar (transpuesta, inversa, determinante)

### Estructura de Archivos
- `/src/`: Implementaciones de funciones principales
- `/include/`: Headers con declaraciones y constantes físicas
- `/data/`: Datos y archivos de referencia
- `Test_Unitarios.cpp`: Framework de testing completo
- `Main.cpp`: Main de la aplicación

## Testing y Validación

Cada función incluye tests unitarios y de integración exhaustivos que validan:
- Casos típicos de órbitas LEO, GEO y elípticas
- Casos límite y condiciones de error
- Precisión numérica contra resultados MATLAB de referencia
- Conservación de propiedades físicas (energía, momento angular)

## Ejecución

### Tests unitarios
```bash
make tests_unitarios; ./tests_unitarios
```

### Main de la aplicación
```bash
make Main; ./Main
```

## Entorno de Desarrollo

- **Sistema**: Ubuntu 24.04.2 LTS
- **Compilador**: g++ (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0
- **Build system**: GNU Make 4.3
- **Plataforma**: WSL 2.3.26.0
- **Kernel**: 5.15.167.4-1
- **WSLg**: 1.0.65
- **Windows**: 10.0.22631.5472

## Constantes y Referencias

Las constantes físicas (GM_Earth, radios planetarios, etc.) están centralizadas en `Sat_const.h` siguiendo estándares astronómicos actuales.

---
*Proyecto desarrollado para aplicaciones de seguimiento satelital y análisis orbital de precisión, usando Extended Kalman Filter*