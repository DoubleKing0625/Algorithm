//
// Created by Peng Qixiang on 2017/8/9.
//
/*
 // Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 // You may assume that each input would have exactly one solution, and you may not use the same element twice.
 // given a vector A [1,2,3,4,5] and a target 6
 // return a vector containing index [0,5] caz A[0] + A[5] = 6(target)
*/

# include <cstdlib>
# include <iostream>
# include <vector>
# include <unordered_map>
# include <map>

using namespace std;

// brute force
// tc: o(n*n) ; sc: o(1)
vector<int> twosum1(vector<int>& nums, int target) {
    vector<int> res;
    try {
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    return res;
                }
            }
        }
        exception e;
        throw e;
    }
    catch (exception e){
        cout << "Wrong" << endl;
    }
}

//two pass hash-map;
// tc: o(n) ; sc: o(n)
// if using usual map tc : o(nlog2n)
vector<int> twosum2(vector<int>& nums, int target){
    vector<int> res;
    unordered_map<int, int> map;
    int diff;
    for(int i = 0; i < nums.size(); i++)
        map.insert(unordered_map<int, int>::value_type(nums[i],i));
    try {
        for (int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];
            if (map.count(diff) && (map[diff] != i)) { // avoiding a[2] + a[2] = target
                res.push_back(i);
                res.push_back(map[diff]);
                return res;
            }
        }
        exception e;
        throw e;
    }
    catch(exception e){
        cout << "Wrong" << endl;
    }
}

// one pass hash-map
// tc and sc same as previous one
vector<int> twosum3(vector<int>& nums, int target){
    vector<int> res;
    unordered_map<int, int> map;
    int diff;
    try{
        for(int i = 0; i < nums.size(); i++){
            diff = target - nums[i];
            if (map.count(diff) && (map[diff] != i)) { // avoiding a[2] + a[2] = target
                res.push_back(i);
                res.push_back(map[diff]);
                return res;
            }
            map.insert(unordered_map<int, int>::value_type(nums[i],i));
        }
        exception e;
        throw e;
    }
    catch(exception e){
        cout << "Wrong" << endl;
    }
}

int main(){
    int a[] = {1,2,5,6,8};
    vector<int> test(a, a+8);
    vector<int> res1 = twosum1(test, 9);
    for(int i = 0; i < res1.size(); i++){
        cout << res1[i] << endl;
    }
    vector<int> res2 = twosum2(test, 9);
    for(int i = 0; i < res2.size(); i++){
        cout << res2[i] << endl;
    }
    vector<int> res3 = twosum3(test, 9);
    for(int i = 0; i < res3.size(); i++){
        cout << res3[i] << endl;
    }
    return 0;
}
