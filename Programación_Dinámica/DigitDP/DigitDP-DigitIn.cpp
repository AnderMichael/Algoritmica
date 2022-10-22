#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

// el numero maximo sera 10^18
// 1000000000000000000
string number;
int dp[20][2][2];

int solve_dp(int pos, int mayor, int nroDeNs)
{
    if (pos > number.size())
    { // cuando la posicion exceda al numero dado
        return 0;
    }
    // Modificar de acuerdo al problema
    if (pos == number.size())
    {
        if (nroDeNs >= 1)
        { // la suma de los digitos es primo
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if (dp[pos][mayor][nroDeNs] == -1)
    { // Pregunto si no lo he calculado
        int tope = 9;
        if (mayor == true)
        {                             // el numero que voy a crear puede llegar a ser mayor
            tope = number[pos] - '0'; // solo podemos usar los numeros de 0 al tope -- '3'-'0' =  51 - 48 = 3
        }
        dp[pos][mayor][nroDeNs] = 0;
        int res;
        for (int digito = 0; digito <= tope; digito++)
        {
            if (digito == tope)
            {
                dp[pos][mayor][nroDeNs] += solve_dp(pos + 1, true && mayor, (digito == 3)||(digito == 4)||nroDeNs);
                res = dp[pos][mayor][nroDeNs];
            }
            else
            { // 0 1 2
                dp[pos][mayor][nroDeNs] += solve_dp(pos + 1, false, (digito == 3)||(digito == 4)||nroDeNs);
                res = dp[pos][mayor][nroDeNs];
            }
        }
    }
    return dp[pos][mayor][nroDeNs];
}

int main()
{
    // Hallar los números los cuales tienen un dígito al menos un 3
    string a = "0";
    string b = "999999";
    // calculando f(a)
    number = a;
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solve_dp(0, true, 0);
    //cout << pares_hasta_a << endl;
    // calculando f(b)
    memset(dp, -1, sizeof(dp));
    number = b;
    int pares_hasta_b = solve_dp(0, true, 0);
    //cout << pares_hasta_b << endl;
    // total para f(a,b) = f(b) - f(a-1)
    cout << pares_hasta_b - pares_hasta_a;
    return 0;
}