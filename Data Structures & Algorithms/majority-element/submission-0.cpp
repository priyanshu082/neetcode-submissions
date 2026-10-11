class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans;
        int cnt=0;
        for(int x : nums){
            if(cnt==0) ans=x;
            if(ans==x) cnt++;
            else cnt--;
        }
        return ans;
    }
};