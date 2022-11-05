// Link del problema https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1927
#include<bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX_N 100000

using namespace std;

// Estructura para manejar el siguiente conjunto de datos: Origen, Destino, Peso.
struct Arista
{
    int origen;
    int destino;
    long int peso;
    long int pesop;
    Arista() {}
     bool operator<(const Arista &a) const
     {
         if (pesop == a.pesop)
         {
             return origen < a.origen;
         }
         else
         {
             return pesop < a.pesop;
         }
     }
     
} aristas[MAX_N];

//PRIM modificado para hallar solo el camino más corto de INICIO -> FINAL ya no el árbol mínimo
// SINO ya no funca :(
void prim(int n, int m)
{
    int inicio, fin;
    scanf("%d %d", &inicio, &fin);
    vector< vector<Arista> > sets(n);
    vector< pair<int, int> > mst(n);
    bool visitado[n];
    memset(visitado, false, sizeof(visitado));
    multiset<Arista> colaPrioridad; // log(n)sk
    for (int i = 0; i < 2 * m; i += 2)
    {
        scanf("%d %d %d", &aristas[i].origen, &aristas[i].destino, &aristas[i].peso);
        aristas[i].pesop = 0;
        sets[aristas[i].origen].push_back(aristas[i]);
        aristas[i + 1].origen = aristas[i].destino;
        aristas[i + 1].destino = aristas[i].origen;
        aristas[i + 1].peso = aristas[i].peso;
        aristas[i + 1].pesop = 0;
        sets[aristas[i].destino].push_back(aristas[i + 1]);
    }
    for (int i = 0; i < sets[inicio].size(); i++)
    {
        Arista first = sets[inicio][i];
        first.pesop += first.peso;
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
                vecino.pesop = vecino.peso + verticeActual.pesop;
                colaPrioridad.insert(vecino);
            }
            mst[verticeActual.destino] = make_pair(verticeActual.origen, verticeActual.pesop);
        }
    }
    if(visitado[fin]){
        printf("%ld\n", mst[fin].second);
    }else{
        printf("unreachable\n");
    }
}

int main()
{
    input;
    output;
    int N, m, n, i = 1;
    // NRONodos "n" y NROAristas "m"
    scanf("%d", &N);
    while(N--){
        scanf("%d %d", &n, &m);
        printf("Case #%d: ",i++);
        if(m){
        prim(n,m);
        }else{
        printf("unreachable\n");
        scanf("%*d %*d");
        }
    }
}
