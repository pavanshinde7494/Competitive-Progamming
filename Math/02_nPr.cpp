
ll nPr(ll n,ll r)
{
    if(r>n)
        return 0;
    if( r == 0)
        return 1;
    return nPr(n-1,r) + r*nPr(n-1,r-1); 
}   

