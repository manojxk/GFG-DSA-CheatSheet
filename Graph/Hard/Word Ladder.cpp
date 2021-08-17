#include <bits/stdc++.h>
using namespace std;

int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    unordered_set<string> dict(wordList.begin(), wordList.end());
    if (dict.find(endWord) == dict.end())
        return 0;
    int n = beginWord.size();
    int level = 0;
    queue<string> q;
    q.push(beginWord);

    while (!q.empty())
    {
        level++;

        int length = q.size();
        for (int i = 0; i < length; i++)
        {
            string word = q.front();
            q.pop();
            for (int po = 0; po < n; po++)
            {
                int orig_char = word[po];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[po] = c;
                    if (word == endWord)
                        return level + 1;

                    if (dict.find(word) == dict.end())
                        continue;

                    dict.erase(word);

                    q.push(word);
                }
                word[po] = orig_char;
            }
        }
    }
    return 0;
}
