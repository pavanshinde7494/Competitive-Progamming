
#include<bits/stdc++.h>
#define ll long long

using namespace std;


vector<ll>ans;

void peakEle(ll arr[] , ll no , left , right)
{
    if(no == 1)
    {
        ans.push_back(0);
        return;
    }
    if(left>right)
        return;
    ll mid = left + (right - left)/2;

    if(mid == 0)
    {
        if(arr[mid] > arr[mid+1])
            ans.push_back(mid);
    }
    else if(mid == no-1)
    {
        if(arr[mid] > arr[mid-1])
            ans.push_back(mid);
    }
    else if( arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1] )
        ans.push_back(mid);
    peakEle(arr,no,left,mid-1);
    peakEle(arr,no,mid+1,right);
}

int main()
{
    ll no;
    cin>>no;
    ll arr[no];
    for(ll i=0;i<no;i++)
        cin>>arr[i];

    peakEle(arr,no,0,no-1);
    for(ll i=0;i<ans.size();i++)
        cout<<ans[i];
}


