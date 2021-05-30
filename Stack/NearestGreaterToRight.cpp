#include<bits/stdc++.h>
#define ll long long

using namespace std;


void NGR(ll arr[] , ll no)
{
    stack<ll>stk;
    ll indices[no];
    
    // Traversing array from right bcoz we want elements of array in sequence in stack
    // means just right element will on top of stack
    for(ll i=no-1;i>=0;i--)
    {
        while(!stk.empty())
        {
            if(arr[stk.top()] <= arr[i]) 
            {
                // Poping the element bcoz this never will be answer for remaining element
                stk.pop();
            }
            else
            {
                // We found our ans
                indices[i] = stk.top();
                break;
            }
        }
        
        // chekcking stack is empty bcoz there will be case if no element at right is greater than current element
        if(stk.empty())
            indices[i] = -1;
            
        stk.push(i);
    }
    for(ll i=0;i<no;i++)
        cout<<indices[i]<<" ";
}


int  main()
{
    ll no;
    cin>>no;
    ll arr[no];
    
    for(ll i=0;i<no;i++)
        cin>>arr[i];
        
    NGR(arr,no);
}

