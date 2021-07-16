
/*
Logic ->

->  array badChar stores last occurance of a particular character in pattern
->  If bad character(a character which is not matching in given string) is encountered
    then we shift our pattern forward in such a way that the character matches
    with corresponding chracter in pattern    

*/ 

int badChar[256];
void badCharHerustics(string pat)
{
    memset(badChar , -1, sizeof(badChar));
    for (int i = 0; i < pat.length(); i++)
    {
        // Stroring last occurance of particular character
        badChar[pat[i]] = i;
    }
}

void search(string str, string pat)
{
    // Creating badChar array
    badCharHerustics(pat);
    int s = 0;
    int strLen = str.length() , patLen = pat.length();

    // max shift s = strLen - patLen
    while (s <= strLen - patLen)
    {
        // j points last char of pattern
        // s + j points corresponding character in str
        int j = patLen - 1;
        while (j >= 0 && str[s + j] == pat[j])
            j--;


        // Matching substring with pattern is found
        if (j < 0)
        {
            cout << s << "\n";

            // if limit is not exeeding
            if ( s <= strLen + patLen){

                // shiting s correspomding to (s + patLen)th character
                s += ( patLen - badChar[str[s + patLen]] );
            }
            else
                s++;
        }
        else
        {
            // shifting s corresponding to (s+j)th character
            s += max(1 , j - badChar[str[s + j]]);
        }
    }
}


