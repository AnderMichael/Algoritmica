#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int BIT[10001]; //  El árbol con el nodo fantasma
int N;

void update(int posicion, int valor)
{
    for (; posicion <= N; posicion += posicion & -posicion)
    {
        BIT[posicion] += valor;
    }
}
// [2,3,7,1,5]
//  0 1 2 3 4
// BIT[0,2,5,7,13,5]; // voy agregar el nodo fantasma

int query(int posicion)
{ // F(3)
    int result = 0;
    for (; posicion > 0; posicion -= posicion & -posicion)
    {
        result += BIT[posicion];
    }
    return result;
}
// query (ini,fin)
// query (2,5)
int query2(int inicio, int final)
{
    // query (5) - query(2-1)
    // query (5) - query(1)
    // 18-  2 = 16
    return query(final) - query(inicio - 1);
}

int main()
{
    input;
    int queries;
    cin >> N >> queries;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        update(i + 1, x);
    }
    for (int i = 0; i <= N; i++)
    {
        cout << "[" << BIT[i] << "]";
    }
    cout << endl;
    while (queries--)
    {
        int x, y;
        cin >> x >> y;
        cout << query2(x, y) << endl;
    }
    return 0;
}