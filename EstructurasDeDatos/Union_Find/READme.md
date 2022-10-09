# Union_Find - *Conjunto disjunto*
Union Find es una estructura de datos que modela una colección de conjuntos disjuntos (disjoint-sets) y se puede utilizar para resolver problemas de búsqueda de componentes conexos en un grafo no dirigido. Se inicializa cada vértice en un conjunto disjunto separado, después se enumera las aristas y uniones del grafo cada dos vértices/conjuntos disjuntos conectados por una arista . A continuación se podrá comprobar si dos vértices pertenecen al mismo componente/conjunto fácilmente. El número de conjuntos disjuntos que se pueden seguir con facilidad también denota el número de componentes conexos del grafo no dirigido.

Todo este procedimiento está basado en 2 operaciones:

- **Find( A ):** Determina a cual conjunto pertenece el elemento A. Esta operación puede ser usada para determinar si 2 elementos están o no en el mismo conjunto.
- **Union( A, B ):** Une todo el conjunto al que pertenece A con todo el conjunto al que pertenece B, dando como resultado un nuevo conjunto basado en los elementos tanto de A como de B.

Las operaciones pueden verse mejor gráficamente:

- **Find**

  <p align="center">
    <img src="https://jariasf.files.wordpress.com/2012/04/find0.jpg"/>
  </p>

  <p align="center">
    <img src="https://jariasf.files.wordpress.com/2012/04/find1.jpg"/>
  </p>

<p align="center">
  <img src="https://jariasf.files.wordpress.com/2012/04/find2.jpg"/>
</p>

<p align="center">
  <img src="https://jariasf.files.wordpress.com/2012/04/find3.jpg"/>
</p>

* **Union**

![img](https://jariasf.files.wordpress.com/2012/04/union2.jpg)

![img](https://jariasf.files.wordpress.com/2012/04/union3.jpg)

A más nodos la estructura se vuelve inestable debido a las consultas para encontrar al padre de cada uno de los vértices, la complejidad en el peor de los casos vendría dada por $O(n) = n$ la cual representaría una gran desventaja en tiempo si se se incrementara la cantidad de nodos hasta 1M, sin embargo, a continuación se sugieren dos propuestas para mejorar la idea que se tiene hasta ahora:

* **Compresión de Caminos**: Al momento de retornar la raíz en la recursión actualizamos el padre de cada vértice visitado como la raíz encontrada.

* **Unión por rango**: Se logra observar en el gráfico:
  ![img](https://jariasf.files.wordpress.com/2012/04/union6rank.jpg)

  La altura del nuevo árbol es 2, este método mantiene el árbol tan balanceado como sea posible, para mayor número de vértices se verá la diferencia en cuanto a la eficiencia. *Asimismo puede decirse que el rango del vértice raíz de una componente conexa es la altura de dicha componente.*

Con todo esto se tiene el código base:

* [Union_Find_R.cpp](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/Union_Find/Union_Find_R.cpp) *Código con mejoras*
* [Union_Find_WR.cpp](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/Union_Find/Union_Find_WR.cpp) Código de la idea base (sin mejoras)

Así también se puede apreciar la aplicación de este algoritmo en el problema adjunto al directorio del algortimo:

* [Anasi_Cobweb.cpp](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/Union_Find/Anasi_Cobweb.cpp)

#### Referencias (imágenes y recursos)

https://www.hackerearth.com/practice/notes/disjoint-set-union-union-find/

https://jariasf.wordpress.com/2012/04/02/disjoint-set-union-find/

Competitive Programming 3: The New Lower Bound of Programming Contests, Volumen 3. Steven Halim (2013).
