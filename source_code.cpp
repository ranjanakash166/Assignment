#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <stack>
#include <queue>
#include <functional>
#include <climits>
#include <vector>
#include <string>
#include <set>
#include <cstring>
#include <iomanip>
#include <cmath>
using namespace std;
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define fora(x,y,z) for(int x=y;x<(z);x++)
#define FL(a,n,x) fill(a,a+n,x)
#define pii pair<int,int>
#define F first
#define S second
#define mp make_pair
#define MOD 1000000007
#define endl  '\n'
#define debug(x) cout<<"here"<<x<<endl;
#define MAX 1000000007
#define iosb ios_base::sync_with_stdio(false);cin.tie(0);
ll fibo(ll n)
{
    ll fib[2][2] = {1, 1, 1, 0};
    ll res[2][2] = {1, 0, 0, 1};
    ll mul[2][2] = {0, 0, 0, 0};
    while (n > 0)
    {
        if (n & 1)
        {
            memset(mul, 0, sizeof(mul));
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 2; j++)
                {
                    for (int k = 0; k < 2; k++)
                        mul[i][j] = (mul[i][j] + (res[i][k] * fib[k][j]) % MOD) % MOD;
                }
            }
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    res[i][j] = mul[i][j];
        }
        memset(mul, 0, sizeof(mul));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
                for (int k = 0; k < 2; k++)
                    mul[i][j] = (mul[i][j] + (fib[i][k] * fib[k][j]) % MOD) % MOD;
        }
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                fib[i][j] = mul[i][j];
        n >>= 1;
    }
    return res[0][1] % MOD;
}
int main() {
    iosb;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n;
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        ll ans = fibo(n + 2);
        cout << ans << endl;
    }
    return 0;
}