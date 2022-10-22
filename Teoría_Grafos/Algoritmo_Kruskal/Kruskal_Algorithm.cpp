#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
// Variables
#define MAX_N 10000 // Maximo numero de vertices o nodos

using namespace std;

// parent y rango sirven para el union find
int parent[MAX_N];
int rango[MAX_N];

int n, m; // n numero de nodos y m numero de aristas

// ===== UNION_FIND (con Rango) =====
void init()
{
    for (int i = 0; i <= MAX_N; i++)
    {
        parent[i] = i;
        rango[i] = 0;
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
// ===== END - UNION_FIND =====

// Método para comprobar conexiones entre aristas
bool sameComponent(int nodeA, int nodeB)
{
    return find(nodeA) == find(nodeB);
}

// Estructura para manejar el siguiente conjunto de datos: Origen, Destino, Peso.
struct Arista
{
    int origen;
    int destino;
    double peso;
    Arista() {}
    // sobrecarga del operador < para ordenar las aristas
    // sort
    // Se configura en el siguiente método el criterio del operador <
    // Cambiar el operador dependiendo el ejercicio > o <.
    
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
    
   /*
    bool operator<(const Arista &a) const
    {
        if (peso == a.peso)
        {
            return origen > a.origen;
        }
        else
        {
            return peso > a.peso;
        }
    }
    */

} aristas[MAX_N];

// Arreglo de "Aristas"
Arista MST[MAX_N]; // n-1 aristas

int numAristasArbol;

double kruskal(int nroNodos, int nroAristas)
{

    int origen, destino;
    double peso;

    double total = 0; // total del arbol de expansión minimo

    numAristasArbol = 0; // contar el numero de aristas
    // sort(array, array+n)
    // array = [a,b,c,d,e]
    // n = 5
    // sort(array, array+5)
    // ====> PASO 1 : Ordenar las aristas por el peso.
    sort(aristas, aristas + nroAristas); // ordena las aristas según el criterio requerido
    // ====> PASO 2 : Crear un "Union_Find".
    init(); // Iniciar el union Find
    // sort utiliza el operador <
    // ====> PASO 3 : Unir NODOS sin repetirlos.
    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if (!sameComponent(origen, destino))
        { // ¿estos 2 dos nodos forman un ciclo?
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
    input;
    // Se introducen el NROdeNodos "n" y NROdeAristas "m"
    while (scanf("%d %d", &n, &m) != EOF)
    {
        // Se introducen los vertices con sus respectivas aristas
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %lf", &aristas[i].origen, &aristas[i].destino, &aristas[i].peso);
        }
        printf("%.2lf\n", kruskal(n, m));
        // Imprimo el arbol de expasion minimo
        for (int i = 0; i < numAristasArbol; i++)
        {
            cout << MST[i].origen << " " << MST[i].destino << " " << MST[i].peso << endl;
        }
    }

    return 0;
}