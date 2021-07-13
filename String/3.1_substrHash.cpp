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


now I want hash of string [1,4]
so, hash(1,4) = (dp[4] - dp[0])/p^1

here we want to do division so , insted we will store its modular inverse in inv[1]

so, hash(1,4) = (dp[4] - dp[0])*inv[1];

*/

ll inv[1000];
ll dp[1000];


ll power(ll a , ll n)
{
    ll result = 1;
    while (n)
    {
        if ( n & 1 ) result = (result * a) % mod;

        n /= 2 ;
        a = (a * a) % mod;
    }
    return result;
}


void init(string input_string)
{
    // p-> any prime no > no. elements in characterset
    ll p = 31;
    ll p_power = 1;

    inv[0] = 1;
    dp[0] = (input_string[0] - 'a' + 1);

    for (ll i = 1; i < input_string.length(); i++)
    {
        char ch = input_string[i];

        // current power
        p_power = (p_power * p) % mod;

        // hash until current prefix
        dp[i] = (dp[i - 1] + ( ch - 'a' + 1 ) * p_power) % mod;
        
        // inverse of p^i
        inv[i] = power(p_power , mod - 2);
    }

}


ll substringHash(ll L , ll R)
{
    // if L == 0 we will get ans directly as dp[R]

    ll result = dp[R];


    // removing unwanted part
    if ( L > 0 ) result -= dp[L - 1];

    // modular divison
    result = (result * inv[L]) % mod;
    
    return result;

}



int main()
{
    fast_io;
    // file();


    string input_string;
    ll tc , L , R;

    cin >> tc;
    cin >> input_string;

// initialize dp and inv
    init(input_string);

    for (ll i = 0; i < tc; i++)
    {
        cin >> L >> R;
        cout << substringHash(L, R) << "\n";
    }

    return 0;
}
