#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int dp[101][1001][1001];
void knapsack(int n , int w , int v)
int main()
{
    memset(dp , 0 , sizeof(dp));
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
}