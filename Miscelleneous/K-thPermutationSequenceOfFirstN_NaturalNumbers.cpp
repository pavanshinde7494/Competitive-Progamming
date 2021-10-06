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

vector<vector<ll>>ans;
bool hasTaken[10001];

void getKthPermutation(ll arr[], ll no, ll k, vector<ll>&curCombo, ll curInd) {
    if (curInd == no) {
        ans.push_back(curCombo);
        return;
    }
    for (int i = 0; i < no; i++) {
        if (!hasTaken[arr[i]]) {
            hasTaken[arr[i]] = true;
            curCombo[curInd] = arr[i];

            getKthPermutation(arr, no, k, curCombo, curInd + 1);

            curCombo[curInd] = 0;
            hasTaken[arr[i]] = false;

        }
    }
}


int main()
{
    fast_io;
    file();
    ll arr[10001] , no , k;

    cin >> no >> k;

    for (ll i = 1; i <= no; i++)
        arr[i - 1] = i;


    memset(hasTaken, 0, sizeof(hasTaken));
    vector<ll>curCombo(no, 0);
    getKthPermutation(arr, no, k, curCombo, 0);
    sort(ans.begin(), ans.end());
    cout << "kth Combination : " << "\n";
    for (int i = 0; i < no; i++) {
        cout << ans[k - 1][i] << " ";
    }

}
