# Algoritmo de Kruskal

La teoría de grafos es un campo muy extenso para estudiar, debido a la cantidad de problemas que tienen estas estructuras compuestas de nodos y vértices. Entre estos últimos se encuentra el problema del MST (Árbol de expansión mínimo): Dado un grafo conexo, no dirigido y ponderado $G$, sleccionar un conjunto de aristas $E´ \in G$ de forma que el grafo $G$ se mantenga conexo y que el peso total de las aristas seleccionadas sea mínimo.

Pueden haber varios árboles de expansión válidos en $G$, incluyendo los árboles de expasión DFS y BFS (Conceptos básicos). Entre los árboles de expansión posibles de G, hay algunos (al menos uno) que satisface el criterio de peso mínimo o máximo.

Existen varios métodos para obtener el MST, entre estos se encuentra el *Algortimo de Kruskal*, el cúal consiste en: Ordenar las $E$ aristas en base al peso no decreciente. En el código del presente repositorio se crea una estructura denominada *Arista*, la cual contiene: El origen, el destino y el peso correspondiente. Estos último son introducidos a un arreglo de tamaño $m$ (Cantidad de aristas), todas las aristas introducidas en el arreglo son ordenadas gracias al método `sort()` con el que cuentan varios lenguajes de programación. Para configurar la manera de ordenar las aristas, en el código del presente repositorio se hizo uso de la *sobrecarga de operadores con el signo <* (Configurar un criterio de ordenación con los atributos de la estructura).

Luego, gracias a lo último, se comienzan a unir los nodos con la implementación de [conjuntos disjuntos](https://github.com/AnderMichael/Algoritmica/tree/main/EstructurasDeDatos/Union_Find), todo como una forma de marcarlos como **visitados¨** la primera vez que se pase por ellos y así evitar los ciclos, cada vez que un nodo tenga un padre diferente al valor de sí mismo entonces ya no podrá unir a otro que tenga el mismo padre.

Se recorre evaluando todo el arreglo de aristas y finalmente se llega a un árbol de expasión mínimo, cabe aclarar que se puede llegar de la misma manera al árbol de expansión máximo configurando el criterio contrario en la sobrecarga de operadores. He aquí un pequeño ejemplo gráfico:

![image](https://user-images.githubusercontent.com/101998948/197396485-91f5b39a-03a5-4947-985c-29847c77cb91.png)

Para finalizar, Kruskal almacena el grafo de una sola forma, no importa cómo introduzcamos el grafo al algoritmo, el resultado siempre será el mismo a menos que se cambien los pesos.

## Problemas

- [ReconnectingComputerSites](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_Grafos/Algoritmo_Kruskal/Problemas/ReconnectingComputerSites.cpp)
- [Freckles](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_Grafos/Algoritmo_Kruskal/Problemas/Freckles.cpp)

## Referencias

https://www.simplilearn.com/tutorials/data-structure-tutorial/kruskal-algorithm

Competitive Programming 3: The New Lower Bound of Programming Contests, Volumen 3. Steven Halim (2013)
