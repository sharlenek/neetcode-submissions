class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0){
            return false;
        }

        int leftrow = 0;
        int rightrow = matrix.size()-1;

        int leftcol = 0;
        int rightcol = matrix[0].size()-1;

        int row;
        int col;

        //finding the row
        while (leftrow <= rightrow){
            
            row = (rightrow-leftrow)/2 + leftrow;

            if (matrix[row][leftcol] > target){
                rightrow = row - 1;
            } else if (matrix[row][rightcol] < target){
                leftrow = row + 1;
            } else {
                break;
            }
        }

        if (matrix[row][leftcol] > target || matrix[row][rightcol] < target){
            return false;
        }

        //gotta check if it wasnt found already

        while (leftcol <= rightcol){
            col = leftcol + (rightcol-leftcol)/2;

            if (matrix[row][col] > target){
                rightcol = col - 1;
            } else if (matrix[row][col] < target){
                leftcol = col + 1;
            } else {
                return true;
            }

        }
        return false;
    }
};
