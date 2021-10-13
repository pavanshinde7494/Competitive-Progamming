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

void mergeSort(ll arr[], ll left, ll mid, ll right) {
    ll maxEle = 1000;
    ll i = left, j = mid, curPtr = left;

    while (i < mid && j < right) {
        ll e1 = arr[i] % maxEle;
        ll e2 = arr[j] % maxEle;

        if (e1 <= e2) {
            arr[curPtr] = arr[curPtr] + (e1) * maxEle;
            i++;
            curPtr++;
        }
        else {
            arr[curPtr] = arr[curPtr] + (e2) * maxEle;
            j++;
            curPtr++;
        }
    }
    while (i < mid) {
        ll e1 = arr[i] % maxEle;
        arr[curPtr] = arr[curPtr] + (e1) * maxEle;
        i++;
        curPtr++;
    }
    while (j < right) {
        ll e2 = arr[j] % maxEle;
        arr[curPtr] = arr[curPtr] + (e2 ) * maxEle;
        j++;
        curPtr++;
    }
    for (ll i = left; i < right; i++) {
        arr[i]  /= maxEle;
    }
}

void partition(ll arr[], ll left, ll right) {
    if (right - left > 1) {
        ll mid = left + (right - left) / 2;
        partition(arr, left, mid);
        partition(arr, mid, right);
        mergeSort(arr, left, mid, right);
    }
}

int main() {
    fast_io;
    file();
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
