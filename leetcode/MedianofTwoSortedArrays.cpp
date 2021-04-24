class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        arr.insert(arr.end(),nums1.begin(),nums1.end());
        arr.insert(arr.end(),nums2.begin(),nums2.end());
        sort(arr.begin(),arr.end());
        double median=0.0;
        if(arr.size()%2==0)
            median=double(arr[arr.size()/2-1]+arr[arr.size()/2])/2;
        else
            median=double(arr[arr.size()/2]);
        return median;
    }
};