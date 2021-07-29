#include<bits/stdc++.h>

using namespace std;

#define ll                          long long
#define mod                         1000000007
#define f                           first
#define s                           second
#define pb                          push_back
#define mk                          make_pair
#define gcd(a,b)                    __gcd(a,b)
#define lcm(a,b)                    a/gcd(a,b)*b
#define fast_io                     ios_base::sync_with_stdio(false);\
                                    cin.tie(NULL)
#define PI                          3.1415926535897932384626
#define INF                         1e18
#define NINF                        -1e18

bool flg = false;

const int dir4[4][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}};

const int dir8[8][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1}};

/*--------------------------------------------------------code starts here--------------------------------------------------------------*/



void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}




void  pavan_coder()
{
    ll n;
    cin >> n;
    ll arr[n][n];

    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    ll dpMin[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || j == 0) dpMin[i][j] = INT_MAX;
            else
            {
                dpMin[i][j] = min(dpMin[i - 1][j] , min(dpMin[i][j - 1] , arr[i - 1][j - 1]));
            }
        }
    }


    ll dpMax[n][n];

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1 || j == n - 1)dpMax[i][j] = INT_MIN;
            else
            {
                dpMax[i][j] = max(dpMax[i + 1][j] , max(dpMax[i][j + 1] , arr[i + 1][j + 1]));
            }
        }
    }
    ll ans = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            ans = max(ans , dpMax[i][j] - dpMin[i][j]);
        }
    }
    cout << ans;
}

int main()
{
    fast_io;
    // file();
    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        pavan_coder();
        cout << "\n";
    }
}




