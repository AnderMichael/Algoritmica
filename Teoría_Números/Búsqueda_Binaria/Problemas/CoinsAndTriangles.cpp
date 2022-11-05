// Link del problema https://www.codechef.com/problems/TRICOIN
#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int t, m;
bool f(int n)
{
    int res = (n + 1) * n / 2;
    if (res > m)
        return false;
    else
        return true;
}

int binarySearch(int left, int right)
{
    int mid = (left + right) / 2;
    if (left == right || right < left)
    {
        if (f(mid))
            return mid;
        else
            return mid - 1;
    }
    else
    {
        if (f(mid))
            return binarySearch(mid + 1, right);
        else
            return binarySearch(left, mid - 1);
    }
}

int main()
{
    input;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &m);
        printf("%d\n", binarySearch(1, min(m, 44720)));
    }
}
