## Hopcroft-Karp

## **Motivación .-**
El algoritmo de Hopcroft-Karp puede verse como un caso especial del algoritmo de Dinic para el problema de flujo máximo. Esto es debido a que en vez de usar un grafo con distintas capacidades, solo tomamos como si tuviera cada conexión una capacidad de 1. 

Gracias a ello podemos encontrar la máxima cantidad de emparejamientos entre dos grupos de datos representados como nodos como en un *grafo bipartito*.

Una posible aplicación para el problema de emparejamiento bipartito es la asignación de estudiantes a los trabajos disponibles. El problema se puede modelar utilizando un grafo bipartito: los estudiantes y los trabajos están representados por dos conjuntos disjuntos de nodos. Las aristas representarán las posibles asignaciones. El objetivo es encontrar tantas asignaciones válidas como sea posible, de modo que cada estudiante sólo pueda tomar un trabajo y cada trabajo solo pueda ser realizado por un solo estudiante.
## **Descripción.-**
Antes de comenzar con la descripción general del algoritmo propuesto en este informe, se presentan brevemente las definiciones de un grafo bipartito:

- Un grafo G=(V,E) es *bipartito* si y solo si, no es dirigido y si se tiene una partición de dos conjuntos de vértices, $V1$ y $V2$, tal que toda arista del conjunto E esté formada por un vértice de cada subconjunto $(E⊆ V1 × V2)$.
- Se sabe que grafo G no puede ser *bipartito* si este contiene ciclos de longitud impar.

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 001](https://user-images.githubusercontent.com/101998948/200096488-3a35697c-8571-4ee0-865e-6385b7c8db80.png) ![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 002](https://user-images.githubusercontent.com/101998948/200096519-f585c31d-6415-4efb-89fa-cb6d19f848af.png)

Un grafo *bipartito*. Con $V1={A,B,C}$ y $V2={D,E,F,G}$.

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 003](https://user-images.githubusercontent.com/101998948/200096542-06bcab4b-77de-4244-9840-1b38210d5420.png)

Un grafo que no puede ser *bipartito.*

El algoritmo **Hopcroft-Karp** o algoritmo **Hopcroft-Karp-Karzanov** es un algoritmo que toma un grafo bipartito como entrada y da de resultado una coincidencia de cardinalidad máxima. Es decir, la máxima cantidad de emparejamiento entre dos nodos.

Para este tipo de problemas necesitan encontrar el máximo provecho en usar dos grupos y relacionarlos de uno a uno. 

Se utiliza este algoritmo iniciando con los datos de qué relaciones se pueden generar entre estos dos grupos. Después se usa una estructura para guardar las conexiones ya realizadas que generan el máximo emparejamiento. Si al finalizar hay nodos que no están conectados; se hará una búsqueda entre las otras opciones de las parejas ya conectadas y así organizar de nuevo las conexiones para hallar el número máximo.
## **Algoritmo.-**
El algoritmo inicia de la siguiente forma:

1. Se tiene un arreglo M donde se guardan las conexiones; inicialmente empezará en 0.
2. Se usará el grupo con menos nodos para conectarlos con el grupo con más nodos. 
3. Un nodo se conectará con el primero que encuentre disponible y se guardará la conexión en M. Una vez que eso pase, ya se marcará como visitado ambos nodos para que no puedan conectarse con otro nodo. Se repetirá el proceso hasta que ya no haya más conexiones posibles. 
4. Después, se verifican los nodos que no pudieron conectarse. Para ello se hará una búsqueda de anchura para encontrar si entre las conexiones guardadas en M se pueden modificar para que el otro nodo se conecte y así agregar más conexiones en M. Se realizará este procedimiento hasta que el máximo valor de M sea igual al menor grupo de los nodos o hasta que no se pueda encontrar alguna conexión para los nodos sin pareja.
5. Se muestra la cantidad de conexiones guardadas en M. Ya sea el número de conexiones o las conexiones. En cualquier caso, dará su valor máximo.

Para una mejor demostración del algoritmo se cita el siguiente ejemplo para un mejor entendimiento:

1. Se tiene el siguiente grafo GE bipartito:

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 004](https://user-images.githubusercontent.com/101998948/200096621-b8c74c0a-f745-497c-b663-dc25c4a1cbf0.png)

GE está conformado por dos conjuntos de vértices U y V.

2. Se comienza haciendo una búsqueda por anchura de por todo el conjunto de aristas U.

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 005](https://user-images.githubusercontent.com/101998948/200096634-8f7491db-6e20-4f09-914b-93893ed7b555.png)

Búsqueda por anchura en GE del conjunto U al conjunto V.

3. Ahora se realiza una búsqueda por profundidad con los vértices del conjunto V al conjunto U. Esto para emparejar dos vértices.

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 006](https://user-images.githubusercontent.com/101998948/200096653-97c6ee34-10a5-4b2c-ae67-74962f3dfd49.png)

Búsqueda por profundidad en GE del conjunto V al conjunto U. Comenzando por V1.

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 007](https://user-images.githubusercontent.com/101998948/200096661-b8836bee-7e0c-469f-b347-6999cd353978.png)

Una vez emparejados dos vértices estos son retirados de todas las subramas exploradas.

4. El proceso se repite hasta que solo sobren dos vértices de cada conjunto:

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 008](https://user-images.githubusercontent.com/101998948/200096695-a313d6d3-ff76-4da9-bc05-f4d5c8cf354d.png)

Búsqueda por profundidad en GE del conjunto V al conjunto U. Continuando con V2.

5. Se borran todos los nodos ya emparejados y sobran los siguientes vértices:

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 009](https://user-images.githubusercontent.com/101998948/200096712-bc6a84db-ab07-4c23-86e7-e85dabcab6e6.png)

6. Entonces el grafo original terminaría de la siguiente manera:

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 010](https://user-images.githubusercontent.com/101998948/200096749-af5d6b42-c58f-432c-9d97-54201ba313a5.png)

Grafo original con emparejamientos obtenidos en las distintas búsquedas.

7. Se repite el mismo proceso para el subgrafo que parte desde el vértice sobrante de U, haciendo búsqueda por anchura, hasta el vértice sobrante de V, pasando solamente por los vértices emparejados. Se tiene lo siguiente:

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 011](https://user-images.githubusercontent.com/101998948/200096772-d08e3e62-b457-476b-b7f0-7dc9e0534eed.png)

Subgrafo de U2 a V3 pasando solo por los vértices emparejados.

8. Se aplica el camino de aumento (llenar el flujo residual del grafo residual) a el subgrafo mostrado en la parte superior, lo cual resultaría en:

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 011](https://user-images.githubusercontent.com/101998948/200096798-ae91673d-cfe2-4efa-87bb-48902a7340a5.png) ![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 012](https://user-images.githubusercontent.com/101998948/200096832-0a0e9187-4b8d-4f1a-9906-bfa2f84ea113.png)


9. El grafo emparejado resultaría finalmente en:

![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 014](https://user-images.githubusercontent.com/101998948/200096950-e7172902-6184-417c-ad19-fecb5e78e5fe.png)
 ![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 013](https://user-images.githubusercontent.com/101998948/200096889-632d0831-da96-4773-950d-9ae186a919ea.png)

## **Análisis de Complejidad.-**
![Aspose Words 863bcb6b-df9e-4aad-ba89-b59c46db9b0a 015](https://user-images.githubusercontent.com/101998948/200096930-51f2bf09-dbf5-46fb-925d-c7c7afbea8fc.png)

1. Los pasos de 2 a 5 se repetirán dependiendo de la cantidad de los nodos que tengan en total los dos grupos. Por ese motivo, la cantidad de veces que vayamos a probar los nodos hasta llegar al punto en que el menor grupo de nodos sea igual a M o si no se pueden realizar más conexiones. Por ese motivo la cantidad de veces que repetiremos este proceso será raíz de la cantidad de nodos.O(nodos)
2. Luego dentro del bucle podemos ver que necesitaremos un BFS para hacer las primeras conexiones para conectarlas a M. Después, para buscar nuevas conexiones para los nodos que no hayan sido conectados se usará un DFS.  Para eso la complejidad máxima que usará para ambas búsquedas será la cantidad de posibles conexiones. O(aristas)

## Código base

[Hopcroft-Karp](https://github.com/AnderMichael/Algoritmica/blob/main/Teor%C3%ADa_Grafos/Flujo_M%C3%A1ximo/HopcroftKarp/HopcroftKarp.cpp)

Como es dentro de un bucle la complejidad del algoritmo es: O(an).
## **Ejercicio.-**
[**10080 - Gopher II**](https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1021)

El siguiente ejercicio proviene del Juez Virtual UVA. 

El ejercicio trata de un halcón llegó a la zona donde residen un grupo de roedores. Para escapar del halcón deciden entrar a agujeros que solo un roedor puede entrar. La tarea consiste en conseguir el mínimo número de roedores vulnerables. En otras palabras, se debe encontrar la mayor cantidad de roedores que pudieron esconderse y restarlo por el número total para así saber cuántos son vulnerables.
### **Bibliografía.-**
<https://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-1-introduction/>

<https://www.geeksforgeeks.org/hopcroft-karp-algorithm-for-maximum-matching-set-2-implementation/>

<https://brilliant.org/wiki/hopcroft-karp/>

<https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm>

<https://algorithms.discrete.ma.tum.de/graph-algorithms/matchings-hopcroft-karp/index_en.html>

<http://uva.outsbook.com/problemhints/problemdetails/100/10080>


**Videos de Referencia:** 

[Sobre_GrafosBipartitos](https://www.youtube.com/watch?v=0Kb4r1oLMbY)

[Hopcroft-Karp Algorithm](https://www.youtube.com/watch?v=CSUEVu-qUgM)

[Hopcroft–Karp algorithm](https://www.youtube.com/watch?v=lM5eIpF0xjA&list=LL&index=3)

[Hopcroft - Karp Brilliant](https://www.youtube.com/watch?v=pJHdqbxvZOI)
