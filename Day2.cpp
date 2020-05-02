class Solution {
public:
    int numJewelsInStones(string J, string S) {
        map<char,int> mp;
        int j = J.length();
        int s = S.length();
        
        // We add all the characters representing jewels in the map
        // Set their frequency/occurrence as 0
        for(int i=0; i<j; i++)
            mp[J[i]]=0;
        
        // If a stone is a jewel, then that character would be there in the map
        // So we increment the frequency/occurrence for that stone which is a jewel also
        for(int i=0; i<s; i++){
            if(mp.find(S[i]) != mp.end()){
                mp[S[i]]++;
            }
        }
        
        // We sum the frequencies of all the stones that are jewels also to get the final result
        int res = 0;
        for(auto x:mp){
            res+=x.second;
        }
        return res;
    }
};
