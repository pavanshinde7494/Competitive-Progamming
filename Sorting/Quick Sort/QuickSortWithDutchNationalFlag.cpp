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

void quickSort(ll arr[], ll left , ll right) {
    if (left >= right - 1)return;
    ll low = left , high = right - 1 , curPtr = left;

    ll pivote = arr[left];

    while (curPtr <= high) {
        if (arr[curPtr] == pivote)curPtr++;
        else if (arr[curPtr] < pivote) {
            swap(arr[curPtr] , arr[low]);
            low++;
        }
        else if (arr[curPtr] > pivote) {
            swap(arr[curPtr] , arr[high]);
            high--;
        }
    }

    quickSort(arr , left , low);
    quickSort(arr , high + 1 , right);
}


int main() {
    fast_io;
    file();
    ll no;
    cin >> no;

    ll arr[no];
    for (ll i = 0; i < no; i++)
        cin >> arr[i];

    quickSort(arr, 0, no);

    for (ll i = 0; i < no; i++)
        cout << arr[i] << " ";
}
