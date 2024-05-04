#include <iostream>
#include <queue>
#include <vector>
#include <stack>

struct ListNode {
    int val;
    ListNode *next;

    // constructer
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *node) : val(x), next(node) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // constructer
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    explicit TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

std::string s2s (const std::string& input) {
    return input.substr(1, (int)input.size() - 2);
}

std::vector<std::string> split(std::string s, const std::string& delimiter) {
    int pos;
    std::string token;
    std::vector<std::string> ans;
    while ((pos = (int)s.find(delimiter)) != std::string::npos) {
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

std::vector<int> s2vi(std::string input) {
    input = s2s(input);
    std::vector<std::string> split_s = split(input, ",");
    std::vector<int> arr;
    for (std::string s: split_s) {
        if (s == "null") {
            arr.push_back(-1);
        } else {
            arr.push_back(stoi(s));
        }
    }
    return arr;
}

int s2i(const std::string& input) {
    return stoi(input);
}

ListNode* s2l (const std::string& input) {
    std::vector<int> tmp = s2vi(input);
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    for (int i: tmp) {
        ListNode* t = new ListNode(i);
        cur -> next = t;
        cur = cur -> next;
    }
    return dummy -> next;
}

TreeNode* buildTree(TreeNode* root, std::vector<int>&tmp, int pos) {
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

TreeNode* s2t(const std::string& input) {
    std::vector<int> tmp = s2vi(input);
    TreeNode* root = nullptr;
    return buildTree(root, tmp, 0);
}

template <typename T>
void printAns(T t) {
    std::cout << t << std::endl;
}

void printAns(const std::vector<int>& ans){
    for (int i: ans) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void printAns(ListNode* head) {
    while (head) {
        std::cout << head -> val << " ";
        head = head -> next;
    }
}

void printTreeVertically(const std::string& prefix, TreeNode* root, bool isLeft) {
    if (root != nullptr) {
        std::cout << prefix;
        std::cout << (isLeft ? "\\--" : "|--");
        std::cout << root -> val << std::endl;
        printTreeVertically(prefix + (isLeft ? "   " : "|  "),root -> right, false);
        printTreeVertically(prefix + (isLeft ? "   " : "|  "),root -> left, true);
    }
}

void printTreeHorizontally (TreeNode* root) {
    // TODO: unfinished
    std::vector<std::vector<int> > tmp;
    std::queue<TreeNode*> q;
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
            std::cout << tmp[i][j] << std::string(interval, ' ');
        }
        interval = (interval - tmp[i][0] / 10 + 1) / 2;
        std::cout << "\n";
    }
}

void printAns(TreeNode* root) {
//    printTreeHorizontally(root);
    printTreeVertically("", root,true);
}

