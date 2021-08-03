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

const int dir4[4][2] = {{0, -1}, {0, 1}, {1, 0}, { -1, 0}};

const int dir8[8][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1}};

/*--------------------------------------------------------code starts here--------------------------------------------------------------*/


void file()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}


ll arr[1001][1001];

ll visited[1001][1001];

bool isValid(ll x, ll y, ll n, ll m)
{
	if (x >= 0 && x < n && y >= 0 && y < m && visited[x][y] == -1 && arr[x][y] == 1)
		return true;
	return false;
}




ll fun(ll n, ll m, ll x, ll y)
{
	visited[x][y] = 1;
	if ( y == m - 1)
	{
		visited[x][y] = -1;
		return 0;
	}
	ll retVal = INF;
	for (ll i = 1; i < 4; i++)
	{
		ll newX = x + dir4[i][0]  , newY = y + dir4[i][1];
		if (isValid(newX , newY , n , m))
			retVal = min(retVal , 1 + fun(n, m, newX, newY));
	}
	visited[x][y] = -1;
	return retVal;
}



void pavan_coder()
{
	memset(visited, -1, sizeof(visited));

	ll n, m;
	cin >> n >> m;


	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
			cin >> arr[i][j];
	}

	for (ll i = 0; i < n; i++)
	{
		for (ll j = 0; j < m; j++)
		{
			if (arr[i][j] == 0)
			{
				pair<ll, ll>up = { i - 1, j };
				pair<ll, ll>down = {i + 1, j };
				pair<ll, ll>left = {i, j - 1};
				pair<ll, ll>right = {i , j + 1};
				if (up.f >= 0 && up.f < n && up.s >= 0 && up.s < m && arr[up.f][up.s] == 1 )
				{
					arr[up.f][up.s] = -1;
				}
				if (down.f >= 0 && down.f < n && down.s >= 0 && down.s < m && arr[down.f][down.s] == 1 )
				{
					arr[down.f][down.s] = -1;
				}
				if (left.f >= 0 && left.f < n && left.s >= 0 && left.s < m && arr[left.f][left.s] == 1)
				{
					arr[left.f][left.s] = -1;
				}
				if (right.f >= 0 && right.f < n && right.s >= 0 && right.s < m && arr[right.f][right.s] == 1)
				{
					arr[right.f][right.s] = -1;
				}
			}
		}
	}
	ll ans = INF;

	for (ll i = 0; i < n; i++)
	{
		if (arr[i][0] == 1)
			ans = min( ans , fun(n, m, i, 0));
	}
	if (ans == INF)
		cout << "Impossible to reach";
	else
		cout << ans;
}

int main()
{
	fast_io;
	file();
	ll tc = 1;
// 	cin >> tc;
	while (tc--)
	{
		pavan_coder();
	}
}



