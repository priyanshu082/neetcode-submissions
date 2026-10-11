class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        if (strs.empty()) return ans;
        int i=0;
        while(true){
            if (i >= strs[0].size()) return ans;
            char ch= strs[0][i];
            for(string x : strs){
                if (i >= x.size()) return ans;
                if(ch!=x[i]) return ans;
            }
            ans+=ch;
            i++;
        }
        return ans;
    }
};