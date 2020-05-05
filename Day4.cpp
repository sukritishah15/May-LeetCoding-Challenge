class Solution {
public:
    string decToComplementedBin (int decNum){
        
        // complementedBin will hold the binary representation of the complement of decNum 
        string complementedBin;
        while(decNum > 0){
            
            // When decNum is converted to it's binary representation
            // last bit for the binary representation is found first and 
            // first bit is found last
            int bit = decNum % 2;
            
            // Since we have to find the complement of decNum
            // we flip all the bits 
            int complementedBit;
            if(bit==0)
                complementedBit = 1;
            else
                complementedBit = 0;
            
            decNum = decNum / 2;
            
            // After flipping the bit
            // we append it to the string complementedBin, created for holding
            // complement of decNum in binary representation
            complementedBin += (complementedBit + '0');
        }
        
        // Since, bits were stored in reverse order i.e. last bit first, 
        // and first bit last, we reverse the string complementedBin
        reverse(complementedBin.begin(), complementedBin.end());
        // Now complementedBin holds the complement of decNum in binary representation
        
        return complementedBin;
    }
    long long binToDec (string binNum){
        
        // dec will hold the equivalent decimal number for binary number - binNum
        long long dec = 0;
        
        // When we convert binary number to decimal number 
        // if the bit is 1 we add base(i.e. 2^position) to our result
        // where result will finally, be our equivalent decimal number
        long long base = 1;
        
        int len = binNum.length();
        for(int i=len-1; i>=0; i--){
            if(binNum[i]=='1')
                dec += base;
            base = base * 2;
        }
        
        // Now, dec contains decimal number equivalent to binary number - binNum
        return dec;
    }
    int findComplement(int num) {
        /*
            In order to find complement of a decimal number, we follow these steps -
                1. Convert to binary representation
                2. Flip the bits to obtain binary representation of the complement
                3. Convert complemented binary representation to decimal representation to get the answer
        */
        
        // Convert the decimal number to it's complemented binary number representation
        string s = decToComplementedBin(num);
        // Convert complemented binary number to it's equivalent decimal number
        long long res = binToDec(s);
        return res;
    }
};
