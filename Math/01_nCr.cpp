
ll nCr(ll n,ll r)
{
    if(r>n)
        return 0;
    if( r == 0)
        return 1;
    return nCr(n-1,r) + nCr(n-1,r-1); 
}   

//Efficient Sol

ll dp[1000];   


ll nCr(ll n,ll r)
{
    if(r>n)
        return 0;
        
    dp[0] = 1;
    dp[1] = n;
    for(ll i=2;i<=r;i++)
    {
        dp[i] = (dp[i-1]*(n-i+1))/i;
    }
    for(ll i=0;i<=r;i++)
        cout<<dp[i]<<" ";
    return dp[r];
}   
