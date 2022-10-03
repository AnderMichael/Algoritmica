#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[10000];
int parent[10000];
int rango[10000];

int n;
// Todo se inicializa con todos los nodos siendo sus propios padres y los rangos de cada uno desde 0
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
}
// Total de grupos en base a la compresión de caminos para determinar un solo nodo superpadre para cada grupo...
int totalGroups(){
    set <int> roots;
    for (int i = 0; i < n; i++){
        roots.insert(find(i));
    }
    return roots.size();
}

int main()
{
    n = 9;
    init();
    unionRango(2,0);
    unionRango(7,0);
    unionRango(3,1);
    unionRango(1,0);
    unionRango(6,4);
    unionRango(8,4);
    cout << "Nodos" << " -> " << "Padres" << " -> " << "Rango" <<endl;
    for (int i = 0; i < n; i++){
        cout << i << " -> " << parent[i] << " -> " << rango[i] << endl;
    }
    cout << "Los grupos totales: " << totalGroups() << endl;
}