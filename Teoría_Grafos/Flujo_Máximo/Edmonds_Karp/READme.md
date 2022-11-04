# Algoritmo Edmonds Karp
El algoritmo de Edmonds-Karp no es más que una concreción del método de FordFulkerson en el que la búsqueda de los caminos aumentados se realiza mediante una búsqueda
primero en anchura (breath-first search, BFS) y para el que, por cada iteración del método,
se ha decidido aumentar el fujo, a través del camino aumentado, en la capacidad residual,
$cf (p)$.


## Problemas

- [Software_Allocation](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_Grafos/Flujo_M%C3%A1ximo/Edmonds_Karp/Problemas/SoftwareAllocation.cpp)
- [Internet_Bandwidth](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_Grafos/Flujo_M%C3%A1ximo/Edmonds_Karp/Problemas/InternetBandwidth.cpp)

## Referencias
https://eprints.ucm.es/id/eprint/16752/1/Memoria_TFM.pdf
