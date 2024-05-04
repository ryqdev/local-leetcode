#include<iostream>
#include "solution.cpp"

int main(){
#ifndef ONLINE_JUDEG
    freopen("./input.txt", "r", stdin);
    freopen("./output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string input;
    getline(cin, input);
    vector<int> arr = s2vi(input);

    Solution s;
    auto ans = s.largestRectangleArea(arr);

    printAns(ans);
    return 0;
}


