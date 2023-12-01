#include <iostream>
#include <vector>
using namespace std;
bool selected[101][1001][1001] = {false};
int knapsackMaxValue(vector<int>& weights, vector<int>& volumes, vector<int>& values, int W, int V) {
    int n = weights.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(W + 1, vector<int>(V + 1, 0)));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            for (int k = 0; k <= V; ++k) {
                dp[i][j][k] = dp[i - 1][j][k];
                selected[i][j][k] = selected[i-1][j][k];
                if (j >= weights[i - 1] && k >= volumes[i - 1]) {
                    if(dp[i][j][k] < dp[i - 1][j - weights[i - 1]][k - volumes[i - 1]] + values[i - 1]){
                        dp[i][j][k] = dp[i - 1][j - weights[i - 1]][k - volumes[i - 1]] + values[i - 1];
                        selected[i][j][k] = true;
                    }
                }
            }
        }
    }

    return dp[n][W][V];
}

int main() {
    int items, weight, volume, temp;
    vector<int> value , weights , volumes;
    cin >> items >> weight >> volume;
    for(int i = 0 ; i < items ; i++){
        cin >> temp;
        value.push_back(temp);
    }
    for(int i = 0 ; i < items ; i++){
        cin >> temp;
        weights.push_back(temp);
    }
    for(int i = 0 ; i < items ; i++){
        cin >> temp;
        volumes.push_back(temp);
    }
    int result = knapsackMaxValue(weights, volumes, value, weight, volume);

    cout << result << endl;
    int w = weight , v = volume;
    vector<int> selected_ans;
    for(int i = 1 ; i <= items ; i++ ){
        if(selected[i][w][v]){
            selected_ans.push_back(i);
            w -= weights[i-1];
            v -= volumes[i-1];
        }
        if(w < 0 || v < 0)
            break;
    }
    cout << selected_ans.size() << endl;
    cout << "(";
    for(int i = 0 ; i < selected_ans.size() ; i++){
        if(i+1 == selected_ans.size())
            cout << selected_ans[i] << ")" << endl;
        else
            cout << selected_ans[i] << ",";
    }
    return 0;
}
