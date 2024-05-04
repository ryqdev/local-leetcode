#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

string s2s (const string& input) {
    return input.substr(1, (int)input.size() - 2);
}

vector<string> split(string s, const string& delimiter) {
    int pos;
    string token;
    vector<string> ans;
    while ((pos = (int)s.find(delimiter)) != string::npos) {
        if (pos == 0) {
            s.erase(0, pos + delimiter.length());
            continue;
        }
        token = s.substr(0, pos);
        ans.push_back(token);
        s.erase(0, pos + delimiter.length());
    }
    ans.push_back(s);
    return ans;
}

vector<int> s2vi(string input) {
    input = s2s(input);
    vector<string> split_s = split(input, ",");
    vector<int> arr;
    for (string s: split_s) {
        if (s == "null") {
            arr.push_back(-1);
        } else {
            arr.push_back(stoi(s));
        }
    }
    return arr;
}

int s2i(const string& input) {
    return stoi(input);
}

ListNode* s2l (const string& input) {
    vector<int> tmp = s2vi(input);
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    for (int i: tmp) {
        ListNode* t = new ListNode(i);
        cur -> next = t;
        cur = cur -> next;
    }
    return dummy -> next;
}

TreeNode* buildTree(TreeNode* root, vector<int>&tmp, int pos) {
    if (pos >= tmp.size()) {
        return nullptr;
    }
    if (tmp[pos] == -1) {
        return nullptr;
    }
    root = new TreeNode(tmp[pos]);
    root -> left = buildTree(root -> left, tmp, 2 * pos + 1);
    root -> right = buildTree(root -> right, tmp, 2 * pos + 2);
    return root;
}

TreeNode* s2t(const string& input) {
    vector<int> tmp = s2vi(input);
    TreeNode* root = nullptr;
    return buildTree(root, tmp, 0);
}

template <typename T>
void printAns(T t) {
    cout << t << endl;
}

void printAns(const vector<int>& ans){
    for (int i: ans) {
        cout << i << " ";
    }
    cout << endl;
}

void printAns(ListNode* head) {
    while (head) {
        cout << head -> val << " ";
        head = head -> next;
    }
}

void printTreeVertically(const string& prefix, TreeNode* root, bool isLeft) {
    if (root != nullptr) {
        cout << prefix;
        cout << (isLeft ? "\\--" : "|--");
        cout << root -> val << endl;
        printTreeVertically(prefix + (isLeft ? "   " : "|  "),root -> right, false);
        printTreeVertically(prefix + (isLeft ? "   " : "|  "),root -> left, true);
    }
}

void printTreeHorizontally (TreeNode* root) {
    // TODO: unfinished
    vector<vector<int> > tmp;
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while(!q.empty()) {
        int Qsize = q.size();
        tmp.push_back({});
        while(Qsize--) {
            TreeNode* cur = q.front();
            q.pop();
            if(cur -> val == -1) {
                continue;
            }
            tmp[level].push_back(cur -> val);
            if (cur -> left) {
                q.push(cur -> left);
            }
            if (cur -> right) {
                q.push(cur -> right);
            }
        }
        level++;
    }
    int n = tmp.size();
    int interval = 1;
    for (int i = 0; i < n - 1; ++i) {
        interval = 2 * interval + (tmp[i][0] / 10 + 1);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < tmp[i].size(); ++j) {
            cout << tmp[i][j] << string(interval, ' ');
        }
        interval = (interval - tmp[i][0] / 10 + 1) / 2;
        cout << "\n";
    }
}

void printAns(TreeNode* root) {
//    printTreeHorizontally(root);
    printTreeVertically("", root,true);
}

