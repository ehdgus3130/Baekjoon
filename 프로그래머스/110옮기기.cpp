#include <string>
#include <vector>

using namespace std;


string cacu(string s) {
    int cnt = 0;
    string st = "";

    for (char c : s) {
        st.push_back(c);


        if (st.size() >= 3) {
            int n = st.size();
            if (st[n - 3] == '1' && st[n - 2] == '1' && st[n - 1] == '0') {
                st.pop_back(); st.pop_back(); st.pop_back();
                cnt++;
            }
        }
    }

    string add = "";
    for (int i = 0; i < cnt; i++) add += "110";

    int pos = 0;
    for (int j = 0; j < st.size(); j++) if (st[j] == '0') pos = j + 1;

    st.insert(pos, add);
    return st;
}
vector<string> solution(vector<string> s) {
    vector<string> answer;
    for (string str : s) {
        answer.push_back(cacu(str));
    }

    return answer;
}