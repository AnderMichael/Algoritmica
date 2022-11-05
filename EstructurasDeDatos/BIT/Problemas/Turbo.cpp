// Link del problema https://open.kattis.com/problems/turbo
#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;

int BIT[100001];
int N, a;

void update(int posicion, int valor)
{
    for (; posicion <= N; posicion += posicion & -posicion)
    {
        BIT[posicion] += valor;
    }
}

int query(int posicion)
{ // F(3)
    int result = 0;
    for (; posicion > 0; posicion -= posicion & -posicion)
    {
        result += BIT[posicion];
    }
    return result;
}

int query2(int inicio, int final)
{
    return query(final) - query(inicio - 1);
}

int main()
{
    input;
    scanf("%d", &N);
    int pos[N + 1];
    for (int i = 0; i < N; i++)
    {
        update(i + 1, 1);
        scanf("%d", &a);
        pos[a] = i + 1;
    }
    bool left = true; // Para iterar de izquierda a derecha
    int lpos, i = 0, rep = N;
    while (rep--)
    {
        if (left)
        {
            lpos = pos[i + 1];
            printf("%d\n", query2(1, lpos - 1)); // Para comenzar desde 1 (el extremo izquierdo) hasta un número antes de la posición
        }
        else
        {
            lpos = pos[N - i];
            printf("%d\n", query2(lpos + 1, N)); // Para llegar hasta el extremo derecho desde un número dspués de la posición
            i++;
        }
        update(lpos, -1);
        left = !left;
    }
}
