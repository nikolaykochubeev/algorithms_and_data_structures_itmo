#include <fstream>
#include <vector>
using namespace std;

vector<int> get_prefix(string str){
    int n = (int)str.size();
    vector<int> p(n, 0);
    for (int i = 1; i < n; i++){
        int k = p[i - 1];   
        while (k > 0 & str[i] != str[k])
            k = p[k - 1];
        if (str[i] == str[k])
            k++;
        p[i] = k;
    }
    return p;
}

vector<int> kmp(const string& p, const string& t){
    int n = (int)t.size();
    int m = (int)p.size();
    vector<int> answer;
    vector<int> prefix = get_prefix(p + "#" + t);
    for (int i = 0; i < n; i++)
        if (prefix[m + i + 1] == m)
            answer.push_back(i - m + 2);
    return answer;
}

int main(){
    ifstream fin("search2.in");
    ofstream fout("search2.out");
    string p, t;
    fin >> p >> t;
    vector<int> answer = kmp(p, t);
    fout << answer.size() << endl;
    for (int i: answer)
        fout << i << ' ';
    return 0;
}