
ll power(ll a , ll n)
{
    ll result = 1;
    while (n)
    {
  //   if n is odd
        if ( n & 1 ) result = (result * a) % mod;

        n /= 2 ;
        a = (a * a) % mod;
    }
    return result;
}
