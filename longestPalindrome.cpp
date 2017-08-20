//
// Created by Peng Qixiang on 2017/8/11.
//
/*
// Given a string s, find the longest palindromic substring in s.
// You may assume that the maximum length of s is 1000.
// Input: "babad", Output: "bab" or "aba"
// Input: "cbbd", Output: "bb"
*/

# include <cstdlib>
# include <iostream>
# include <vector>

using namespace std;

// reverse input then get the longest common substring（using dynamic）and check if palindrome
// tc : o(n*n)， sc : o(n*n)
// transform function: res[i][j] = res[i-1][j-1] + 1   if s[i] = sR[j]
//                     0                   otherwise
string longestPalindrome1(string s) {
    string sReverse(s.rbegin(), s.rend());
    int size = s.size();
    // size_s * size_sR saving res[m][n]
    vector<vector<int>> res(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        if (s[0] == sReverse[i])
            res[0][i] = 1;
        if (sReverse[0] == s[i])
            res[i][0] = 1;
    }
    for (int i = 1; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (s[i] == sReverse[j])
                res[i][j] = res[i - 1][j - 1] + 1;
        }
    }
    int longest = 0, index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if ((longest < res[i][j]) &&
                (i - res[i][j] + 2 + j == size)) { //check if palindrom(check if it's the same substring)
                longest = res[i][j];
                index = i;
            }
        }
    }
    return s.substr(index - longest + 1, longest);
}

// using dynamic directly
// tc : o(n*n)， sc : o(n*n)
// p(i,j) = true   if Si...Sj is palindrome
//          false  otherwise
// transform function:  res[i][j] = res[i+1][j-1] if s[i]=s[j]
//                      res[i][i+1] = (s[i] == s[i+1])
//                      res[i][j] = true

string longestPalindrome2(string s) {
    int size = s.size();
    vector<vector<int>> res(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        res[i][i] = 1;
        int j = i + 1;
        while(s[i] == s[j]){
            res[i][j++] = 1;
        }
    }
    for (int i = 1; i < size; i++) {
        for (int j = i; j < size; j++) {
            int begin = i - 1, end = j + 1;
            if (res[begin][end])
                continue; // speed up
            else {
                while (begin >= 0 && end < size && s[begin] == s[end]) {
                    res[begin][end] = res[begin + 1][end - 1];
                    begin--;
                    end++;
                }
            }
        }
    }
    int longest = 0, index = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i; j < size; j++) {
            if (res[i][j]) {
                if (longest < j - i + 1) {
                    longest = j - i + 1;
                    index = i;
                }
            }
        }
    }
    return s.substr(index,longest);
}

// expand around center，2n-1 centers, n singe center, n-1 double center
// tc : o(n*n) , sc : o(1)
/**
 *
 * @param s : original string
 * @param left : left index of test center
 * @param right : right index of test center
 * @return  : length of palindrome centered at l and r
 */
int expandAroundCenter(string s, int left, int right) {
    int l = left, r = right;
    if(r >= s.size())
        return 1;
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
        l--;
        r++;
    }
    return r - l - 1; // anohter operation, so we need (r-1) - (l+1) +1
}

string longestPalindrome3(string s){
    int longest = 0, index = 0;
    for (int i = 0; i < s.size(); i++) {
        int length1 = expandAroundCenter(s, i, i);
        int length2 = expandAroundCenter(s, i, i + 1);
        int length = length1 > length2 ? length1 : length2;
        if (length > longest) {
            longest = length;
            index = i - (length - 1) / 2;
        }
    }
    cout << longest << ' ' << index << endl;
    return s.substr(index, longest);
}

int main() {

    cout << longestPalindrome3("bab") << endl;

}
