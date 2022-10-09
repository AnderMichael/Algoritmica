# Backtracking
Un algoritmo de *backtracking* es un algoritmo que utiliza un enfoque de fuerza bruta para encontrar la solución deseada. El enfoque de fuerza bruta prueba todas las posibles soluciones y elige las soluciones buscadas o mejores.
El término *backtracking* sugiere que si la solución actual no es conveniente, entonces se retrocede un paso y se intenta con otras posibles soluciones. De este modo la recursión es usada en este enfoque. Para entender mejor la última explicación se utiliza el concepto de *árbol de espacio de estados*, este último representa todos los posibles estados (Solución o no-solución) del problema desde la raíz de un estado inicial a una hoja como un estado terminal.

![State Space Tree](https://cdn.programiz.com/sites/tutorial2program/files/ba-state-space-tree.png)

Un ejemplo de un enfoque de backtracking es el siguiente: Encontrar todas las posibles formas de posicionar 2 chicos y un chica en 3 asientos. Sin embargo, la chica no debería estar em el asiento del medio. La solución explica estos puntos: Hay $3! = 6$ posibilidades. Si se probaran recursivamente todas las posibilidades se obtendría el siguiente *árbol de espacio de estados* con las siguientes soluciones:

![State state tree](https://cdn.programiz.com/sites/tutorial2program/files/ba-state-state-tree-example.png)

No existe una implementación base para la idea de *backtracking* explicada, ya que existen diversos problemas en los que el enfoque del *backtracking* sufre muchas modificaciones para llegar al resultado esperado. Pero así también es importante recalcar que las implementaciones de *backtracking* son funcionales únicamente para problemas específicos los cuales necesitan probar distintas formas de construir la solución, podando las combinaciones inválidas. Si no se respeta esta última consideración el código será lento y pesado.

```
// Idea base en pseudocódigo
Backtrack(x)
    if x is not a solution
        return false
    if x is a new solution
        add to list of solutions
    backtrack(expand x)
```

Algunos problemas resueltos con el enfoque de backtracking:

* [Good_Morning!](https://github.com/AnderMichael/Algoritmica/blob/main/Backtracking/Problemas/E-GoodMorning.cpp)
* [Geppetto](https://github.com/AnderMichael/Algoritmica/blob/main/Backtracking/Problemas/F-Geppetto.py)

#### Referencias

https://www.programiz.com/dsa/backtracking-algorithm

Competitive Programming 3: The New Lower Bound of Programming Contests, Volumen 3. Steven Halim (2013)