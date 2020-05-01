// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int low = 1, high = n;
        while(low <= high){
            int mid = low + (high-low)/2;
            // if mid is a bad version, first bad version would occur before mid (first half) 
            // or mid itself would be the first bad version
            // if mid is not a bad version, first bad version would occur after mid (second half)
            if(isBadVersion(mid)){
                // if (mid-1) version is not bad, then mid is the first bad version    
                // else if (mid-1) is a bad version, then we will have to apply binary search 
                // to the first half in order to identify the first bad version before mid
                if(!isBadVersion(mid-1))
                    return mid;
                else
                    high = mid - 1;
            }
            else
                low = mid + 1;
        }
        return -1;
    }
};
