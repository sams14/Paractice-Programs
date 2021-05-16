// You are given  integers in sorted order. Also, you are given  queries. In each query, you will
// be given an integer and you have to tell whether that integer is present in the array. If so, 
// you have to tell at which index it is present and if it is not present, you have to tell the 
// index at which the smallest integer that is just greater than the given number is present.


// The first line of the input contains the number of integers . The next line contains  integers in 
// sorted order. The next line contains , the number of queries. Then  lines follow each containing 
// a single integer .

// Note: If the same number is present multiple times, you have to print the first index at which it occurs. Also, the input is such that you always have an answer for each query.


// For each query you have to print "Yes" (without the quotes) if the number is present and at which index(1-based) it is present separated by a space.
// If the number is not present you have to print "No" (without the quotes) followed by the index of the next smallest number just greater than that number.
// You have to output each query in a new line.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n, x, q, val;
    vector<int> v;
    cin>>n;
    for(int i=0; i<n; i++){  cin>>x;  v.push_back(x);  } 
    cin>>q;
    while(q>0){
        cin>>val;
        vector<int>::iterator low = lower_bound(v.begin(), v.end(), val);
        if (v[low - v.begin()] == val)
            cout << "Yes " << (low - v.begin()+1) << endl;
        else
            cout << "No " << (low - v.begin()+1) << endl;
        q--;
    }
    return 0;
}

// WHY TO USE lower_bound() instead of find() 
// --The lower_bound() method in C++ is used to return an iterator pointing to the first element 
//   in the range [first, last] which has a value not less than val. This means that the function
//   returns the index of the next smallest number just greater than or equal to that number.
// --Hence best to use in sorted arrays