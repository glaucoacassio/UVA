#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cstdio>
#define MIN(a, b) (a < b ? a : b)
#define MAX(a, b) (a > b ? a : b)
        using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b, n, aux, cont;

    while (scanf("%d %d", &a, &b) != EOF)
    {
        int maior = -10000000; 
        int min = MIN(a, b);
        int max = MAX(a, b);
        for (int i = min; i <= max; i++)
        {
            cont = 1, n = i;
            while (n != 1)
            {
                if (n % 2 == 0) n/= 2;   
                else n = 3 * n + 1;

                cont++;
            }
            if (cont > maior) maior = cont;
        }
        printf("%d %d %d\n", a, b, maior);
    }
    return 0;
}
