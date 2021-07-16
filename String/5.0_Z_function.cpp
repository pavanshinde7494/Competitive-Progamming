



ll z[100001];



// Here is a naive approch : self explainatory
void z_function(string str)
{
    ll n = str.length();
    for (ll i = 1; i < n; i++)
    {
        for (ll j = i; j < n; j++)
        {
            if (str[j - i] == str[j])
                z[i]++;
            else
                break;
        }
    }
}




// Efficient approch

// Logic -> Insted of everytime check string from ith char and another from 0th index , 
// We simply try to find out min possible value for z[i] for given string in worst case senario

void z_function(string str)
{
    ll n = str.length();

    ll l = 0 , r = 0;
    for (ll i = 1; i < n; i++)
    {
        // Getting min possible z[i]
        if (i <= r)
            z[i] = min(z[i - l] , r - i + 1);


        // Travesing loop for more discories of matching substring
        while ( i + z[i] < n && str[i + z[i]] == str[z[i]])
            z[i]++;

        // Updating new values if current string matches such that it overtakes value of r
        if (i + z[i] - 1 > r)
            l = i , r = i + z[i] - 1;
    }
}
