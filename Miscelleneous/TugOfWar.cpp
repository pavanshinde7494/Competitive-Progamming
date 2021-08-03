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

ll dp[10][10];

ll dir[8][2] = {{ -2, 1}, { -1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, { -1, -2,}, { -2, -1}};




ll ans = INF;

ll incF[1000];
ll inc[1000];

void fun(ll arr[], ll no, ll ind, ll set1Size , ll set2Size, ll set1Sum, ll set2Sum)
{
	if (ind == no)
	{

		if (ans > abs(set1Sum - set2Sum))
		{
			ans = abs(set1Sum - set2Sum);
			for (ll i = 0; i < no; i++)
			{
				incF[i] = inc[i];
			}
		}
		return;
	}
	if (set1Size > 0 && set2Size)
	{
		inc[ind] = 1;
		fun(arr, no, ind + 1, set1Size - 1, set2Size, set1Sum + arr[ind], set2Sum);
		inc[ind] = 2;
		fun(arr, no, ind + 1, set1Size, set2Size - 1, set1Sum, set2Sum + arr[ind]);
		inc[ind] = -1;
	}
	else if (set1Size > 0)
	{
		inc[ind] = 1;
		fun(arr, no, ind + 1, set1Size - 1, set2Size, set1Sum + arr[ind], set2Sum);
		inc[ind] = -1;
	}

	else if (set2Size)
	{
		inc[ind] = 2;
		fun(arr, no, ind + 1, set1Size, set2Size - 1, set1Sum, set2Sum + arr[ind]);
		inc[ind] = -1;
	}
}



void pavan_coder()
{

	memset(dp, -1, sizeof(dp));
	memset(inc, -1, sizeof(inc));
	ll no;

	cin >> no;


	ll arr[no];

	for (ll i = 0; i < no; i++)
		cin >> arr[i];

	fun(arr, no, 0, no / 2 , no / 2 + no % 2 , 0, 0);

	cout << "1st Set -> ";
	for (ll i = 0; i < no; i++)
	{
		if (incF[i] == 1)
			cout << arr[i] << " ";
	}
	cout << "\n2nd Set -> ";

	for (ll i = 0; i < no; i++)
	{
		if (incF[i] == 2)
			cout << arr[i] << " ";
	}


	cout << "\n" << ans;

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



