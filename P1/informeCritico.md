

## **Calidad del Código:**
* Inconsistencias severas en formato: algunos archivos usan espacios, otros tabs. No importaria mucho si no fuese porque en algunos usan identacion con espacios inpares... Tambien identacion no homogenea.
* Falta de convenciones consistentes para nombres de funciones (iau76fk5all_itrf_gcrf, twoline2rv)
* Una sola palabra: "dsvbksb"... (me gustaría dejarlo asi porque es autoexplicativo, pero por si acaso: nombres de funciones muy concentradas generadas a partir de acortaciones pegadas a la fuerza, como dsvdcmp. Si andas dentro del contexto bien, pero si sin leer el codigo ni saber contexto sabes que es un dsvbksb, llama una ambulancia, estas teniendo un ictus). Ni siquiera es el peor ejemplo

## **Reutilización y Modularidad:**
* Muchas dependencias cruzadas entre modulos. SGP4DC.h se incluye a si mismo...
* Funciones demasiado largas con multiples responsabilidades. Por ejemplo, en findatwaatwb puedo contar hasta 8 responsabilidades: Acumulacion de matrices ATWA/ATWB, cálculos matriciales y pesos, diferenciación finita, manejo de diferentes tipos de observaciones, transformaciones de tiempo, propagacion orbital SGP4, y la configuración inicial junto al loop principal de observaciones.

## **Gestión de Errores:**
* Inexistente: no hay try-catch ni validaciones (personalmente, no creo en el try-catch). Por ejemplo en finitediff no verifica el array xnom, ni state2satrec si falló, etc. En pronttle hay operaciones de formato sin validacion.
* Funciones tipo void que no retornan códigos de error (state2satrec, finitediff...).
* No hay verificacion de punteros nulos antes de usar archivos

## **Documentación:**
* Comentarios poco descriptivos en cuanto a procedimientos. Aunque esta bien indicado inputs y outputs.
* Codigo de debug mezclado con produccion sin explicacion (SGP4DC.cpp, función state2satrec, leastsquares)

## **Seguridad:**
* Uso inseguro de funciones C (strcpy, printf con format strings, gets) (!!!!)
* No hay validacion de entrada de datos (en dsvbksb no se validan las dimensiones de matrices, en findatwaatwb se aceden a arrays sin verificación)
* Posibles buffer overflows en manejo de strings (printtle: buffers de tamaño fijo vulnerables)
* Variables globales accesibles sin control (los files en testdc, cualquier funcion puede modificarlos; globales sin protección y algunas mal definidas en SGP4DC)
* Ojala los del banco santander programasen tambien así

## **Eficiencia:**
* Calculos repetitivos sin cache (Propagacion repetida en finndatwaatwb; operaciones trigonométricas repetidas en state2satrec; calculos ESTATICOS repetidos como en printtle, finitediff o leastsquares)
* Uso excesivo de printf para debug que impacta el rendimiento del programa
* No hay optimizacion de estructuras de datos (matrices ineficientes std::vector de std::vector HORRIBLE iugh, y encima creadas en cada llamada en findatwaatwb; retamañificacion de vector ineficiente, es MASIVA)

