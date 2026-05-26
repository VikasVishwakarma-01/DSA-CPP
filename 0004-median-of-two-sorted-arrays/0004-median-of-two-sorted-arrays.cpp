class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<double> vec;
        
        int i = 0, j = 0;
        while(j < m && i < n) {

            if(nums1[i] < nums2[j]) {
                vec.push_back(nums1[i]);
                i++;
            }
            else {
                vec.push_back(nums2[j]);
                j++;
            }
        }

        while(i < n) {
            vec.push_back(nums1[i]);
            i++;
        }
        while(j < m) {
            vec.push_back(nums2[j]);
            j++;
        }

        int l = vec.size();
        
        if(l % 2 != 0) 
            return vec[l/2];
        
        return (vec[l/2] + vec[(l/2) - 1])/2.0;
    }
};