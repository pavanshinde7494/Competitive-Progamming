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


map<ll, ll>m1;
map<ll, ll>m2;
ll dp[100001][2];



ll maxSum(ll arr1[], ll no1, ll arr2[], ll no2, ll ind, bool isSec) {
    ll poss1 = 0 , poss2 = 0;
    if (dp[ind][isSec] != -1)return dp[ind][isSec];
    if (isSec) {
        if (ind == no2 + 1)
            return 0;
        if (m1[arr2[ind]] != 0) {
            return dp[ind][isSec] = arr2[ind] + max(maxSum(arr1, no1, arr2, no2, ind + 1, isSec) , maxSum(arr1, no1, arr2, no2, m1[arr2[ind]] + 1, false)) ;
        }
        else {
            return dp[ind][isSec] = arr2[ind] + maxSum(arr1, no1, arr2, no2, ind + 1, isSec);
        }
    }
    else {
        if (ind == no1 + 1)
            return  0;
        if (m2[arr1[ind]] != 0) {
            return dp[ind][isSec] = arr1[ind] + max(maxSum(arr1, no1, arr2, no2, ind + 1, isSec) , maxSum(arr1, no1, arr2, no2, m2[arr1[ind]] + 1, true));
        }
        else {
            return dp[ind][isSec] = arr1[ind] + maxSum(arr1, no1, arr2, no2, ind + 1, isSec);
        }
    }
    return -1;
}

int main() {
    fast_io;
    file();

    while (1) {
        m1.clear();
        m2.clear();

        ll no1 , no2;

        cin >> no1;

        if (no1 == 0)break;

        ll arr1[no1 + 1];
        for (ll i = 1; i <= no1; i++) {
            cin >> arr1[i];
            m1[arr1[i]] = i;
        }


        cin >> no2;
        ll arr2[no2 + 1];
        for (ll i = 1; i <= no2; i++) {
            cin >> arr2[i];
            m2[arr2[i]] = i;
        }
        memset(dp, -1, sizeof(dp));
        ll res1 = maxSum(arr1, no1, arr2, no2, 1, 0);
        memset(dp, -1, sizeof(dp));
        ll res2 = maxSum(arr1, no1, arr2, no2, 1, 1);
        // cout << res1 << ' ' << res2 << "\n";
        cout << max(res1 , res2) << "\n";
    }
    return 0;
}
