#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;

int dp[101][101]; // Modificar el tamaño de la matriz para la resolución de distintos problemas.
int v[101];
// Exploracion de arriba hacia abajo.
bool solve(int index, int k)
{
    // Hasta considerar el último elemento de la lista de numeros.
    if (index == -1)
    {
        // Verificar si se llegó a conformar el número requerido.
        if (k == 0)
        {
            return true;
        }
        return false;
    }
    // Solo si nunca se exploró la opción.
    if (dp[index][k] == -1)
    {
        if (k - v[index] >= 0)
        {
            dp[index][k] = solve(index - 1, k - v[index]) || solve(index - 1, k);
        }
        else
        {
            dp[index][k] = solve(index - 1, k);
        }
    }
    // Responder a la consulta.
    return dp[index][k];
}

// Este algoritmo base solo sirve para determinar si existe una combinación de números que resulten en otro.
int main()
{
    input;
    int n;
    cin >> n;
    // Seteando de la matriz a -1
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // El número a conformar a -1.
    int k;
    cin >> k;
    if (solve(n - 1, k))
        cout << "YES\n";
    else
        cout << "NO\n";
}