string reverseWords(string s)
{
    reverse(s.begin(), s.end());
    string str, res;
    stringstream ss(s);
    while (getline(ss, str, '.'))
    {
        reverse(str.begin(), str.end());
        res += str + '.';
    }
    return res.substr(0, res.size() - 1);
}