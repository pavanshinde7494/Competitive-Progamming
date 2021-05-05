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

const int dir4[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

const int dir8[8][2] = {{0, 1}, {0, -1}, {1, 0}, { -1, 0}, {1, 1}, {1, -1}, { -1, 1}, { -1, -1}};

/*--------------------------------------------------------code starts here--------------------------------------------------------------*/


// int a[][4] = { { 4, 5, 3, 2 },
//               { 2, 10, 1, 4 } };
// int t[][4] = { { 0, 7, 4, 5 },
//               { 0, 9, 2, 8 } };
// int e[] = { 10, 12 }, 
// x[] = { 18, 7 };


// 35

void pavan_coder()
{
    
    int n = 4;
    
    int a[][4] = { { 4, 5, 3, 2 },
                   { 2, 10, 1, 4 } };
              
    int t[][4] = { { 0, 7, 4, 5 },
                   { 0, 9, 2, 8 } };
                
    int e[] = { 10, 12 }, x[] = { 18, 7 };
    
    int dp[3][5];
    
    dp[0][0] = e[0] + a[0][0];
    dp[1][0] = e[1] + a[0][1];
    
    for(int i=1;i<n;i++)
    {
        // Filling 1st row
        int cost;
        
        cost = a[0][i] + min(dp[0][i-1] , dp[1][i-1] + t[1][i]);
        
        dp[0][i] = cost;
        
        // Filling 2nd row
        
        cost = a[1][i] + min(dp[1][i-1] , dp[0][i-1] + t[0][i]);
        dp[1][i] = cost;
        
    }
    
    cout<<min(dp[0][n-1] + x[0] , dp[1][n-1] + x[1]);
                
}


int main()
{
	fast_io;
	ll tc = 1;
// 	cin>>tc;
	while(tc--)
	{
		pavan_coder();
	}
}








