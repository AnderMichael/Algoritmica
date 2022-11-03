# Digit DP
Se busca resolver el siguiente problema:

*¿Cúantos números desde $a$ hasta $b$ cumplen una condición dada?*
  
Entonces los problemas que tengan la forma del enunciado mostrado pueden resolverse con *DigitDP* para esta pequeña introducción se hará uso del siguiente enunciado de ejemplo: ¿Cúantos números entre 1 y 100 cumplen que la suma de sus dígitos es un número primo?

Se toman en cuenta las siguientes consideraciones:
- Un enfoque de fuerza bruta no sería el más indicado para iterar entre 1 y n (mayor a $10^5$), y verificar si la suma de sus dígitos es un número primo, obviamente sería muy lento.
- La suma de dígitos de un número no debería exceder $180$ para $18$ dígitos, por lo que se tendrá solamente 180 estados los cuales guadarán tiempo y memoria. Esta es la idea clave detrás de la mayoría de los problemas $DigitDP$: Identificar y manejar una propiedad la cual es finita y ayuda a alcanzar la respuesta. 
- Entonces teniendo una función $f(x)$ la cual retorna todos los números que cumplen la propiedad del problema en el rango $[0,x]$. Más adelante se hará uso de $f(R)- f(L-1)$ para encontrar la respuesta final.

Ahora se presentan deatlles importantes del código:

- Se declara el siguiente arreglo `dp[20][2][200]`.

20 $\rightarrow$ máximo número de dígitos que puede soportar el arreglo (18 para ser preciso).
2 $\rightarrow$ condición de tope.
200 $\rightarrow$ suma máxima posible de los dígitos de un número.

Para un mejor entendimiento los índices, se piensa en los índices de la siguiente manera:

``
dp [posición][tope][suma]
``

¡Se trata de un juego de acumuladores!

![image](https://user-images.githubusercontent.com/101998948/197392143-dea78450-5c22-4fe7-a975-97452a91920d.png)


¿Qué es el *tope*?
Para todos los estados de `dp` siempre será necesario saber si el sufijo actual formado incluye todos los números limitados o solo los números menores o iguales al sufijo de entrada. Esta información es requerida porque cuando se anteponen dígitos para construir `dp[pos]` desde `dp[pos+1]` debe elegirse entre los números limitados y no limitados basándose en el dígito actual. En otras palabras, dividiendo la explicación en subproblemas:

$$
dp[pos][0][sum]=\sum_{d=0}^{9}dp[pos+1][0][sum−d]
$$

$$
dp[pos][1][sum]=dp[pos+1][1][sum−numero[pos]+\sum_{d=0}^{numero[pos]−1}dp[pos+1][0][sum−d]
$$

Puede concluirse que $DigitDP$ es una excelente forma de resolver problemas basados en el enunciado del principio. Se pueden agregar más estados y criterios medida que se avance en el problema.

## Problemas (Distintos enfoques)

- [DigitDP-SumaDígitos](https://github.com/AnderMichael/Algoritmica/blob/main/Programaci%C3%B3n_Din%C3%A1mica/DigitDP/DigitDP-DigitSum.cpp)
- [DigitDP-DigitoCondición](https://github.com/AnderMichael/Algoritmica/blob/main/Programaci%C3%B3n_Din%C3%A1mica/DigitDP/DigitDP-DigitIn.cpp)

## Referencias

https://codeforces.com/blog/entry/77096

