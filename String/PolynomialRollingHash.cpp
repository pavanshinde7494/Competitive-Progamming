#define ll long long
#define mod 1000000007

// Hash = str[0]*p^0 + str[1]*p^1 + str[2]*p^2 + ....... + str[n-1]*p^(n-1)
ll getHash(string str)
{
    ll hash = 0;
    ll p_power = 1;

    // Here p is any prime no. > size of characterset
    // mod is taken to avoid size limit exeeds
    ll p = 31;
    for (char ch : str)
    {
        hash = (hash + (ch - 'a' + 1) * p_power) % mod;
        p_power = (p_power * p) % mod;
    }
    return hash;
}
