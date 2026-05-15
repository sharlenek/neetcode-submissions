class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //2d array of chars passed by reference
        //need to track if something exists three different ways
        //should i use a hashmap? add it to hash and if it exists return false

        //ill brute force w several for loops first
        unordered_set<char> row;
        unordered_set<char> col;
        unordered_set<char> square;

        //this is for row
        for (int i = 0; i < 9; ++i){
            row.clear(); 
            for (int j = 0; j < 9; ++j){ 
                char val = board[i][j];
                if (val != '.'){
                    if (row.count(val)){
                        return false;
                    } else {
                        row.insert(val);
                    }
                }
            }
        }

        //this is for col
        for (int j = 0; j < 9; ++j){ 
            col.clear();
            for (int i = 0; i < 9; ++i){ 
                char val = board[i][j];
                if (val != '.'){
                    if (col.count(val)){
                        return false;
                    } else {
                        col.insert(val);
                    }
                }
            }
        }

        //now for squares
        for (int i = 0; i < 9; i+=3){
            for (int j = 0; j < 9; j+=3){
                square.clear();

                for (int sr = 0; sr < 3; ++sr){
                    for (int sc = 0; sc < 3; ++sc){
                        char val = board[i+sr][j+sc];
                        if (val != '.'){
                            if (square.count(val)){
                                return false;
                            } else {
                                square.insert(val);
                            }
                        }
                    }
                }
            }
        }

        return true;
    }
};
