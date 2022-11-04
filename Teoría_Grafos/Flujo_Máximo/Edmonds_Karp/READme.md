# Algoritmo Edmonds Karp
El algoritmo de Edmonds-Karp no es más que una concreción del método de Ford Fulkerson en el que la búsqueda de los caminos aumentados se realiza mediante una búsqueda
primero en anchura *(breath-first search, BFS)* y para el que, por cada iteración del método, se ha decidido aumentar el flujo, a través del camino aumentado, en la capacidad residual, $cf (p)$.
<p align="center">
<img src="https://user-images.githubusercontent.com/101998948/199869346-85f9b1d1-f7d5-447e-8c0d-d99f4d585684.png">
</p>
Puede demostrarse que el número de aumentos en el flujo realizados por este algoritmo hasta hallar el flujo máximo es $O(|V||E|)$. Si además consideramos que encontrar un camino aumentado tiene un coste $O(|E|)$ utilizando BFS, entonces podemos concluir que el tiempo de ejecución del algoritmo de Edmonds-Karp es $O(|V||E|^2)$. 

## Problemas

- [Software_Allocation](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_Grafos/Flujo_M%C3%A1ximo/Edmonds_Karp/Problemas/SoftwareAllocation.cpp)
- [Internet_Bandwidth](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_Grafos/Flujo_M%C3%A1ximo/Edmonds_Karp/Problemas/InternetBandwidth.cpp)

## Código Base

- [Karp:algorithm](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_Grafos/Flujo_M%C3%A1ximo/Edmonds_Karp/Karp_Algorithm.cpp)

## Referencias
https://eprints.ucm.es/id/eprint/16752/1/Memoria_TFM.pdf
https://www.topcoder.com/thrive/articles/A%20New%20Approach%20to%20the%20Maximum%20Flow%20Problem
https://programmerclick.com/article/3654584570/
