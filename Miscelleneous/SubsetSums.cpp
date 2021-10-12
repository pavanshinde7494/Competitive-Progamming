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


void solve(vector<ll>&v, ll arr[], ll sp, ll ep, ll curSum, ll ind) {
    if (ind == ep) {
        v.pb(curSum);
        return;
    }
    solve(v, arr, sp, ep, curSum, ind + 1);
    solve(v, arr, sp, ep, curSum + arr[ind], ind + 1);

}

int main() {
    fast_io;
    file();
    ll no, a, b;
    cin >> no >> a >> b;
    ll arr[no];
    for (ll i = 0; i < no; i++)
        cin >> arr[i];
    vector<ll>v1, v2;

    solve(v1, arr, 0, no / 2, 0, 0);
    solve(v2, arr, no / 2, no, 0, no / 2);

    sort(v2.begin(), v2.end());

    ll cnt = 0;
    for (ll i = 0; i < v1.size(); i++) {
        ll low = lower_bound(v2.begin(), v2.end(), a - v1[i]) - v2.begin() ;
        ll high = upper_bound(v2.begin(), v2.end(), b - v1[i]) - v2.begin();
        // cout << v1[i] << " " << low << "->" << high << "\n";
        cnt += (high - low);
    }
    cout << cnt;

}









