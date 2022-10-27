class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<set<int>> rows(9), columns(9), blocks(9);
        
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                
                if (board[i][j] == '.')
                    continue;
                
                int current_element_value = board[i][j] - '0';
                if (rows[i].count(current_element_value) || columns[j].count(current_element_value) || blocks[(i/3)*3 + j/3].count(current_element_value))
                    return false;
                
                rows[i].emplace(current_element_value);
                columns[j].emplace(current_element_value);
                blocks[(i/3)*3 + j/3].emplace(current_element_value);
            }
        }
        return true;
    }
};