#include <bits/stdc++.h>
using namespace std;
/*
count letter appearance and store in hash[i]
find the letter with largest occurence.
put the letter into even index numbe (0, 2, 4 ...) char array
put the rest into the array
*/

string reorganizeString(string S)
{
    vector<int> hash(26, 0);
    for (int i = 0; i < S.size(); i++)
    {
        hash[S[i] - 'a']++;
    }
    int max = 0, letter = 0;
    for (int i = 0; i < 26; i++)
    {
        if (hash[i] > max)
        {
            max = hash[i];
            letter = i;
        }
    }
    if (max > (S.size() + 1) / 2)
    {
        return "";
    }
    int n = S.size();
    string res(n, 'x');
    int idx = 0;
    while (hash[letter] > 0)
    {
        res[idx] = (char)(letter + 'a');
        idx += 2;
        hash[letter]--;
    }
    for (int i = 0; i < 26; i++)
    {
        while (hash[i] > 0)
        {
            if (idx >= n)
            {
                idx = 1;
            }
            res[idx] = (char)(i + 'a');
            idx += 2;
            hash[i]--;
        }
    }
    return res;
}