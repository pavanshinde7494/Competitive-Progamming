#include<bits/stdc++.h>
#define ll long long

using namespace std;



/*
Applications ->
1)Find GCD
2)Find modulo inverse
3)Linear Diophentine equation


Logic->

Postulate->
for ax + by = g(a,b) ------------------> There exist at least 1 integral sol.
g = GCD


e.g
81x + 57y = g(81,57)

we will write each no. as linear combo of another no. and
modulo of that no. with another
i.e.

81 = 1(57) + 24             -----1
57 = 2(24) + 9              -----2
24 = 2(9)  + 6              -----3
9  = 1(6)  + 3(gcd)         -----4
6  = 2(3)  + 0              -----5
       ^
       |
    this is gcd
Now, will try to write gcd in linera combo. of a and b

3 = 9 - 1(6)                                       ------from 4
3 = 9 - 1(24 - 2(9)) =-1(24) + 3(9)                ------from 3
3 = 1(24) + 3(57 - 2(24)) = 3(57) - 7(24)          ------from 2
3 = 3(57) - 7(81 - 1(57)) = -7(81) + 10(57)        ------from 1

and we finally got

-7(81) + 10(57) = 3                 x = -7 and y = 10
*/



/*

implementation :(partially same as normal euclid)

gcd(81,57)
    |
gcd(57,24)
    |
gcd(24,9)
    |
gcd(9,6)
    |
gcd(6,3)
    |
gcd(3,0)            (base case x = 1 , y = 0)



Now , we are travesing back in recursion tree
let consider at any intermediate situation we have->

ax + by = g (current state)          and          a1x1 + b1y1 = g (state just below of current)

from prev calculation -> a1 = b , b1 = a%b (simple euclid)

so , bx1 + (a%b)y1 = g
=>   bx1 + [a - (a/b)*b]y1 = g
=>   ay1 + b[x1 - (a/b)*y1] = g (state just below of current)


comparing (current state) and (state just below of current)

x = y1 and y = x1 - (a/b)*y1
and at each step we can calculate this and ultimately reach actual ans

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




int main()
{
	ll a = 81 , b = 57;
	ll x = 0 , y = 0;
	cout << gcd(a, b, x, y) << endl;
	cout << x << " " << y;
}

