//
// Created by Peng Qixiang on 2017/8/10.
//
/*
 // You are given two non-empty linked lists representing two non-negative integers
 // The digits are stored in reverse order and each of their nodes contain a single digit.
 // Add the two numbers and return it as a linked list.
 // You may assume the two numbers do not contain any leading zero, except the number 0 itself.
 // (2 -> 4 -> 3) + (5 -> 6 -> 4) = (7 -> 0 -> 8)
*/

# include <cstdlib>
# include <iostream>
# include <list>

using namespace std;

// tc: o(n) ; sc: o(1)
list<int> add_two_numbers(list<int>& l1, list<int>& l2) {
    list<int> res;
    if (l1.empty())
        return l2;
    if (l2.empty())
        return l1;
    int carry = 0;
    list<int>::iterator it1 = l1.begin();
    list<int>::iterator it2 = l2.begin();
    while((it1 != l1.end()) || (it2 != l2.end())){
        int x = (it1 != l1.end())? *it1 : 0;
        int y = (it2 != l2.end())? *it2 : 0;
        int sum = x + y + carry;
        res.push_back(sum % 10);
        carry = sum / 10;
        //if reaching end, maintaining end position
        if (it1 != l1.end()) it1++;
        if (it2 != l2.end()) it2++;
    }
    if(carry > 0)
        res.push_back(carry);
    return res;
}


int main(){
    list<int> l1;
    l1.push_back(2);
    l1.push_back(4);
    l1.push_back(3);
    
    list<int> l2;
    l2.push_back(5);
    l2.push_back(6);
    l2.push_back(4);
    
    list<int> res = add_two_numbers(l1, l2);
    
    for(list<int>::iterator it = res.begin(); it != res.end(); it++)
        cout << *it << endl;
    return 0;
}
