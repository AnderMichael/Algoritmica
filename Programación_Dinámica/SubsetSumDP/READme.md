# Subset Sum DP

Para introducir el presente algoritmo es necesario hacer cita del siguiente problema: 

#### Subset Sum Problem (SSP)

Este es un problema de decisión de las ciencias computacionales. En su formulación general, encontrar un subconjunto del conjunto $S$ cuya suma es precisamente un número $T$. Este problema pertenece a la categoría NP-Hard y NP, por lo que también representa un NP-Complete.

Resolver este problema conlleva más razonamiento del que se estima para los casos de prueba más simples. En el repositorio presente se tienen dos métodos de resolución: *Por recursividad* o *por programación dinámica.*

##### Con programación dinámica (Uso de la *Memoization*)

Gracias a la técnica de la *memoization* los casos redundantes ya no son calculados, por lo que la complejidad se verá reducida. Se hará uso de una tabla de resultados 2-D para el cometido explicado, los estados para las filas y columnas serán los *valores del conjunto $S$* (No ordenados necesariamente) y los *valores de la suma hasta $T$* respectivamente.

La tabla comenzará con un llenado inicial que abarcará el primer caso como si se tratase de una primera evaluación para ver qué números pueden conformarse, ya para los otros casos se verá el resultado de la fila anteirior o se evaluará si el número ya pudo ser conformado con anteiroridad, al final será devuelto el valor de verdad de la última casilla en la esquina infeiror derecha, como se puede observar en la figura. Debido a la forma de la tabla y el proceso de llenado la complejidad vendrá dada por $O(n+sum) = n \dot sum$ donde n representa la cantidad de elementos en el conjunto $S$ y sum los posibles valores que pueden ser conformados a través de la suma de componentes.

![image](https://user-images.githubusercontent.com/101998948/197376119-e889b1c7-dd04-4804-bc69-c1d5c543c090.png)

![image](https://user-images.githubusercontent.com/101998948/197376126-8bf6d532-fa9c-4d30-89f6-733a306436a9.png)

##### Con recursividad (Árbol de Backtracking)

La idea principal para este método es considerar todos los subconjuntos de elementos y determinar que existe un subconjunto cuya suma de sus elementos sea $T$.

Cada vez que consideramos un elemento, se tiene una de las siguientes opciones:
1. El item elegido será incluido en el subconjunto óptimo, descontando a la suma el valor del elemento.
2. El elemento puede no ser incluido en el subconjunto óptimo, conservando las operaciones realizadas hasta entonces.

Si la suma es igual a 0 después de evaluar todos o cierta cantidad de elementos entonces existirá una respuesta positiva, de lo contrario negativa.

![image](https://user-images.githubusercontent.com/101998948/197376819-a9a7ff69-3558-4c4c-974d-9bfd6455387e.png)
