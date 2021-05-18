#include<bits/stdc++.h>

using namespace std;

/* 
Approch -> 
    When things happen to you , consider them as worst
    When you do things , do your best
*/
bool dp[1000];

bool doWin(int coin_remain)
{
    // if coin_remain is -ve then , it is fauorable
    if(coin_remain <= 0)
        return true;
    return dp[coin_remain];
}


void computePossibility(int x,int y,int n)
{
    dp[1] = dp[x] = dp[y] = true;

    for(int i=2;i<=n;i++)
    {
        // Things are happening to me , so considered them as worst taking AND

        bool fstPos = (doWin(i-1-1) && doWin(i-1-x) && doWin(i-1-y));
        bool sndPos = (doWin(i-x-1) && doWin(i-x-x) && doWin(i-x-y));
        bool ThrPos = (doWin(i-y-1) && doWin(i-y-x) && doWin(i-y-y));

        // I am doing things , so considered them as best taking OR
        dp[i] = (fstPos || sndPos || ThrPos);
    }
}

int main()
{
    memset(dp,0,sizeof(dp));
    int x,y,n;
    cin>>n>>x>>y;

    computePossibility(x,y,n);

    if(dp[n])
        cout<<"I can Win";
    else
        cout<<"No Possibility of Win";
}
