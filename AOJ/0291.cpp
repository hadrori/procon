#include <bits/stdc++.h>
using namespace std;

typedef int number;
typedef vector<number> arr;
typedef vector<arr> mat;

arr mul(const mat &A, const arr &x)
{
        arr y(A.size());
        for(int i = 0; i < (int)A.size(); ++i)
                for(int j = 0; j < (int)A[0].size(); ++j)
                        y[i] += A[i][j] * x[j];
        return y;
}

mat mul(const mat &A, const mat &B)
{
        mat C(A.size(), arr(B[0].size()));
        for(int i = 0; i < (int)C.size(); ++i)
                for(int j = 0; j < (int)C[i].size(); ++j)
                        for(int k = 0; k < (int)A[i].size(); ++k)
                                C[i][j] += A[i][k] * B[k][j];
        return C;
}

mat identity(int n)
{
        mat A(n, arr(n));
        for (int i = 0; i < n; i++)
                A[i][i] = 1;
        return A;
}

mat pow(const mat &A, int e)
{
        return e == 0 ? identity(A.size())  :
               e % 2 == 0 ? pow(mul(A, A), e/2) :
               mul(A, pow(A, e-1));
}

int n, m, q, id[32];
char s[1024];
arr vs[32];
mat f[32];

int num(int &i)
{
        int ret = 0;
        while(isdigit(s[i])) ret = 10*ret+s[i++]-'0';
        return ret;
}

mat expr(int &i)
{
        mat ret = identity(n);
        if(i == m) return ret;
        if(s[i] == ')') {
                i++;
                return ret;
        }
        if(s[i] == '+') return expr(++i);
        int a = 1;
        if(isdigit(s[i])) a = num(i);
        if(s[i] == '(') ret = pow(expr(++i),a);
        else if(isalpha(s[i])) ret = pow(f[id[s[i++]-'A']], a);
        return mul(expr(i), ret);
}

void solve()
{
        for (int i = 0; i < m; i++) {
                f[i].assign(n,arr(n,0));
                for (int j = 0; j < n; j++) f[i][j][vs[i][j]] = 1;
        }
        while(q--) {
                scanf("%s", s);
                m = strlen(s);
                int _ = 0;
                mat A = expr(_);
                arr x(n);
                for (int i = 0; i < n; i++) x[i] = i;
                x = mul(A,x);
                for (int i = 0; i < n; i++) printf("%d%c", x[i]+1, (i==n-1? '\n': ' '));
        }
}

void input()
{
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++) {
                vs[i].assign(n,0);
                for (int j = 0; j < n; j++) vs[i][j] = j;

                char c; int h, b;
                scanf(" %c %d", &c, &h);
                id[c-'A'] = i;
                for (int j = 0; j < h-1; j++) {
                        for (int k = 0; k < n-1; k++) {
                                scanf("%d", &b);
                                if(b) swap(vs[i][k], vs[i][k+1]);
                        }
                }
        }
        scanf("%d", &q);
}

int main()
{
        input();
        solve();
        return 0;
}
