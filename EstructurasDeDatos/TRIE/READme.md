# TRIE
El trie (también conocido como *árbol de prefijos*) es una estructura de datos muy útil para resolver problemas asociados con strings. El problema mas conocido es dado una colección de palabras (algo como un diccionario) y una palabra en particular, saber si la palabra se encuentra en la colección de palabras.

Existen varias formas de construir la estructura, estas varían entre usar estructuras `struct` o clases `class`, sin embargo, el repositorio presente contiene la construcción basada en estructuras. Para empezar, la nueva estructura basada en *nodos* cuenta con los siguientes tres atributos importantes para cada uno: "El caracter correspondiente al nodo, los nodos hijos y un atributo que identifique al nodo actual como el final de una palabra". 

Realizando la implementación vista en el código base, se tiene como resultado final a un árbol como en el siguiente gráfico:

<p align="center">
  <img src="https://prodeportiva.files.wordpress.com/2013/02/triea.png?w=604" alt="Trie construido con distintas palabras"/>
</p>

Las estructuras base para consultar los hijos de un árbol también tienen 2 variaciones: El *array* y el *map*. Con ambas estructuras se llega a lo mismo, pero con diferentes complejidades, $O(n) = n$ y $O(n) = n\log_{2}(n)$ respectivamente en cada una de las operaciones (la búsqueda es primordial).

Los métodos principales para un manejo básico son: Insertar palabra, borrar palabra y buscar palabra. Los cuales vienen en las implementaciones del repositorio como: `insertWord`, `deleteWord` y `searchWord`.

Códigos base de esta estructura:
* [TriesArray.cpp](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/TRIE/TriesArray.cpp)
* [TriesMap.cpp](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/TRIE/TriesMap.cpp)

## Problemas

Implementación del método `delete` y la resolución de algunos problemas como ser la búsqueda de frases utilizando el contenido del TRIE y la búsqueda de palabras dada una sopa de letras.
* [TriesArray_implementations.cpp](https://github.com/AnderMichael/Algoritmica/blob/main/EstructurasDeDatos/TRIE/TriesArray_implementations.cpp)

## Referencias

https://www.topcoder.com/thrive/articles/Using%20Tries

https://prodeportiva.wordpress.com/2013/02/13/trie-arbol-prefijos/
