#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int padres[1000];
// Al inicializar el árbol y los nodos, estos últimos son padres de sí mismos
void init() {
    for(int i = 0; i < 1000; i++){
        padres[i] = i; //[0,1,2,3,4,5,6,7,8,9...] 
    }
}
// Sub-método para unir las raíces de dos nodos propuestos
void unir(int vertice1, int vertice2) {
    padres[vertice2] = vertice1;
}
// Buscar el padre de toda una rama de nodos
int encontrarAlPadre(int vertice) {
    if(padres[vertice] == vertice) {
        return vertice;
    }
    return encontrarAlPadre(padres[vertice]);
}
//Método para unir dos nodos propuestos a partir de las ráices  
void unionNodes(int nodo1, int nodo2){
    //Se buscan las raíces
    int padre1 = encontrarAlPadre(nodo1);
    int padre2 = encontrarAlPadre(nodo2);
    // En este caso el nodo de la izquiera es el padre del otro (puede variar de acuerdo al ejercicio o criterio).
    unir(padre1,padre2);
}
// Pruebita :D
int main(){
    init();
    unionNodes(6,7);
    unionNodes(5,6);
    unionNodes(4,5);
    unionNodes(3,4);
    unionNodes(2,3);
    unionNodes(1,2);
    cout << "Nodos" << " -> " <<" Padres " <<endl;
    for (int i = 1; i < 8; i++){
        cout << i << " -> " << padres[i] << endl;
    }
    
}
// Esta es la idea principal de Union_Find, sin embargo, aplicando solo esta idea cada vez que se haga unión...
// ...entre componentes con mayor numero de nodos el árbol tiende a ser un árbol desbalanceado (Find tarda más en hallar a los padres).