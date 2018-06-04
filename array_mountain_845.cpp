class Solution {
public:
    int longestMountain(vector<int>& A) {
        // For each index i, store the length of the longest
        // increasing sequence which ends at i, and the length
        // of the longest decreasing sequence which starts at i.

        // If the index i is the peak of a mountain, the size
        // of the mountain can be determined from above. 

        // Have to ensure that both increasing and decreasing sides
        // are present (mountain has both "slopes").
        
        // set up the size in the constructor !!
        vector<int> longestSI( A.size() ), longestSD( A.size() );
        
        // Longest increasing sequence ending at i
        for(int i=0; i<A.size(); i++) {
            longestSI[i] = ( i>0 && A[i]>A[i-1] ) ? (longestSI[i-1]+1) : (1);
        }
        
        // Longest decreasing sequence starting at i
        for(int i=A.size()-1; i>=0; i--) {
            longestSD[i] = ( i<A.size()-1 && A[i+1]<A[i] ) ? (longestSD[i+1]+1) : (1);
        }
        
        // length of the longest mountain seen
        int best = 0;
        for(int i=0; i<A.size(); i++) {
            int cur = longestSI[i] + longestSD[i] - 1;
            // ensure mountain is not a slope and meets min. length
            if(longestSD[i]==1 || longestSI[i]==1 || cur<3) continue;
            best = max(best, cur);
        }
        return best;
    }
};