
// Knuth-Morris-Pratt String matching algorithm
// This algorithm is used to make substring matches using pi functino

// pi function -> It gives maximum proper substring from i th element which is prefix of that string

ll pi[100001];



// Logic -> value pi[i] will be at max pi[i-1] + 1 i.e p[i] <= p[i-1] + 1 
void kmp(string str)
{
    ll n = str.length();
    memset(pi, 0, sizeof(pi));

    for (ll i = 1; i < n; i++)
    {
        // First check for just before element
        ll j = pi[i - 1];

        while (j > 0 && str[i] != str[j])
        {
            // if str[i] is not matching with str[j] then we have to decrease our search space
            // and will take next possible number by making j = p[j-1]
            j = pi[j - 1];
        }


        // Finally if in case str[i] and str[i] matches then just increment j
        // bcoz j is value for current possible substring
        if (str[i] == str[j])
            j++;

        
        pi[i] = j;

    }
}
