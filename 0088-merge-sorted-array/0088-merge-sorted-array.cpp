class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m == 0) nums1[0] = nums2[0];
        int point1 = m-1; //0
        int point2 = n-1; // 0
        int k = nums1.size()-1; //1
        while(point1 >= 0 && point2>=0 ){
            if(nums1[point1] < nums2[point2])
            {
                nums1[k] = nums2[point2];
                point2-- ;
            }    
            else  
            {
                nums1[k] = nums1[point1];
                point1-- ;
            }
            k--;    
        }
        while(k>=0 && point2>=0)
        {
            nums1[k]=nums2[point2];
            k--;
            point2--;
        }
        // if (nums1.size()>1) {
        //     if(nums1[0]>nums2[0])
        //   nums1[0]=nums2[0];
        // }
            
    }
};