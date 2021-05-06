// Maximum subsequence sum such that no three are consecutive
int NoThreeConsecutive(int a[] , int n)
{
    int dp[n][2];
    dp[0][0] = dp[0][1] = a[0];
    dp[1][0] =  a[0] + a[1];
    dp[1][1] = a[1];

    for(int i=2;i<n;i++)
    {
        dp[i][0] = dp[i-1][1] + a[i];
        dp[i][1] = a[i] + max(dp[i-2][0],dp[i-2][1]);
        // cout<<dp[i][0]<<" "<<dp[i][1]<<"\n";
    }
    return max(dp[n-1][0],dp[n-1][1]);
}
