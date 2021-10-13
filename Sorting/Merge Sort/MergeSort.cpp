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


// Merging provided partitions
void merge(ll arr[], ll sp, ll mid, ll ep) {
    ll tmp[ep - sp];
    ll curPtr = 0;

    ll i = sp, j = mid;
    while (i < mid && j < ep) {
        if (arr[i] <= arr[j]) {
            tmp[curPtr] = arr[i];
            i++;
        }
        else {
            tmp[curPtr] = arr[j];
            j++;
        }
        curPtr++;
    }
    while (i < mid) {
        tmp[curPtr] = arr[i];
        i++;
        curPtr++;
    }
    while (j < ep) {
        tmp[curPtr] = arr[j];
        j++;
        curPtr++;
    }
    for (ll i = sp; i < ep; i++) {
        arr[i] = tmp[i - sp];
    }
}


// Making patrition
void partition(ll arr[], ll left , ll right) {
    if (right - left > 1) {
        ll mid = left + (right - left) / 2;
        partition(arr, left, mid);
        partition(arr, mid, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    fast_io;
    // file();
    ll no;
    cin >> no;
    ll arr[no];
    for (ll i = 0; i < no; i++)
        cin >> arr[i];

    partition(arr, 0, no);

    for (ll i = 0; i < no; i++)
        cout << arr[i] << " ";
    return 0;
}
