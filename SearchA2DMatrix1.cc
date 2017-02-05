class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    	if(matrix.size() == 0){
    		return false;
    	}
    	if(matrix[0].size() == 0){
    		return false;
    	}
    	vector<int> leftSide;
    	for (int i = 0; i < matrix.size(); ++i)
    	{
    		leftSide.push_back(matrix[i][0]);
    	}
    	if(leftSide[0] >  target) return false;
    	if(leftSide[leftSide.size()-1] < target){
    		vector<int> tmp = matrix[matrix.size()-1];
    		if(tmp[0] >  target || tmp[tmp.size()-1] < target) return false;
    		if(*lower_bound(tmp.begin(), tmp.end(), target) == target){
    			return true;
    		}else{
    			return false;
    		}
    	}

    	auto itr = lower_bound(leftSide.begin(), leftSide.end(), target);
    	if(*itr == target){
    		return true;
    	}
    	if(itr == leftSide.begin()){
    		return false;
    	}
    	itr--;
    	int indx = itr - leftSide.begin();
    	vector<int> tVector = matrix[indx];
    	if(tVector[0] >  target || tVector[tVector.size()-1] < target) return false;
    	auto itr2 = lower_bound(tVector.begin(), tVector.end(), target);
    	if(*itr2 == target){
    		return true;
    	}
    	return false;
    }
};