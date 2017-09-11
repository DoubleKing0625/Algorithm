//
// Created by Peng Qixiang on 2017/8/23.
//
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target.
// Return the sum of the three integers.
// You may assume that each input would have exactly one solution.
// Input: S = [-1, 2, 1, -4], target = 1
// Output: 2 (-1 + 2 + 1 = 2)


# include <iostream>
# include <vector>

using namespace std;

// using sorted array to optimise
// a = nums[0], search b and c between nums[1] --- nums[n]
// a = nums[1], search b and c between nums[2] --- nums[n]
// tc : o(n*n)

int threeSumClosest(vector<int> &nums, int target) {
    int sum;
    int res = nums[0] + nums[1] +nums[2]; // assign value randomly
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++) {
        int begin = i + 1;
        int end = nums.size() - 1;
        while (begin < end) {
            sum = nums[begin] + nums[end] + nums[i];
            if (abs(sum - target) <= abs(res - target)) {
                res = sum;
            }
            int noteBegin = nums[begin];
            int noteEnd = nums[end];
            //change index(begin and end) and erase same b and c
            if (sum <= target){
                begin++;
                while (begin < end && nums[begin] == noteBegin)
                    begin++;
            }
            else{
                end--;
                while (begin < end && nums[end] == noteEnd)
                    end--;
            }
        }
        // erase same a
        while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
    }
    return res;
}

int main(){
    vector<int> data = {1, 1, 1, 1};
    cout << threeSumClosest(data, 0) << endl;
    return 0;
}





