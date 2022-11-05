# Segment Tree - *Árbol de segmentos*
*Segment Tree* o un *Árbol de Segmentos* es básicamente un árbol binario usado para guardar los intervalos o segmentos. Cada nodo en el *Segment Tree* representa un intervalo. Una idea tan simple como esta puede responder, de forma eficiente, a consultas de rango dinámicas. Una de esas consultas de rango la encontraremos en el problema de buscar el índice del elemento mínimo en un array dentro del rango $[i..j]$ . Un algoritmo trivial consiste en iterar el array desde el índice $i$ hasta $j$, e informar del que tiene el valor mínimo, pero esto se ejecuta en tiempo $O(n)$ o lineal por consulta. Si $n$ es grande y requiere muchas consultas este último algoritmo es inviable.
Entonces para construir la estructura propuesta se consideran los siguientes puntos para un array $A$ dado de tamaño $n$  y un correspondiente *Árbol de segmentos* $T$:

1. La raíz de $T$ representa todo el array en conjunto $A[0:n-1]$.
2. Cada hoja en el *Árbol de segmentos* $T$ representa un elemento.
3. Los nodos internos del *Árbol de segmentos* representan la unión de elementos en el intervalo $A[i:j]$ donde $0 < i < j < n$.

La raíz del *Árbol de segmentos* representa a todo el array $A[0:n-1]$ en conjunto. El siguiente paso para la construcción es dividir en dos intervalos o segmentos tal que representen $A[0:(n-1)/2]$ y $A[(n-1)/2 + 1:(n-1)]$. Así que en cada paso, el segmento es dividido en dos hijos que representan esas dos mitades pero en términos del segmento padre. La altura del *Árbol de segmentos* será $log_2 (n)$. El número total de nodos es $2n -1$.

![enter image description here](https://he-s3.s3.amazonaws.com/media/uploads/a0c7f90.jpg)

![enter image description here](https://he-s3.s3.amazonaws.com/media/uploads/aad673e.jpg)

Un detalle importante para tener en cuenta es que una vez que el *Árbol de segmentos* es construido, su estructura no puede ser cambiada. Pueden actualizarse el valor de los nodos pero sin modificar la estructura. El *Árbol de segmentos* cuenta con las siguientes operaciones básicas para su uso en distintos problemas:

* Update - Actualizar: Al actualizar un elemento del array A y reflejar el cambio correspondiente en todo el árbol.
* Query - Consulta: En esta operación se puede consultar por un intervalo o segmento y devolver una respuesta al problema (operaciones correspondientes a una estructura algebraica "Monoide").

Estas últimas pueden observarse en el código base del *Árbol de segmentos* de este repositorio:

* [SegmentTree.cpp](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/SegmentTree/SegmentTree.cpp)

## Problemas

- [Skyline](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3673)
- [Ahoy, Pirates!](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2397)

## Referencias

https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/

Competitive Programming 3: The New Lower Bound of Programming Contests, Volumen 3. Steven Halim (2013)
