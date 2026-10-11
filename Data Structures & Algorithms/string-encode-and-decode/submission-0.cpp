

class Solution {
public:
    
    string encode(vector<string>& strs) {
        string ans="";
        for(int i=0;i<strs.size();i++){
            int sz=strs[i].size();
            ans+=to_string(sz);
            ans+='#';
            ans+=strs[i];
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.size()){
            int len=0;

            while (i < s.size() && s[i] != '#') {
                len = len*10 + (s[i]-'0');
                i++;
            }

            i++;

            ans.push_back(s.substr(i, len));

            i+=len;
        }
        return ans;
    }
};
