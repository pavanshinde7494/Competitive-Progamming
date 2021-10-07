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



bool cmp(pair<ll, ll>p, pair<ll, ll>q) {
    if (p.first == q.first)return p.second < q.second;
    return p.first < q.first;
}

void pavan_coder()
{
    ll no , q;
    cin >> no >> q;
    vector<pair<ll, ll>> arr;
    for (ll i = 0; i < no; i++) {
        ll a, b;
        cin >> a >> b;
        if (a < b)
            arr.push_back({a, b});
        else
            arr.push_back({b, a});
    }
    sort(arr.begin(), arr.end(), cmp);
    ll sp = arr[0].first , ep = arr[0].second;
    vector<pair<pair<ll, ll>, ll>>range;
    ll curCnt = 0;
    for (ll i = 1; i < arr.size(); i++) {
        if (arr[i].first <= ep + 1) {
            ep = max(ep , arr[i].second);
        }
        else {
            curCnt += (ep - sp + 1);
            range.push_back({{sp, ep} , curCnt });
            sp = arr[i].first;
            ep = arr[i].second;
        }
    }
    curCnt += (ep - sp + 1);
    range.push_back({{sp, ep}, curCnt});

    // for (ll i = 0; i < range.size(); i++) {
    //     cout << range[i].first.first << " " << range[i].first.second << "->>" << range[i].second << "\n";
    // }

    while (q--) {
        ll query;
        cin >> query;
        if (query > curCnt) {
            cout << -1 << "\n"; continue;
        }
        ll left = 0, right = range.size() - 1;
        ll mid = (left + right) / 2;
        ll res = mid;
        while (left <= right) {
            mid = (left + right) / 2;
            if (query <= range[mid].second) {
                res = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        if (res == 0) {
            cout << range[res].first.first + query - 1 << "\n";
            continue;
        }
        ll offset = query - range[res - 1].second;
        cout << range[res].first.first + offset - 1 << "\n";
    }
}



int main()
{
    fast_io;
    file();
    ll tc = 1;
    cin >> tc;
    while (tc--)
    {
        pavan_coder();
    }
}



