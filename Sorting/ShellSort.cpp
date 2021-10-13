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


/*
Shell Sort ->
    - It is nothing but gapped insertion sort.
    - In insertion sort array is divied in 2 catagories (i)Sorted (ii)Unsorted
    - And We try to insert element from unsorted pool to sort pool 
    - In the same way we in shell sort but, here insertion is done by some gap to reduce time complexity of insertion sort
    - In short Insertion sort == shell sort where gap = 1
    - Time Complexity -> O(n^2)
*/ 

void file()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}


void shellSort(ll arr[], ll no) {
    for (ll gap = no / 2; gap > 0; gap /= 2) {
        for (ll i = gap; i < no; i++) {
            for (ll j = i ; j - gap >= 0 && arr[j - gap] > arr[j] ; j -= gap)
                swap(arr[j] , arr[j - gap]);
        }
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

    shellSort(arr, no);

    for (ll i = 0; i < no; i++)
        cout << arr[i] << " ";
    return 0;
}

