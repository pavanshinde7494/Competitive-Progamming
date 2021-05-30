#include<bits/stdc++.h>
#define ll long long

using namespace std;


void NGL(ll arr[] , ll no)
{
    stack<ll>stk;
    ll indices[no];
    
    
    // We are traversing array from left bcoz we want element of array in stack in same order as they are from right of current element to left 
    // means just left of current array element must be on top of stack
    for(ll i=0;i<no;i++)
    {
        while(!stk.empty())
        {
            if(arr[stk.top()] < arr[i])     
            {
                // Poping the element bcoz this never will be answer for remaining elements of array
                stk.pop();
            }
            else
            {
                // We found our answer
                indices[i] = stk.top();
                break;
            }
        }
        
        // chekcking stack is empty bcoz there will be case if no element at left is greater than current elements of array
        
        if(stk.empty())
            indices[i] = -1;
            
        // Pushing currient element in the array for further computation
        stk.push(i);
    }
    for(ll i=0;i<no;i++)
        cout<<indices[i]<<" ";
}

int main()
{
    ll no;
    cin>>no;
    ll arr[no];
    for(ll i=0;i<no;i++)
        cin>>arr[i];
    
    NGL(arr,no);
}
