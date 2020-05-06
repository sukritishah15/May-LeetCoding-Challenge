class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        // mp is a map that stores the frequency of every element of array
        map<int,int> mp;
        int n = nums.size();
        for(int i=0; i<n; i++)
            mp[nums[i]]++;
        
        // if frequency of an element is greater than floor(n/2),
        // return that element
        for(auto x:mp){
            if(x.second>n/2)
                return x.first;
        }
        
        return -1;
    }
};
