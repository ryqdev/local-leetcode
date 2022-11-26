#include<bits/stdc++.h>
#include "solution.cpp"
using namespace std;

int main(){
#ifndef ONLINE_JUDEG
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    getline(cin, input);
    TreeNode* root = s2t(input);

    Solution s;
    auto ans = s.invertTree(root);

    printAns(ans);
    return 0;
}


