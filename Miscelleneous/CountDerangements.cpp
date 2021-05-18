
#include<bits/stdc++.h>
#define ll long long

using namespace std;

ll dp[1000];

ll findDerangements(ll no)
{
    if(no == 1)
        return 0;
    if(no == 2)
        return 1;
    if(dp[no] != -1)
        return dp[no];

/*
    lets say at 0th position , we can place every no. other than 0 which explains multiplication with (n-1)

    now, at ith postion we placed 0 and at 0th position we placed i then we just have to find answer for res (no-2) elements and
    if we just placed 0 at ith position and any other element at 0th position so, now we have to solve it for (no-1) elements hence
    fun call for (no-1) and (no-2) is there
*/
    return dp[no] = (n-1)*(findDerangements(no-1) + findDerangements(no-2));
}

int main()
{
    memset(dp,-1,sizeof(dp));
    ll no;
    cin>>no;

    cout<<findDerangements(no);
}

