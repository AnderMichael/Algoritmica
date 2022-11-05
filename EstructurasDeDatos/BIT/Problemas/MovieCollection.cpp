// Link del problema https://open.kattis.com/problems/moviecollection
#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;
int t, m, r;
int BIT[200001];
int pos[100001];
void update(int posicion, int valor)
{
    for (; posicion <= m + r; posicion += posicion & -posicion)
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
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &m, &r);
        for (int i = 1; i <= m + r; i++)
        {
            BIT[i] = 0;
        }
        for (int i = 0; i < m; i++)
        {
            update(i + 1, 1);
        }
        for (int i = m; i > 0; i--)
        {
            pos[i] = m - i + 1;
        }
        int movie;
        while (r--)
        {
            scanf("%d", &movie);
            if (pos[movie] != m)
            {
                printf("%d ", query2(pos[movie] + 1, m));
                update(pos[movie], -1);
                m++;
                pos[movie] = m;
                update(m, 1);
            }
            else
            {
                printf("%d ", 0);
            }
        }
        printf("\n");
    }
}
