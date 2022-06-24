class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int curpos,curneg,maxx;
        curpos = max(nums[0],0);
        curneg = min(nums[0],0);
        maxx = nums[0];
        for(int i = 1; i<nums.size();i++)
        {
            int temp = curpos;
            curpos = max({0,nums[i],curpos*nums[i],curneg*nums[i]});
            curneg = min({0,nums[i],temp*nums[i],curneg*nums[i]});
            maxx = max({maxx,curpos,curneg});
        }
        return maxx;
    }
};