#include<bits/stdc++.h>

using namespace std;

#define ll                          long long
#define mod                          1000000007
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

ll mat[101][101];

ll visited[101][101];



bool isValid(ll n, ll m, ll x, ll y)
{
    if (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == 0)
        return true;
    return false;
}


ll fun(int n, int m, pair<ll, ll>src, pair<ll, ll>dest)
{
    visited[src.f][src.s] = 1;
    if (src.f == dest.f && src.s == dest.s)
    {
        visited[src.f][src.s] = 0;
        return 0;
    }
    ll retVal = NINF;
    for (ll i = 0; i < 4; i++)
    {
        ll newX = src.f + dir4[i][0] , newY = src.s + dir4[i][1];
        if (isValid(n, m, newX, newY) && mat[newX][newY] == 1)
        {
            retVal = max(retVal , 1 + fun(n, m, {newX, newY}, dest));
        }
    }
    visited[src.f][src.s] = 0;
    return retVal;
}


void pavan_coder()
{

    memset(visited, 0, sizeof(visited));

    ll n, m;
    cin >> n >> m;


    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < m; j++)
            cin >> mat[i][j];
    }
    pair<ll, ll>src;
    pair<ll, ll>dest;

    ll x, y;
    cin >> x >> y;
    src = {x, y};

    cin >> x >> y;
    dest = {x, y};

    cout << fun(n, m, src, dest);
}


int main()
{
    file();

    ll tc = 1;
    // cin >> tc;
    while (tc--)
    {
        pavan_coder();
    }


}




