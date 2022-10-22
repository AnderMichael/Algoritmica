#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define MAX_N 10000

using namespace std;

// Estructura para manejar el siguiente conjunto de datos: Origen, Destino, Peso.
struct Arista
{
    int origen;
    int destino;
    int peso;
    Arista() {}
    // sobrecarga del operador < para ordenar las aristas
    // sort
    // Se configura en el siguiente método el criterio del operador <
    // Cambiar el operador dependiendo el ejercicio > o <.
    /*
     bool operator<(const Arista &a) const
     {
         if (peso == a.peso)
         {
             return origen < a.origen;
         }
         else
         {
             return peso < a.peso;
         }
     }
     */

    bool operator<(const Arista &a) const
    {
        if (peso == a.peso)
        {
            return origen < a.origen;
        }
        else
        {
            return peso < a.peso;
        }
    }
} aristas[MAX_N];

void prim(int n, int m)
{
    vector< vector<Arista> > sets(n);
    vector<Arista> MST;
    bool visitado[n];
    memset(visitado, false, sizeof(visitado));
    multiset<Arista> colaPrioridad; // log(n)sk
    for (int i = 0; i < 2 * m; i += 2)
    {
        scanf("%d %d %d", &aristas[i].origen, &aristas[i].destino, &aristas[i].peso);
        sets[aristas[i].origen].push_back(aristas[i]);
        aristas[i + 1].origen = aristas[i].destino;
        aristas[i + 1].destino = aristas[i].origen;
        aristas[i + 1].peso = aristas[i].peso;
        sets[aristas[i].destino].push_back(aristas[i + 1]);
    }
    int inicio;
    scanf("%d", &inicio);
    for (int i = 0; i < sets[inicio].size(); i++)
    {
        Arista first = sets[inicio][i];
        colaPrioridad.insert(first);
    }
    visitado[inicio] = true;
    while (!colaPrioridad.empty())
    {
        Arista verticeActual = *colaPrioridad.begin();
        colaPrioridad.erase(colaPrioridad.begin()); // pop()           // distancia
        int next = verticeActual.destino;
        if (!visitado[next])
        {
            visitado[next] = true;
            for (int i = 0; i < sets[next].size(); i++)
            {
                Arista vecino = sets[next][i];
                colaPrioridad.insert(vecino);
            }
            MST.push_back(verticeActual);
        }
    }
    for (int i = 0; i < MST.size(); i++)
    {
        printf("%d %d %d\n", MST[i].origen,MST[i].destino, MST[i].peso);
    }
    
}

int main()
{
    input;
    int m, n;
    // NRONodos "n" y NROAristas "m"
        scanf("%d %d", &n, &m);
        prim(n, m);
    
}