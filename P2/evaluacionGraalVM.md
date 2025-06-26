
Recomendado para

* Microservicios
* Aplicaciones cloud-native
* Apps empresariales Java existentes
* Proyectos políglotas

## Por nivel de abstracción

**Nivel**: Medio-Alto (híbrido)

- **Como JIT**: Alto nivel, se comporta como cualquier JVM tradicional
- **Como Native Image**: Nivel medio, genera código nativo pero mantiene abstracciones Java

## Por paradigma de programación

**Paradigma**: Multiparadigma extremo

- Soporta todos los paradigmas que soporta Java (OOP, funcional, etc.)
- Además permite ejecutar JavaScript, Python, Ruby, R, C/C++ en la misma aplicación

## Por modelo de ejecución

**Categoría**: Híbrido avanzado (nueva categoría)

- **JIT mode**: Compilación just-in-time
- **Native Image**: Compilación ahead-of-time

## Por sistema de tipos

**Tipado**: Depende del lenguaje huésped

- Java en GraalVM mantiene tipado estático fuerte
- JavaScript, Python, Ruby mantienen su sistema de tipos original pero con optimizaciones JIT

## Por dominio específico

**Clasificación**: Multipropósito con especialización cloud-native

- **Propósito general**: Compatible con frameworks como Helidon, Micronaut, Quarkus, Spring Boot

## Por concurrencia

**Modelo**: Hereda modelos de lenguajes huésped

- Java: threads tradicionales, Fork/Join
- JavaScript: event-driven

## Por gestión de memoria

**Tipo**: Garbage collection avanzado + manual

- **JIT mode**: GC optimizado con tiempos de pausa significativamente menores
- **Native Image**: Substrate VM con GC embebido más eficiente

## Por plataforma objetivo

**Targets**: Multiplataforma cloud-first

- **Sistemas**: Linux, macOS, Windows (x64, AArch64)
- **Cloud**: Optimizado para Kubernetes, OpenShift, entornos serverless

