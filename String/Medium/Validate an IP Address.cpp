
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int isValid(string s)
    {
        if (count(s.begin(), s.end(), '.') > 3)
            return 0;
        // check if the string only contains digits
        // if not then return false
        for (int i = 0; i < s.size(); i++)
            if ((s[i] >= '0' && s[i] <= '9') == false)
                return false;
        stringstream ss(s);
        string str;
        while (getline(ss, str, '.'))
        {
            if (str[0] == '0' and str.size() != 1)
            {
                return 0;
            }
            if (stoi(str) > 255)
                return 0;
        }
        return 1;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isValid(s) << endl;
    }
    return 0;
}