#include<bits/stdc++.h>
#define ll long long

using namespace std;



// Part 1

/*
Linaer Diophentine Equation : Application of Extended Euclid


ax + by = c  Here a,b,c given we have to find integral values of x and y


			a = b = 0
			  /\
	                 /  \
			/    \
		       /      \
		   c = 0        c!=0
		  infinite      No Solution
		  solutions

To solve above problem for generel case Extended Euclidian algo.

i.e ax0 + by0 = g(a,b) ------------------------------------> sol. for this eq. always exists
g = GCD

multiply c/g(a,b) on both sides,
a (x0*c/g(a,b)) + b (y0*c/g(a,b)) = c

so, x = x0*c/g(a,b)    and    y = y0*c/g(a,b)  ------------> here sol. will exists only if c%g(a,b) == 0
*/



// Part 2

/*
ax + by = c
Not we have one solution from part 1 but , There can infinite solutions

let say
   a[x + k(b/g)] + b[y - k(a/g)]
=  ax + by + k(ab/g) - k(ab/g)
=  ax + by = c

so, we can conclude

xgen = x + k(b/g)            ygen = y - k(a/g)

*/



// Part 3

/*
min value of (xgen + ygen) = min(xgen +ygen )
= min(x0 + k(b/g) + y0 - k(a/g))
= min( k/g(b - a) )  -------------------------(other are constant)
          /\
         /  \
        /    \
       /      \
      /        \
     b>a       a<b
  k = min     k = max
  possible    possible

   b = a => independent value of k
*/



ll gcd(ll a, ll b, ll &x, ll &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	ll x1, y1;
	ll g = gcd(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}



bool find_any_solution(ll a, ll b, ll c, ll &x, ll &y)
{
	ll x0 , y0;

	// gcd of -ve no. can't be calculated so, abs() is provided
	ll g = gcd(abs(a), abs(b), x0, y0);
	if (c % g != 0)
		return false;
	x = (x0 * c) / g;
	y = (y0 * c) / g;

	if (a < 0)x *= -1;
	if (b < 0)y *= -1;

	return true;
}


int main()
{
	// file();
	ll a = 6 , b = 9 , c = 27 , x = 0, y = 0;
	if (find_any_solution(a, b, c, x, y))
		cout << x << " " << y ;
	else
		cout << "No solution";
}
