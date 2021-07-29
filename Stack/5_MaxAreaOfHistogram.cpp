 int maxArea(int arr[], int n)
{

    int nsr[n];
    int nsl[n];


    stack<int>stk1;
    stack<int>stk2;
  
   
//    Finding Nearest smaller to right
    for(int i = n-1;i>=0;i--)
    {
        while(!stk1.empty())
        {
            if(arr[stk1.top()] >= arr[i])
                stk1.pop();
            else
            {
                nsr[i] = stk1.top();
                break;
            }
        }
        if(stk1.empty())
        {   
            nsr[i] = n;
        }
        stk1.push(i);
    }

// Finding nearest smaller to left
    for(int i=0;i<n;i++)
    {
        while(!stk2.empty())
        {
            if(arr[stk2.top()] >= arr[i] )
                stk2.pop();
            else
            {
                nsl[i] = stk2.top();
                break;

            }
        }
        if(stk2.empty())
        {
            nsl[i] = -1;
        }
        stk2.push(i);
    }

    int ans = 0;
    for(int i=0;i<n;i++)
    {
        int curArea = arr[i]*((nsr[i]-1) - (nsl[i]+1) + 1);
        ans = max(ans , curArea);
    }
    return ans;
}
