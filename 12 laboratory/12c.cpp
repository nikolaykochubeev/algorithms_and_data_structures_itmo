#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
void lcs(int s1, int s2, string str1, string str2, vector<int>& lastMatrixStr)
{
    vector<vector<int>> k(2, vector<int>(s2 + 1));
    for (int j = 0; j <= s2; j++)
        k[1][j] = 0;
    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j <= s2; j++)
        {
            k[0][j] = k[1][j];
        }
        for (int j = 1; j <= s2; j++)
        {
            if (str1[i] == str2[j - 1])
            {
                k[1][j] = k[0][j - 1] + 1;
            }
            else
            {
                k[1][j] = max(k[1][j - 1], k[0][j]);
            }
        }
    }
    for (int j = 0; j <= s2; j++)
    {
        lastMatrixStr[j] = k[1][j];
    }
}

void hirsh(int s1, int s2, string str1, string str2)
{
    if (s2 == 0)
    {
        return;
    }

    if (s1 == 1)
    {
        int f = str2.find_first_of(str1[0]);
        if (f != string::npos){
            cout << str1[0];
        }
        return;
    }
    vector<int> l1(s2 + 1);
    vector<int> l2(s2 + 1);
    int middle = s1 / 2;
    lcs(middle, s2, str1.substr(0, middle), str2, l1);
    string str1_2 = str1;
    string str2_2 = str2;
    reverse(str1_2.begin(), str1_2.end());
    reverse(str2_2.begin(), str2_2.end());
    lcs(middle + 1, s2, str1_2.substr(0, s1 - middle), str2_2, l2);
    int max_v = l2[0];
    int maxJ = 0;
    for (int j = 0; j <= s2; j++)
    {
        if (l1[j] + l2[s2 - j] > max_v)
        {
            max_v = l1[j] + l2[s2 - j];
            maxJ = j;
        }
    }
    if (!middle)
    {
        middle++;
    }
    if (l1[s2] > max_v)
    {
        maxJ = s2;
    }
    hirsh(middle, maxJ, str1.substr(0, middle), str2.substr(0, maxJ));
    hirsh(s1 - middle, s2 - maxJ, str1.substr(middle, s1), str2.substr(maxJ, s2));
}
int main(){
    string str1, str2;
    cin >> str1 >> str2;
    hirsh(str1.length(), str2.length(), str1, str2);
    return 0;
}