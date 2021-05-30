#include<bits/stdc++.h>
#define ll long long

using namespace std;


void NSR(ll arr[] , ll no)
{
    stack<ll>stk;
    ll indices[no];
    
    // Traversing array from right bcoz we want elements of array in stack (in the same sequence as they are)
    // means just right element of array will on top of stack
    for(ll i=no-1;i>=0;i--)
    {
        while(!stk.empty())
        {
            if(arr[stk.top()] >= arr[i]) 
            {
                // Poping the element bcoz this never will be answer for remaining elements of array
                // bcoz we found current element is still smaller than available numbers in stack
                stk.pop();
            }
            else
            {
                // We found our answer
                indices[i] = stk.top();
                break;
            }
        }
        
        // chekcking stack is empty bcoz there will be case if no element at right is greater than current element
        if(stk.empty())
            indices[i] = -1;
        // adding current element in stack for further computaion             
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
        
    NSR(arr,no);
}

