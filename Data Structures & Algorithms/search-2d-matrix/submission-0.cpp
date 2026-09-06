class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        //  search to getting row then binary search on that row
        int m = matrix.size();
        int targeted_row = -1;

        for(int i = 0; i < m; i++){
            if(target >= matrix[i][0] && target <= matrix[i][matrix[i].size()-1]) {
                targeted_row = i;
                break;
            } 
        }
        if(targeted_row == -1) return false;

        int i = 0;
        int j = matrix[targeted_row].size()-1;

        while(i <= j){
            int mid = i + (j-i)/2;

            if(matrix[targeted_row][mid] == target) return true;
            else if(matrix[targeted_row][mid] > target) j = mid-1;
            else i = mid+1;
        }
        return false;
    }
};
