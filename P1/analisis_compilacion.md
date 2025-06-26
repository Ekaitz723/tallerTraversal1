# Informe Completo de Errores de Compilación

## **1. Constructor de Vector Bidimensional Inválido (Error Principal)**

Este es el error más crítico y frecuente en toda la base de código. Aparece unas 20-30 veces entre múltiples archivos:

```
astiod.cpp:195:48: error: no matching function for call to 'std::vector<std::vector<double> >::vector(int, int)'
  195 |   std::vector< std::vector<double> > lmatii(3,3), cmat(3,3), rhomat(3,3),
      |                                                ^
```

```
astmath.cpp:1015:60: error: no matching function for call to 'std::vector<std::vector<double> >::vector(int, int)'
 1015 |       std::vector< std::vector<double> > lu(order+1,order+1);
      |                                                            ^
```

El problema radica en que no existe un constructor de `std::vector` que tome dos enteros para crear directamente una matriz. La sintaxis correcta requiere usar `.resize()` o inicialización apropiada.

## **2. Headers Faltantes**

Funciones de manipulación de cadenas no están disponibles por falta del header correspondiente:

```
asttime.cpp:46:6: error: 'strcpy' was not declared in this scope
   46 |      strcpy(monstr[1], "Jan");
      |      ^~~~~~
asttime.cpp:33:1: note: 'strcpy' is defined in header '<cstring>'; did you forget to '#include <cstring>'?
```

```
asttime.cpp:60:14: error: 'strcmp' was not declared in this scope
   60 |      while ((strcmp(instr, monstr[ktr])!=0) && (ktr <=12))
      |              ^~~~~~
```

La solución es agregar `#include <cstring>` en `asttime.cpp`.

## **3. Variables No Declaradas**

Variables específicas del sistema que no están definidas en el contexto actual:

```
testdc.cpp:58:24: error: '_argc' was not declared in this scope
   58 |    cout << "argc= " << _argc << endl;
      |                        ^~~~~
testdc.cpp:61:15: error: '_argv' was not declared in this scope
   61 |       cout << _argv[i] << endl;
      |               ^~~~~
```

Probablemente faltan includes específicos del sistema o estas variables necesitan ser definidas de manera diferente.

## **4. Directivas de Preprocesador Malformadas**

Token extra al final de la directiva include:

```
sgp4dc.h:37:75: warning: extra tokens at end of #include directive
   37 | #include "astiod.h"                                                       `
      |                                                                           ^
```

Hay un carácter backtick (`) innecesario al final de la línea que causa el warning.

## **5. Errores de Switch-Case**

Sintaxis incorrecta en declaración de casos múltiples:

```
sgp4dc.cpp:817:16: error: expected ':' before ',' token
  817 |          case 1,3 : indobs= 2;
      |                ^
      |                :
sgp4dc.cpp:817:16: error: expected primary-expression before ',' token
```

La sintaxis `case 1,3:` es inválida. Debería ser `case 1: case 3:` para casos múltiples.

## **6. Shadowing de Variables**

Variables locales que ocultan parámetros de función:

```
coordfk5.cpp:375:15: error: declaration of 'double rpef [3]' shadows a parameter
  375 |               rpef[3], vpef[3], apef[3], omgxv[3], tempvec1[3], tempvec[3];
      |               ^~~~
coordfk5.cpp:357:15: note: 'double* rpef' previously declared here
  357 |        double rpef[3], double vpef[3], double apef[3],
      |        ~~~~~~~^~~~~~~
```

Se están redeclarando variables que ya existen como parámetros de la función.

## **7. Warnings de Formato**

Inconsistencias entre especificadores de formato y tipos de datos:

```
testdc.cpp:257:52: warning: format '%d' expects argument of type 'int*', but argument 4 has type 'long int*' [-Wformat=]
  257 |                               sscanf(longstr2,"%d %d %d %d %d %d %d %d %lf ",
      |                                                   ~^
      |                                                    |
      |                                                    int*
      |                                                   %ld
```

```
testdc.cpp:1163:37: warning: format '%d' expects argument of type 'int', but argument 3 has type 'long int' [-Wformat=]
 1163 |                fprintf(outfile1," %8d  difference %11lf  %11lf  %11lf km %12lf m \n\n",satrec.satnum, dr[0], dr[1], dr[2], 1000.0 * mag(dr) );
      |                                   ~~^                                                  ~~~~~~~~~~~~~
      |                                     |                                                         |
      |                                     int                                                       long int
```

El especificador `%d` espera `int` pero recibe `long int`. Debería usarse `%ld`.