class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int lenr = ransomNote.length();
        int lenm = magazine.length();
        
        // We create 2 maps - first is freq1 which indicates frequency of characters in ransomNote
        // and second is freq2 which indicates frequency of characters in magazine
        map<char,int> freq1, freq2;
        for(int i=0; i<lenr; i++){
            freq1[ransomNote[i]]++;
        }
        for(int i=0; i<lenm; i++){
            freq2[magazine[i]]++;
        }
        
        // In order to construct ransomNote from magazines, the frequency of each character 
        // in magazine should be greater than or equal to 
        // the frequency of the same character in ransomNote
        int flag=0;
        for(auto x:freq1){
            if(freq2.find(x.first)==freq2.end() || freq2[x.first]<x.second){
                flag=1;
                break;
            }
        }
        
        if(flag)
            return false;
        else
            return true;
    }
};
