# BIT (Binary Indexed Tree) - *Árbol binario indexado*
*BIT (Binary Indexed Tree)* o *Árbol binario indexado* es una estructura de datos muy útil para representar un array de números en otro, permitiendo las sumas de elementos entre posiciones del arreglo original de una forma eficiente. Para constituir esto último se considera las siguientes operaciones para el uso del BIT dado un array $A$:

1. Cambiar el valor guardado en el índice $i$ (También es conocido como *update*).
2. Encontrar la suma de una posición a otra en el arreglo (También es conocido como *query*).

Ambas operaciones deben efectuarse en tiempo $O(n) = log_2 n$, entonces por qué tener en cuenta otra estructura cuando un [*Segment Tree*](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/SegmentTree/READme.md) podría hacer lo mismo en la misma complejidad. Es porque un BIT requiere de menos espacio y es más fácil de implementar durante los concursos de programación competitiva (el código no engloba más de 8-10 líneas). Puede inferirse para esta parte el uso principal de un BIT que es implementar *tablas de frecuencia acumulada dinámicas*.

Las operaciones son extremadamente eficientes, ya que se utilizan técnicas rápidas de manipulación de bits. Se hace uso del bit menos significativo que en el código base de este repositorio vendría representado por `i & -i`. Como se sabe que le árbol está indexado por los bits de sus claves enteras las cuales se encuentra en el rango $[1..n]$ no utilizando el índice 0. Con la manipulación de bits mencionada será posible desplazarse a través del BIT para obtener los resultados requeridos con las operaciones básicas. Para visualizar mejor estas ideas se presenta un ejemplo de BIT  en imágenes:

- Dado un array $A = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16]$. Para facilitar el ejemplo el array $A$ se indexa desde 1 añadiendo el 0 en la posición $A[0]$.

![enter image description here](https://he-s3.s3.amazonaws.com/media/uploads/68f2369.jpg)

Con estos simples pasos y la idea principal se obtiene el siguiente código base:

* [bit.cpp](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/BIT/bit.cpp)

## Problemas
- [MovieCollection](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/BIT/Problemas/MovieCollection.cpp)
- [Supercomputers](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/BIT/Problemas/Supercomputers.cpp)
- [Turbo](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/BIT/Problemas/Turbo.cpp)
## Referencias

https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/tutorial/

Competitive Programming 3: The New Lower Bound of Programming Contests, Volumen 3. Steven Halim (2013)

