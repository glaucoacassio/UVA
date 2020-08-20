// Um programa otimizado pra encontrar
// o numero de digitos em um fatorial
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

// Retorna o numero de digitos presente
// em n! Como o resultado pode ser grande
// long long eh usado como tipo de retorno.
long long contaDigitosFatorial(int n)
{
    // Fatorial do numero -v
    // nao existe
    if (n < 0)
        return 0;

    // caso base fatorial de 0 e 1 = 1
    if (n <= 1)
        return 1;

    // Use formula de Kamenetsky pra calculatar
    // o numero de digitos
    double x = ((n * log10(n / M_E) + log10(2 * M_PI * n) / 2.0));

    return floor(x) + 1;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << contaDigitosFatorial(n) << endl;
    }
    return 0;
}
