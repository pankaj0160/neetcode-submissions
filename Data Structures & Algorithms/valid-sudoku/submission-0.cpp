class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row checking

        for (int i = 0; i < 9; i++) {
            unordered_set<char> s;

            // each row :
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                else if (s.find(board[i][j]) != s.end())
                    return false;
                s.insert(board[i][j]);
            }
        }

        // column checking

        for (int j = 0; j < 9; j++) {
            unordered_set<char> s;
            // each column
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                else if (s.find(board[i][j]) != s.end())
                    return false;
                s.insert(board[i][j]);
            }
        }

        //  box checking :
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                unordered_set<char> s;

                // each box :
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        if (board[i + k][j + l] == '.')
                            continue;
                        else if (s.find(board[i + k][j + l]) != s.end())
                            return false;
                        s.insert(board[i + k][j + l]);
                    }
                }
            }
        }
        return true;
    }
};
