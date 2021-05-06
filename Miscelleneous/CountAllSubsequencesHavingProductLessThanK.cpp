// Count all subsequences having product <= k
int cntAllSubSeq(int a[] , int n,int k)
{
    int dp[n+1][k+1];
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++)
    {
        for(int j = 1; j<=k;j++)
        {
            dp[i][j] = dp[i-1][j];
            if(a[i-1] <= j)
            {
                dp[i][j] += (1 + dp[i-1][j/a[i-1]]);
            }
        }
    }
    return dp[n][k];
}
