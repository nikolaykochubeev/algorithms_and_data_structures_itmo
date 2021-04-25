#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MAX = 1000000001;

void LIS(const vector<int>& input, int n){
    vector<int> d(n+1);
    vector<int> pos(n+1);
    vector<int> prev(n);
    int len = 0;
    pos[0] = -1;
    d[0] = -MAX;
    for(int i = 1; i < n+1; i++)
        d[i] = MAX;
    for(int i = 0; i < n; i++){
        int j = upper_bound(d.begin(), d.end(), input[i]) - d.begin();
        if(d[j - 1] < input[i] and input[i] < d[j]){
            d[j] = input[i];
            pos[j] = i;
            prev[i] = pos[j - 1];
            if (j > len)
                len = j;
        }
    }
    vector<int> output;
    int p = pos[len];
    while(p != -1){
        output.push_back(input[p]);
        p = prev[p];
    }
    reverse(output.begin(), output.end());
    cout << output.size() << '\n';
    for(int i : output)
        cout << i << " ";
}

int main() {
    int n ;
    cin >> n;
    vector<int> input(n);
    for(int i = 0; i < n; i++)
        cin >> input[i];
    LIS(input, n);
    return 0;
}