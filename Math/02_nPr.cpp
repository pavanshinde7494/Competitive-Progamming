
ll nPr(ll n,ll r)
{
    if(r>n)
        return 0;
    if( r == 0)
        return 1;
    return nPr(n-1,r) + r*nPr(n-1,r-1); 
}   

//Efficient Sol

ll dp[1000];   


ll nPr(ll n,ll r)
{
    if(r>n)
        return 0;
        
    dp[0] = 1;
    for(ll i=1;i<=r;i++)
    {
        dp[i] = dp[i-1]*(n-i+1);
    }
    for(ll i=0;i<=r;i++)
        cout<<dp[i]<<" ";
    return dp[r];
}   
