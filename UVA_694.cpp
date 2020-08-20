/*
https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=635&mosmsg=Submission+received+with+ID+25086340
*/
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int testes = 1;
    long long int n, m, a, b;

    while (scanf("%lld %lld", &a, &b) && a > 0 && b > 0)
    {
        int contador = 1;
        n = a;
        m = b;
        while (n != 1)
        {
            if (n % 2 == 0) n /= 2;
            else n = 3 * n + 1;
            
            if (n > m) break;
            contador++;
        }
        printf("Case %d: A = %lld, limit = %lld, number of terms = %lld\n", testes++, a, b, contador);
    }
    return 0;
}