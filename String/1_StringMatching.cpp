#include<bits/stdc++.h>
using namespace std;

#define ll long long



bool isMatch(ll l, ll r, string str, string pat)
{
    for (ll i = 0; i < pat.length(); i++)
    {
        if (str[i + l] != pat[i])
            return false;
    }
    return true;
}


int main()
{
    string str, pat;
    cin >> str >> pat;

    vector<ll>ans;
    ll n = str.length() , m = pat.length();
    for (ll l = 0 , r = m - 1; r < n; l++, r++)
    {
        if (isMatch(l, r, str, pat))
            ans.push_back(l);
    }
    for (ll i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";

}

