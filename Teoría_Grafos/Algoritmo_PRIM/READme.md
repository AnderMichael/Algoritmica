# Algoritmo de PRIM

La teoría de grafos es un campo muy extenso para estudiar, debido a la cantidad de problemas que tienen estas estructuras compuestas de nodos y vértices. Entre estos últimos se encuentra el problema del MST (Árbol de expansión mínimo): Dado un grafo conexo, no dirigido y ponderado $G$, sleccionar un conjunto de aristas $E´ \in G$ de forma que el grafo $G$ se mantenga conexo y que el peso total de las aristas seleccionadas sea mínimo.

Pueden haber varios árboles de expansión válidos en $G$, incluyendo los árboles de expasión DFS y BFS (Conceptos básicos). Entre los árboles de expansión posibles de G, hay algunos (al menos uno) que satisface el criterio de peso mínimo o máximo. Entre estos está el algoritmo de PRIM, el cual se basa en el uso de una cola de prioridad.
