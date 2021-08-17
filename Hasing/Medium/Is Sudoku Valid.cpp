class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<string> seen;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] != '.')
            {
                char num = board[i][j];

                string s1 = to_string(num) + " in row " + to_string(i);
                string s2 = to_string(num) + " in column " + to_string(j);
                string s3 = to_string(num) + " in block " + to_string(i / 3) + "-" + to_string(j / 3);

                if (seen.find(s1) != seen.end() or seen.find(s2) != seen.end() or seen.find(s3) != seen.end())
                    return false;
                seen.insert(s1);
                seen.insert(s2);
                seen.insert(s3);
            }
        }
    }
    return true;
        
    }
};