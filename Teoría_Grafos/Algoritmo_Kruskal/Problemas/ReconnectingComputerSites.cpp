#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
// Variables
#define MAX_N 1000009    // Maximo numero de vertices o nodos

using namespace std; 

// parent y rango sirven para el union find 
int parent[MAX_N];
int rango[MAX_N];

int n;
long long int m; // n numero de nodos y m numero de aristas 

void init() {
    memset(rango, 0, sizeof(0));
    for(int i=0;  i<= MAX_N; i++) {
        parent[i] = i;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

bool sameComponent(int nodeA,int nodeB) {
    return find(nodeA) == find(nodeB);
}

void unionRango(int x,int y) {
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista{ 
    int origen;
    int destino; 
    long long int peso; 
    Arista(){}
    // sobrecarga del operador < para ordenar las aristas
    // sort 
    bool operator<(const Arista &a) const {
        if(peso == a.peso) {
            return origen < a.origen;
        } else {
            return peso < a.peso;
        }
    }
}aristas[MAX_N]; 

Arista MST[MAX_N]; // n-1 aristas 

long long int numAristasArbol;
int kruskal(int nroNodos, int nroAristas) {
    
    int origen, destino;
    long long int peso;

    int total = 0; // total del arbol de expansión minimo 

    numAristasArbol = 0; // contar el numero de aristas 

    init(); // Iniciar el union Find 
    // sort(array, array+n)
    // array = [a,b,c,d,e]
    // n = 5
    // sort(array, array+5)
    sort(aristas,aristas + nroAristas); // ordena las aristas
    // sor utiliza el operador < 

    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!sameComponent(origen,destino)) { // estos 2 dos nodos forman un ciclo 
            total += peso; 
            unionRango(origen,destino);  // unimos los nodos
            MST[numAristasArbol] = aristas[i]; // Guardamos la arista agregada
            numAristasArbol++; // incrementados la posicion para la futura arista
            
        }
    }
    return total;
}

int main(){
    //input;
    int a, b;
    long long int c;
    int con=0;
    while(scanf("%d",&n)!=EOF){
        con++;
        if(con>1){
            printf("\n");
        }
        int num = 0;
        for(int i=0; i<n-1; i++){
        scanf("%d %d %lld",&a,&b,&c);
        num+=c;
        }
        
    int k;
    scanf("%d",&k);
    for(int i=0; i<k; i++){
        scanf("%d %d %lld",&aristas[i].origen,&aristas[i].destino,&aristas[i].peso);
    }
    scanf("%lld",&m);
    for(long long int i=k; i<m+k; i++){
        scanf("%d %d %lld",&aristas[i].origen,&aristas[i].destino,&aristas[i].peso);
    }
    printf("%d\n",num);
    printf("%d\n",kruskal(n,m+k));

    }
    

}
