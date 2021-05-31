#include<bits/stdc++.h>
#define ll long long

using namespace std;



int findMedian(int arr1[],int arr2[],int n1,int n2)
{
    // We will operate in smaller array so that it will time complex less
    if(n1 > n2)
    {
        swap(arr1,arr2);
        swap(n1,n2);
    }
    
    int left = 0,right = n1;
    while(left <= right)
    {
        
        // Makint Partition
        
        // mid1 , mid2 = no. of elements in left side of partition
        int mid1 = left + (right - left)/2;
        int mid2 = (n1 + n2)/2 - mid1;
        
        // l1 , l2  = max element of left partion
        int l1 = (mid1 == 0 ? INT_MIN : arr1[mid1-1]);
        int l2 = (mid2 == 0 ? INT_MIN : arr2[mid2-1]);
        
        // r1 , r2  = min element of right partiton
        int r1 = (mid1 == n1 ? INT_MAX : arr1[mid1]);
        int r2 = (mid2 == n2 ? INT_MAX : arr2[mid2]);
        
        // in order to be at right partition l1 < r2 ans l2 < r1
        
        
        if(l1 > r2)
        {
            // l1 must be reduced so, right has shifted 
            right = mid1 - 1;
        }
        else if(r1 < l2)
        {
            // r1 must be increased so, left has shifted
            left = mid1 + 1; 
        }
        else
        {
            // We have obtained correct partion
            // Just have to check for n1 + n2 is odd or even
            // For even : we always have to check over edge of partion
            // For odd : median will always be at one element after partion
            return ((n1+n2)%2 == 0)?((max(l1,l2) + min(r1,r2))/2):min(r1,r2);
        }
    }
    return 0;
}

int main()
{
    int n1,n2;
    cin>>n1;
    int arr1[n1];
    
    for(int i=0;i<n1;i++)
        cin>>arr1[i];
        
    cin>>n2;
    int arr2[n2];
    
    for(int i=0;i<n2;i++)
        cin>>arr2[i];
    
    cout<<findMedian(arr1,arr2,n1,n2);
}
