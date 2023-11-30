#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
int dp[101], cut[101];
int main()
{
    memset(dp , 0 , sizeof(dp));
    memset(cut, 0 , sizeof(cut));
    vector<int> price;
    int length, temp;
    cin >> length;
    while(cin >> temp)
        price.push_back(temp);
    for(int i = 1 ; i <= length ; i++){
        int Max = INT16_MIN , Cut = 0;
        for(int j = 0 ; j < i ; j++){
            if(dp[i-j] + price[j] > Max){
                Max = dp[i-j-1] + price[j];
                Cut = j;
            }
        }
        dp[i] = Max;
        cut[i] = Cut + 1;
    }
    cout << dp[length] << endl;
    vector<int> cut_sequence;
    int count = 0;
    temp = length;
    while(cut[temp] != 0){
        count++;
        cut_sequence.push_back(cut[temp]);
        temp -= cut[temp];
    }
    cout << count << endl << length << "=";
    for(auto a : cut_sequence)
        cout << a << " ";
}