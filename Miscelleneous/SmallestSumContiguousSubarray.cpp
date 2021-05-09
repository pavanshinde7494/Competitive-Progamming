

int dp[1001];
int AntiKadane(int arr[] , int N)
{
    int ans = arr[0];
    dp[0] = arr[0];

    for(int i=1;i<N;i++)
    {
        dp[i] = min(arr[i] , dp[i-1] + arr[i]);
        ans = min(ans , dp[i]);
    }
    return ans;
}
