class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.size() == 0) return false;
    	if(matrix[0].size() == 0) return false;
    	int startX = matrix[0].size()-1;
    	int startY = 0;
    	while(true){
    		if(matrix[startY][startX] == target) return true;
    		if(matrix[startY][startX] > target){
    			startX--;
    		}else{
    			startY++;
    		}
    		if(startX < 0 || startY >= matrix.size()) break;
    	}
    	return false;
    }
};
