//
// Created by Peng Qixiang on 2017/8/23.
//
// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0?
// Find all unique triplets in the array which gives the sum of zero.
// Input: S = [-1, 0, 1, 2, -1, -4],
// Output: [[-1, 0, 1],[-1, -1, 2]]


# include <iostream>
# include <vector>

using namespace std;

// using sorted array to optimise
// a = nums[0], search b and c between nums[1] --- nums[n]
// a = nums[1], search b and c between nums[2] --- nums[n]
// tc : o(n*n)
vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        int begin = i + 1;
        int end = nums.size() - 1;
        while (begin < end) {
            if (nums[begin] + nums[end] + nums[i] == 0) {
                vector<int> tmp;
                tmp.push_back(nums[i]);
                tmp.push_back(nums[begin]);
                tmp.push_back(nums[end]);
                res.push_back(tmp);
                begin++;
                end--;
                //erase same b and c
                while (begin < end && nums[begin] == tmp[1])
                    begin++;
                while (begin < end && nums[end] == tmp[2])
                    end--;
                continue;
            } else if (nums[begin] + nums[end] + nums[i] > 0) {
                end--;
                continue;
            } else {
                begin++;
                continue;
            }
        }
        // erase same a
        while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
    }
    return res;
}

int main() {
    vector<int> nums;
    nums.reserve(1);
    nums.push_back(-1);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(-1);
    nums.push_back(-4);
    vector<vector<int>> res = threeSum(nums);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i][0] << ' ' << res[i][1] << ' ' << res[i][2] << endl;
    }
}





