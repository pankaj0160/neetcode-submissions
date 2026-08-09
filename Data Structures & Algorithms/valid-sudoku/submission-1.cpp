class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // -------------------------
        // 1. Check Rows
        // -------------------------

        for(int row = 0; row < 9; row++) {

            unordered_set<char> seen;

            for(int col = 0; col < 9; col++) {

                char value = board[row][col];

                // ignore empty cells
                if(value == '.')
                    continue;

                // duplicate found
                if(seen.find(value) != seen.end())
                    return false;

                // store number
                seen.insert(value);
            }
        }


        // -------------------------
        // 2. Check Columns
        // -------------------------

        for(int col = 0; col < 9; col++) {

            unordered_set<char> seen;

            for(int row = 0; row < 9; row++) {

                char value = board[row][col];

                // ignore empty cells
                if(value == '.')
                    continue;

                // duplicate found
                if(seen.find(value) != seen.end())
                    return false;

                // store number
                seen.insert(value);
            }
        }


        // -------------------------
        // 3. Check 3 x 3 Boxes
        // -------------------------

        for(int startRow = 0; startRow < 9; startRow += 3) {

            for(int startCol = 0; startCol < 9; startCol += 3) {

                unordered_set<char> seen;


                // move inside current 3x3 box
                for(int row = 0; row < 3; row++) {

                    for(int col = 0; col < 3; col++) {


                        char value = board[startRow + row][startCol + col];


                        // ignore empty cells
                        if(value == '.')
                            continue;


                        // duplicate found in box
                        if(seen.find(value) != seen.end())
                            return false;


                        // store number
                        seen.insert(value);
                    }
                }
            }
        }


        // all checks passed
        return true;
    }
};