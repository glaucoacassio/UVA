#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cstdio>
using namespace std;

// Numero maximo de digitos na saida
#define MAX 200000

int multiplicar(int x, int res[], int res_size);

// Esta funcao encontra o fatorial de numeros largos
// e imprime eles
void fatorial(int n)
{
    int res[MAX];

    // Inicializa resultado
    res[0] = 1;
    int res_size = 1;

    // Aplico a simples formula do fatorial n! = 1 * 2 * 3 * 4 * ... * n
    for (int x = 2; x <= n; x++)
        res_size = multiplicar(x, res, res_size);

    cout << n <<"!\n";
    for (int i = res_size - 1; i >= 0; i--)
        cout << res[i];
    cout<<endl;
}

// Esta função multiplica x pelo número
// representado por res[].
// res_size é o tamanho de res[] ou o número de dígitos no
// número representado por res[]. 
// Esta função tem o valor de res_size e retorna o
// novo valor de res_size
int multiplicar(int x, int res[], int res_size)
{
    int carry = 0; // Inicializamos o carry

    // Um por um multiplique n pelos dígitos individuais de res[]
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;

        // Armazena o último dígito de 'prod' em res[]
        res[i] = prod % 10;

        // Coloque o resto em transporte(carry)
        carry = prod / 10;
    }

    // Coloque carry em res e aumentamos o tamanho do resultado
    while (carry)
    {
        res[res_size] = carry % 10;
        carry = carry / 10;
        res_size++;
    }
    return res_size;
}
int main() 
{ 
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
	int n;
	
	while(scanf("%d", &n) != EOF)
        {
	    fatorial(n); 
        }
	return 0; 
	
} 
