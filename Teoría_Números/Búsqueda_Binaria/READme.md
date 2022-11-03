# Búsqueda Binaria

Encontrar un elemento en un array ordenado es más que solamente evaluar cada uno de los componentes de la estructura, eso conllevaría un tiempo lineal $O(n) = n$. Existe otro algoritmo de búsqueda denominado "Búsqueda binaria" , el cuál consiste en ir dividiendo el arreglo en partes iguales e ir explorando cada vez en partes más especificas hasta llegar al elemento buscado, eso está estimado en $O(n) = \log(n)$.

Supongamos un arreglo $A=[3, 7,9,10,23,41,100]$ y se desea localizar el elemento 7, el procedimiento conduce a una primera evaluación dividiendo el array por la mitad y tomando el elemento del centro, el cuál sería el 10. 10 no es menor igual que 7 por lo tanto los elementos hacia la derecha quedarían descartados así como el 10, entonces el proceso de segmentación continúa, ahora se tiene el subarreglo $A_{1} = [3,7,9]$, el nuevo elemento del medio sería el 7. 7 es menor o igual a 7, sin embargo, aún no se llegó a un elemento en concreto por lo que la búsqueda continúa. Finalmente el nuevo elemento del arreglo vendría a ser el 3, pero este es menor al número original, por lo que la respuesta del algoritmo a la búsqueda devolvería el siguiente número y por ende al 7.

![image](https://user-images.githubusercontent.com/101998948/197692247-e9df6f63-4f2e-4cef-beed-b68bbdcffc9f.png)

Se cree que para hacer búsqueda binaria se necesita si o sí de un arreglo ordenado. Sin embargo, varios problemas pueden resolverse sin la necesidad de crear y llenar arreglos ordenados. Bastaría con suponer el mismo arreglo pero únicamente manejar indices y números para llegar a la misma respuesta.

El algoritmo en ese repositorio viene dado por:

- [Búsqueda binaria](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_N%C3%BAmeros/B%C3%BAsqueda_Binaria/BinarySearch.cpp)

Referencias

http://codigomaldito.blogspot.com/2005/11/busqueda-binaria.html

https://www.geeksforgeeks.org/binary-search/
