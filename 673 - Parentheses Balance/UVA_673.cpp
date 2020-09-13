#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    int n;
    char linha[1000];
    stack<char> pilha;

    scanf("%d", &n);
    getchar();
    while (n--)
    {
        bool ok = true;
        gets(linha);
        for (int i = 0; i < strlen(linha); i++)
        {
            if (linha[i] == '(' || linha[i] == '[')
                pilha.push(linha[i]);
            else if (linha[i] == ')' || linha[i] == ']')
            {
                if (!pilha.empty() && linha[i] == ')' && pilha.top() == '(')
                    pilha.pop();
                else if (!pilha.empty() && linha[i] == ']' && pilha.top() == '[')
                    pilha.pop();
                else
                {
                    ok = false;
                    break;
                }
            }
        }
        if (ok && pilha.empty()) printf("Yes\n");
        else printf("No\n");

        //Esvazio a pilha em caso de nao ta ok...
        while (!pilha.empty())
                pilha.pop();
    }
    return 0;
}
