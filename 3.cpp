#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
vector<int> selected;
void swap(int &a,int &b){
    int temp = a;
    a = b;
    b = temp;
}
void select(vector<int> start , vector<int> end, int size){
    vector<int> ans(size,0);
    for(int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < i ; j++){
            if(end[j] < start[i] && ans[i] < ans[j]){
                ans[i] = ans[j];
            }
        }
        ans[i]++;
    }
    int max_index = max_element(ans.begin(),ans.end()) - ans.begin();
    selected.push_back(max_index+1);
    for(int i = max_index ; i >= 0 ; i--){
       if(end[i] <= start[max_index] && ans[i] == ans[max_index] - 1){
            selected.push_back(i+1);
            max_index = i;
       }
    }
    cout << *max_element(ans.begin(),ans.end()) << endl;
    for(int i = selected.size() - 1 ; i >= 0 ; i--)
        cout << selected[i] << " ";
}
int main()
{
    int n;
    cin >> n;
    vector<int> start_time,end_time;
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin >> temp;
        start_time.push_back(temp);
    }
    for(int i = 0 ; i < n ; i++){
        int temp;
        cin >> temp;
        end_time.push_back(temp);
    }
    select(start_time,end_time,n);

}