
/*
logic->
lets take an example

str = "coding"

so,  hash(str) = 'c' + 'o'p + 'd'p^2 + 'i'p^3 + 'n'p^4 + 'g'p^5

now we will store hash of each prefix in dp[]

dp[0] = 'c'
dp[1] = 'c' + 'o'p
dp[2] = 'c' + 'o'p + 'd'p^2
dp[3] = 'c' + 'o'p + 'd'p^2+ 'i'p^3
dp[4] = 'c' + 'o'p + 'd'p^2+ 'i'p^3 + 'n'p^4
dp[5] = 'c' + 'o'p + 'd'p^2+ 'i'p^3 + 'n'p^4 + 'g'p^5


now pattern = "dig";


so, at position 2 we will find pattern. hence at that instance
=> hash(pattern) * p^2 = dp[4] - dp[1];

*/



ll dp[100001];
ll pat_hash = 0;
ll p = 31;

void init(string str, string pat)
{

    // calculating pattern hash
    ll p_power = 1;
    for (ll i = 0; i < pat.length(); i++)
    {
        ll ch  = pat[i] - 'a' + 1;
        pat_hash = (pat_hash + ( ch * p_power ) % mod) % mod;
        p_power = (p_power * p) % mod;
    }


    // calculating hash for each prefix
    p_power = 31;

    dp[0] = str[0] - 'a' + 1;
    for (ll i = 1; i < str.length(); i++)
    {
        ll ch = str[i] - 'a' + 1;
        dp[i] = (dp[i - 1] + (ch * p_power) % mod) % mod;
        p_power = (p_power * p) % mod;
    }
}


int main()
{
    fast_io;
    // file();

    string str, pat;
    cin >> str >> pat;


    memset(dp, 0, sizeof(dp));
    init(str, pat);


    ll patLen = pat.length(), strLen = str.length();

    ll p_power = 1;
    for (ll i = 0; i <= strLen - patLen; i++)
    {

        if (i == 0) {
            if (dp[patLen - 1] == pat_hash)
                cout << i << "\n";
        }

        else {
            if ((dp[patLen - 1 + i]  - dp[i - 1]) == (pat_hash * p_power) % mod)
                cout << i << "\n";
        }
        p_power = (p_power * p) % mod;
    }

}
