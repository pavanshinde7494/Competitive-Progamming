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

int mat[101][101];
ll visited[101][101];




bool isValid(ll r, ll c, ll x, ll y)
{
    if (x >= 0 && x < r && y >= 0 && y < c && visited[x][y] == 0)
        return true;
    return false;
}


void fun(ll r , ll c, ll x, ll y, string curStr)
{
    visited[x][y] = 1;
    curStr.pb(mat[x][y] + 48 );
    curStr.pb(' ');

    if (x == r - 1 && y == c - 1)
    {
        cout << curStr << "\n";

        curStr.pop_back();
        curStr.pop_back();
        visited[x][y] = 0;
        return;
    }
    if (isValid(r, c, x + 1, y))
        fun(r, c, x + 1, y, curStr);
    if (isValid(r, c, x, y + 1))
        fun(r, c, x, y + 1, curStr);


    curStr.pop_back();
    curStr.pop_back();
    visited[x][y] = 0;
}


void pavan_coder()
{
    memset(visited, 0, sizeof(visited));

    ll r, c;
    cin >> r >> c;

    for (ll i = 0; i < r; i++)
    {
        for (ll j = 0; j < c; j++)
            cin >> mat[i][j];
    }

    fun(r, c, 0, 0, "");

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




