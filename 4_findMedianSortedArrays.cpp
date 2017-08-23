//
// Created by Peng Qixiang on 2017/8/11.
//
/*
// There are two sorted arrays nums1 and nums2 of size m and n respectively.
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
// nums1 = [1, 3]， nums2 = [2]
// The median is 2.0
// nums1 = [1, 2], nums2 = [3, 4]
// The median is (2 + 3)/2 = 2.5
*/

# include <cstdlib>
# include <iostream>
# include <vector>

using namespace std;

// merge sort
// tc : o(log(m+n))
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    vector<int> res;
    int index1 = 0, index2 = 0;
    int size1 = nums1.size();
    int size2 = nums2.size();
    while(index1 < size1 && index2 < size2){
        if(nums1[index1] <= nums2[index2]) {
            res.push_back(nums1[index1]);
            index1++;
        }
        else{
            res.push_back(nums2[index2]);
            index2++;
        }
    }
    if(index1 == size1){
        for( ; index2 < size2; index2++ )
            res.push_back(nums2[index2]);
    }
    if(index2 == size2){
        for( ; index1 < size1; index1++ )
            res.push_back(nums1[index1]);
    }
    int size3 = res.size();
    if(size3%2)
        return double(res[size3/2]);
    else
        return double(res[size3/2] + res[size3/2 - 1]) / 2;

}

int main(){
    int a[] = {1,2};
    int b[] = {3,4};

    vector<int> nums1(a, a+2);
    vector<int> nums2(b, b+2);
    cout << findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}
