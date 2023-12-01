#include <iostream>
#include <deque>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
map<int , string> ans;
struct node
{
    int value;
    struct node* left;
    struct node* right;
    node() {
        value = 0;
        left = nullptr;
        right = nullptr;
    }
    node(int v) {
        value = v;
        left = nullptr;
        right = nullptr;
    }
    node(int v, struct node* l, struct node* r) {
        value = v;
        left = l;
        right = r;
    }
};
bool cmp(node* a, node* b) {
    return a->value < b->value;
}
void printcode(node* parent, string toprint) {
    if (parent->left == nullptr || parent->right == nullptr) {
        cout << parent->value << "'s code is " << toprint << " " << endl;
        ans[parent->value] = toprint;
        return;
    }
    if (parent->left != nullptr)
        printcode(parent->left, toprint + "0");
    if (parent->right != nullptr)
        printcode(parent->right, toprint + "1");

}
int main()
{
    int n;
    cin >> n;
    deque<node*> frquence;
    vector<int> order;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        frquence.push_back(new node(temp));
        order.push_back(temp);
    }
    sort(frquence.begin(), frquence.end(), cmp);
    while(frquence.size() != 1){
        node* l = frquence.front();
        frquence.pop_front();
        node* r = frquence.front();
        frquence.pop_front();
        node* parent = new node(l->value + r->value, l, r);
        frquence.push_back(parent);
        sort(frquence.begin(), frquence.end(), cmp);
    }
    printcode(frquence.front(), "");
    for(int i = 0 ; i < n ; i++){
        if(ans.find(order[i]) != ans.end()){
            cout << ans[order[i]] << " ";
        }
        else
            return -1;
    }
}