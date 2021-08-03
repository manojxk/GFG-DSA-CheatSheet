#include <bits/stdc++.h>
using namespace std;

void ps(string tmp, int i, string s, vector<string> &v)
{
    int n = s.size();
    if (i == n)
    {
        v.push_back(tmp);
        return;
    }
    ps(tmp + " " + s[i], i + 1, s, v);
    ps(tmp + s[i], i + 1, s, v);
}
vector<string> permutation(string S)
{
    // Code Here
    vector<string> v;
    string tmp = "";
    tmp.push_back(S[0]);
    ps(tmp, 1, S, v);
    return v;
}