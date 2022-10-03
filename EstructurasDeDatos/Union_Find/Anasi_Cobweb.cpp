#include <iostream>
#include <stack>
#include <vector>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int parent[100000];
int rango[100000];

int n, m, q, nroGrupos;
void init()
{
    for (int i = 0; i <= n; i++)
    {
        parent[i] = i;
        rango[i] = 0;
    }
}
// Find implementando la compresión de caminos para llegar más rápido al nodo superpadre
int find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    else
    {
        parent[x] = find(parent[x]);

        return parent[x];
    }
}
// Unión implementando el criterio por rangos
void unionRango(int x, int y)
{
    int xRaiz = find(x);
    int yRaiz = find(y);
    if (xRaiz == yRaiz)
    {
        return;
    }
    if (rango[xRaiz] > rango[yRaiz])
    {
        parent[yRaiz] = xRaiz;
    }
    else
    {
        parent[xRaiz] = yRaiz; // Asignación dependiente del ejercicio o el criterio de construcción del grafo
        if (rango[xRaiz] == rango[yRaiz])
        {
            rango[yRaiz]++; // Aumentar el rango del padre
        }
    }
    nroGrupos--;
}
// Total de grupos en base a la compresión de caminos para determinar un solo nodo superpadre para cada grupo...
int main()
{
    input;
    cin >> n >> m;
    init();
    vector< pair<int, int> > threads(m);
    nroGrupos = n;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        threads[i] = make_pair(x, y);
    }
    int deleteThread;
    cin >> q;
    vector<bool> deleteThreads(m, false);
    vector<int> reverseThreads;
    for (int i = 0; i < q; i++)
    {
        cin >> deleteThread;
        deleteThreads[deleteThread - 1] = true;
        reverseThreads.push_back(deleteThread);
    }
    for (int i = 0; i < m; i++)
    {
        if (!deleteThreads[i])
        {
            unionRango(threads[i].first, threads[i].second);
        }
    }
    vector<int> answer(q);
    answer[q - 1] = nroGrupos;
    for (int i = q - 1; i > 0; i--)
    {
        int last = reverseThreads[i];
        unionRango(threads[last - 1].first, threads[last - 1].second);
        answer[i - 1] = nroGrupos;
    }
    cout << answer[0];
    for (int i = 1; i < q; i++)
    {
        cout << " " << answer[i];
    }
}