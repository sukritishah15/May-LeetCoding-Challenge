class Solution {
public:
    int firstUniqChar(string s) {
        // Create a map to store the frequency of characters of the string
        map<char,int> mp;
        int n = s.length();
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        // Traverse the string once, and 
        // if the frequency of any character is found to be 1,
        // return it's index
        // The first time a character with frequency 1 would be found,
        // it's index would be returned as answer
        for(int i=0; i<n; i++){
            if(mp[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};
