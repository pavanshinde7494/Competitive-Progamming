
ll nCr(ll n,ll r)
{
    if(r>n)
        return 0;
    if( r == 0)
        return 1;
    return nCr(n-1,r) + nCr(n-1,r-1); 
}   

