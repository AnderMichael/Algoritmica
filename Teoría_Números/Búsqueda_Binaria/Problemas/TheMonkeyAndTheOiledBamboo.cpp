#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
using namespace std;

int v[10000010];
int diferencias[10000010];
bool arregloAux[10000010];
int N;
int grandote;
int litteOne;

bool f(int k)
{
    for (int i = 0; i < N; i++)
    {
        if (k == diferencias[i])
        {
            k--;
            if (k < 0)
            {
                return false;
            }
        }
        else if (k < diferencias[i])
        {
            return false;
        }
        else
        {
            continue;
        }
    }
    return true;
}

int binarySearch()
{
    long left = 1;
    long long right = 2 * (grandote + 1);
    int mid;
    mid = (left + right) / 2;
    while (left <= right)
    {
        if (f(mid))
        {
            if (mid < litteOne)
            {
                litteOne = mid;
            }
            if (left == right)
            {
                return mid;
            }
            right = mid - 1;
        }
        else
        {
            if (left == right)
            {
                return mid;
            }
            left = mid + 1;
        }
        mid = (left + right) / 2;
    }
    return mid;
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &v[j]);
            if (j > 0)
            {
                diferencias[j] = v[j] - v[j - 1];
            }
            else
            {
                diferencias[0] = v[0];
            }
            if (diferencias[j] > grandote)
            {
                grandote = diferencias[j];
            }
        }
        litteOne = grandote + 1;
        binarySearch();
        printf("Case %d: %d\n", i + 1, litteOne);
    }
    return 0;
}
