// Link del problema https://open.kattis.com/problems/supercomputer
#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;
int BIT[1000001]; //  El árbol con el nodo fantasma
int bits[1000001];
int N, K, i, l, r;
char op;

void update(int posicion, int valor)
{
    for (; posicion <= N; posicion += posicion & -posicion)
    {
        BIT[posicion] += valor;
    }
}

int query(int posicion)
{
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
    scanf("%d %d", &N, &K);
    for (int j = 0; j < N; j++)
    {
        BIT[j + 1] = 0;
        bits[j + 1] = 0;
    }
    while (K--)
    {
        scanf(" %c", &op);
        if (op == 'F')
        {
            scanf("%d", &i);
            if (bits[i])
            {
                update(i, -1);
                bits[i] = 0;
            }
            else
            {
                update(i, 1);
                bits[i] = 1;
            }
        }
        else
        {
            scanf("%d %d", &l, &r);
            printf("%d\n", query2(l, r)); 
        }
    }
}
