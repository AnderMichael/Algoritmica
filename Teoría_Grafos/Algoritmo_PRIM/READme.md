# Algoritmo de PRIM

La teoría de grafos es un campo muy extenso para estudiar, debido a la cantidad de problemas que tienen estas estructuras compuestas de nodos y vértices. Entre estos últimos se encuentra el problema del MST (Árbol de expansión mínimo): Dado un grafo conexo, no dirigido y ponderado $G$, sleccionar un conjunto de aristas $E´ \in G$ de forma que el grafo $G$ se mantenga conexo y que el peso total de las aristas seleccionadas sea mínimo.

Pueden haber varios árboles de expansión válidos en $G$, incluyendo los árboles de expasión DFS y BFS (Conceptos básicos). Entre los árboles de expansión posibles de G, hay algunos (al menos uno) que satisface el criterio de peso mínimo o máximo. Entre estos está el algoritmo de PRIM, el cual se basa en el uso de una cola de prioridad.

El algoritmo de PRIM comienza desde cualquier nodo perteneciente al grafo $G$ del cuál se busca el árbol de expansión mínimo o máximo, se coloca a el primer nodo como visitado y se introducen sus vecinos en orden(gracias a la cola de prioridad), es importante señalar que al igual que el [algoritmo de Kruskal] () el algoritmo prensente en este repositorio cuenta con una modificación para el operador < (criterio de ordenamiento de la estructura *Arista*) .
El procedimiento continúa para todos los nodos que no hayan sido visitados aún, cuando no exista algún otro nodo para visitar se vacía la cola de prioridad y se muestra el árbol de expansión mínimo obtenido. 
![image](https://user-images.githubusercontent.com/101998948/197690909-68a32621-1a43-490d-8c21-6065505018cd.png)

La primera diferencia con Kruskal es que el árbol de expansión mínimo está guardado de una manera diferente y en PRIM solo se ordenan las aristas a medida que se vayan introduciendo, no como en Kruskal todas en conjunto.
La implementación de este algoritmo se encuentra en el siguiente enlace:

- [Algoritmo_PRIM](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_Grafos/Algoritmo_PRIM/PRIM_Algorithm.cpp)

## Problemas

- [SendingEmail](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_Grafos/Algoritmo_PRIM/Problemas/SendingEmail.cpp)

## Referencias

https://es.wikipedia.org/wiki/Algoritmo_de_Prim

Competitive Programming 3: The New Lower Bound of Programming Contests, Volumen 3. Steven Halim (2013)
