// Applications of catalan no.
	
// 1.Count the number of expressions containing n pairs of parentheses which are correctly matched. 
//   For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).
// 2.Count the number of possible Binary Search Trees with n keys (See this)
// 3.Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.
// 4.Given a number n, return the number of ways you can draw n chords in a circle with 2 x n points such that no 2 chords intersect.


ll dp[1001];
    
ll catalan(int n){

	if(n == 0 || n == 1)    
	    return 1;
	    
	ll res = 0;
	
	for(int i=0;i<n;i++)
	{
	    ll a ,b;
	    
	    if(dp[i]!=-1)
		a = dp[i];
	    else{
		a = dp[i] = fun(i);
	    }
		
	    if(dp[n-i-1]!=-1)
		b = dp[n-i-1];
	    else{
		b = dp[n-i-1] = fun(n-i-1);
	    }
	    res =  res + a*b;
	}
	return res;
}
    
    
// More efficient using nCr Approch

ll dp[1000];   


ll nCr(ll n,ll r)
{
    if(r>n)
        return 0;
        
    dp[0] = 1;
    dp[1] = n;
    for(ll i=2;i<=r;i++)
    {
        dp[i] = (dp[i-1]*(n-i+1))/i;
    }
    return dp[r];
}   

ll catalan(ll n)
{
    return nCr(2*n,n)/(n+1);
}
