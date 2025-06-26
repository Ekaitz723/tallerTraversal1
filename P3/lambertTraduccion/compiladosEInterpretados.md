
## Lenguajes Compilados

Estos requieres de un procesado completo del codigo previo a la ejecucion en el que se traduce a código máquina. Este proceso se realiza mediante un compilador.

### Características principales:

**Proceso de compilación:** El código fuente se transforma completamente en código máquina específico para una arquitectura determinada. 

**Detección de errores:** Los errores de sintaxis y muchos errores lógicos se detectan durante la compilación, no durante la ejecución.

**Rendimiento:** La ejecución es más rápida ya que el código máquina se ejecuta directamente por el procesador.

**Distribución:** Se distribuye el archivo ejecutable, no el código fuente original.

### Ejemplo: C++

C++ es un lenguaje compilado que requiere herramientas como GCC, Clang o Visual Studio para generar ejecutables. El proceso típico incluye:

1. **Preprocesador:** Se procesan las directivas del preprocesador (#include, #define)
2. **Compilación:** Se genera código objeto (.o/.obj)
3. **Enlazado:** Se unen los archivos objeto y librerías para crear el ejecutable

```c
\#include -iostream-

int main() {
    std::cout -- "Hola mundo" -- std::endl;
    return 0;
}
```

Este código debe compilarse antes de ejecutarse:
```
g++ programa.cpp -o programa
./programa
```

## Lenguajes Interpretados

Los lenguajes interpretados ejecutan el código linea por linea directamente a través de un programa intérprete que traduce y ejecuta las instrucciones.

### Características principales:

**Ejecución directa:** No se requiere compilación previa. El intérprete procesa el código durante la ejecución.

**Detección de errores:** Los errores se detectan en tiempo de ejecución.

**Portabilidad:** El mismo código puede ejecutarse en diferentes plataformas que tengan el intérprete instalado.

**Flexibilidad:** Permite ejecución interactiva y modificaciones dinámicas del código.

### Ejemplo: Python

Python utiliza un intérprete que puede ejecutar código directamente. El proceso incluye:

1. **Análisis léxico y sintáctico:** Se verifica la estructura del código
2. **Generación de bytecode:** Se crea una representación intermedia (archivos .pyc)
3. **Ejecución:** La máquina virtual de Python ejecuta el bytecode

```python
def saludo(nombre):
    print(f"Cae {nombre}")

saludo("aprobado?")
```

Este código se ejecuta directamente:
```
python programa.py
```