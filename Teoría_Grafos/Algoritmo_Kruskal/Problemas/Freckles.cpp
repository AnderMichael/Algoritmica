#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
// Variables
#define MAX_N 1000009 // Maximo numero de vertices o nodos

using namespace std;

// parent y rango sirven para el union find
int parent[MAX_N];
int rango[MAX_N];
vector<pair<double, double> > V;
int n;
long long int m; // n numero de nodos y m numero de aristas

void init()
{
    memset(rango, 0, sizeof(0));
    for (int i = 0; i <= MAX_N; i++)
    {
        parent[i] = i;
    }
}

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

bool sameComponent(int nodeA, int nodeB)
{
    return find(nodeA) == find(nodeB);
}

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
        parent[xRaiz] = yRaiz;
        if (rango[xRaiz] == rango[yRaiz])
        {
            rango[yRaiz]++;
        }
    }
}

struct Arista
{
    double origen;
    double destino;
    double peso;
    Arista() {}
    // sobrecarga del operador < para ordenar las aristas
    // sort
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

Arista MST[MAX_N]; // n-1 aristas

int numAristasArbol;
double kruskal(int nroNodos, int nroAristas)
{

    double origen, destino;
    double peso;

    double total = 0.0; // total del arbol de expansión minimo

    numAristasArbol = 0; // contar el numero de aristas

    init(); // Iniciar el union Find
    // sort(array, array+n)
    // array = [a,b,c,d,e]
    // n = 5
    // sort(array, array+5)
    sort(aristas, aristas + nroAristas); // ordena las aristas
    // sor utiliza el operador <

    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if (!sameComponent(origen, destino))
        { // estos 2 dos nodos forman un ciclo
            total += peso;
            unionRango(origen, destino);       // unimos los nodos
            MST[numAristasArbol] = aristas[i]; // Guardamos la arista agregada
            numAristasArbol++;                 // incrementados la posicion para la futura arista
        }
    }
    return total;
}

int main()
{
    
    //input;
    //output;
    int t;
    double x, y;
    scanf("%d", &t);
    while(t--){
        scanf("%d",&n);
        V.clear();
        for(int i=0; i<n; i++){
            scanf("%lf %lf", &x, &y);
            V.push_back(make_pair(x,y));
        }
        int con = 0;
        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                double x1 = V[i].first;
                double y1 = V[i].second;
                x = V[j].first;
                y = V[j].second;
                double p=  sqrt((x-x1)(x-x1) + (y-y1)(y-y1));
                aristas[con].origen = i;
                aristas[con].destino = j;
                aristas[con].peso = p;
                con++;
            }
        }
        printf("%.2lf\n", kruskal(n, con));
        if(t>0){
            printf("\n");
        }

    }

    
}
