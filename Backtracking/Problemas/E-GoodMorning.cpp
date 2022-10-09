#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)

using namespace std;

bool v[11][11];
bool values[220];

int n = 0;

void num(int dig, int val)
{
    if (val > 200)
    {
        return;
    }
    else
    {
        values[val] = true;
        val = val * 10 + dig;
        for (int i = 0; i < 10; i++)
        {
            if (v[dig][i])
            {
                num(i, val);
            }
        }
    }
}
void init()
{
    memset(values, false, sizeof(values));
    memset(v, false, sizeof(v));
    for (int i = 0; i < 10; i++)
    {
        v[i][i] = true;
        v[1][i] = true;
        if (i >= 4)
        {
            v[4][i] = true;
        }
        if (i >= 7)
        {
            v[7][i] = true;
        }
    }
    v[4][0] = v[7][0] = true;
    v[2][3] = v[2][5] = v[2][6] = v[2][8] = v[2][9] = v[2][0] = true;
    v[3][6] = v[3][9] = true;
    v[5][6] = v[5][8] = v[5][9] = v[5][0] = true;
    v[6][9] = true;
    v[8][9] = v[8][0] = true;
    values[0] = true;
    for (int i = 1; i < 10; i++)
    {
        num(i, 0);
    }
}

int main()
{
    init();
    input;
    int k, t;
    // scanf("%d", &t);
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        // scanf("%d", &k);
        cin >> k;
        if (values[k])
        {
            // printf("%d\n",k);
            cout << k << endl;
        }
        else
        {
            int j = k + 1;
            while (!values[j])
            {
                j++;
            }
            int v1 = j;
            j = k - 1;
            while (!values[j])
            {
                j--;
            }
            if (abs(v1 - k) < abs(k - j))
            {
                cout << v1 << endl;
            }
            else
            {
                cout << j << endl;
            }
        }
    }
}
