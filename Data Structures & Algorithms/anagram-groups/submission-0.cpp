class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>,vector<string>> mpp;
        
        for(string x :strs){
            vector<int> key(26,0);
            for(char ch : x){
                key[ch-'a']++;
            }
            mpp[key].push_back(x);
        }

        for (auto x : mpp){
            ans.push_back(x.second);
        }
        return ans;
    }
};
