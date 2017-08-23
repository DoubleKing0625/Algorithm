//
// Created by Peng Qixiang on 2017/8/10.
//
/*
// Given a string, find the length of the longest substring without repeating characters.
// Given "abcabcbb", the answer is "abc", which the length is 3.
// Given "bbbbb", the answer is "b", with the length of 1.
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

# include <cstdlib>
# include <iostream>
# include <unordered_set>
# include <unordered_map>

using namespace std;

// brute force
// tc : o(n*n*n)
bool allUnique(string s, int start, int end){
    unordered_set<char> subString;
    for(int i = start; i < end; i++){
        char tmp = s.at(i);
        if (subString.count(tmp)) return false;
        subString.insert(tmp);
    }
    return true;
}

int lengthOfLongestSubstring1(string s) {
    int size = s.size();
    int length = 0;
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j <= size; j++){// j is unreacheable
            if(allUnique(s, i, j)) length = (j - i) > length? (j - i): length;
        }
    }
    return length;
}

// slide window
// tc : o(n) if using hash-set or o(n*n)
int lengthOfLongestSubstring2(string s){
    int size = s.size();
    int length = 0, i =0 , j = 0;
    unordered_set<char> subString;
    while ( i < size && j < size ){
        if(!subString.count(s.at(j))){
            //char tmp = s.at(j++);
            subString.insert(s.at(j++));
            length = (j - i) > length ? (j - i) : length;
        }
        else{
            subString.erase(s.at(i++));// find the same char little by little
        }
    }
    return length;
}

// slide window2
//
int lengthOfLongestSubstring3(string s){
    int size = s.size();
    int length = 0, i = 0, j = 0;
    unordered_map<char, int> subString;
    while ( i < size && j < size ){
        if(!subString.count(s.at(j))){
            subString.insert(unordered_map<char, int>::value_type(s.at(j), j));
        }
        else{
            i = subString[s.at(j)] >= i ? subString[s.at(j)] + 1 : i;// find the same char directly
            subString[s.at(j)] = j; // update the newest position
        }
        j++;
        length = (j - i) > length ? (j - i) : length;
    }
    return length;
}

int main(){
    string s("tmmzuxt");

    //cout << lengthOfLongestSubstring1(s) << endl;
    //cout << lengthOfLongestSubstring2(s) << endl;
    cout << lengthOfLongestSubstring3(s) << endl;
    return 0;
}
