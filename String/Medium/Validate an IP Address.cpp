
#include <bits/stdc++.h>
using namespace std;

int isValid(string s)
{
    if (count(s.begin(), s.end(), '.') > 3)
    {

        return 0;
    }
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '.')
            continue;
        if ((s[i] >= '0' && s[i] <= '9') == false)
        {
            return 0;
        }
    }
    stringstream ss(s);
    string str;
    while (getline(ss, str, '.'))
    {
        if (str[0] == '0' && str.size() != 1)
        {
            return 0;
        }
        if (stoi(str) > 255)
            return 0;
    }
    return 1;
}
