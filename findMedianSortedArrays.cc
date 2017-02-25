class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = 0;
        int r1 = nums1.size();
        int l2 = 0;
        int r2 = nums2.size();
        if(r1 == 0 && r2 == 0)return 0;
        if(r1 == 0){
            return (nums2[(r2+1)/2] + nums2[r2/2] )/2.0;
        }else if(r2 == 0){
            return (nums1[(r1+1)/2] + nums1[r1/2] )/2.0;
        }
        int mid1 = (l1 + r1) / 2;
        int mid2 = (l2 + r2) / 2;
        while(l1 < r1 && l2 < r2){
            mid1 = (l1 + r1) / 2;
            mid2 = (l2 + r2) / 2;
            if(nums1[mid1] < nums2[mid2]){
                l1 = mid1 + 1;
                r2 = mid2 - 1;
            }else{
                r1 = mid1 - 1;
                l2 = mid2 + 1;
            }
        }
        while(l1 != r1){
            mid1 = (l1 + r1) / 2;
            if(nums1[mid1] < nums2[mid2]){
                l1 = mid1 + 1;
            }else{
                r1 = mid1 - 1;
            }
        }
        while(l2 != r2){
            mid2 = (l2 + r2) / 2;
            if(nums1[mid2] < nums2[mid2]){
                l2 = mid2 + 1;
            }else{
                r2 = mid2 - 1;
            }
        }
        if( (nums2.size() + nums1.size() ) % 2 == 0 ){
            return (nums1[mid1] + nums2[mid2]) / 2.0;
        }else{
            if(nums1[mid1] < nums2[mid2]){
                return nums1[mid1];
            }else{
                return nums2[mid2];
            }
        }

    }
};
