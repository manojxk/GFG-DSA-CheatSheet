#include <bits/stdc++.h>
using namespace std;
vector<string> graycode(int n)
{
    if (n == 1)
    {
        return {"0", "1"};
    }
    vector<string> v = graycode(n - 1);
    vector<string> rstr;
    for (int i = 0; i < v.size(); i++)
    {
        rstr.push_back("0" + v[i]);
    }
    for (int i = v.size() - 1; i >= 0; i--)
    {
        rstr.push_back("1" + v[i]);
    }
    return rstr;
}
