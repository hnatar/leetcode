class Solution {
public:
    vector<int> partitionLabels(string S) {
        // Given a string s, if its first character
        // does not appear further on into the string,
        // separate the character into its own block
        // of size 1.
        //
        // If it does appear, then all the characters
        // between the two occurences (atleast) belong
        // to its block. Last occurences for these chars
        // must also be in the same block. Extend until
        // end-of-string, or nothing outside the block.
        map<char, int> last_pos;
        vector<int> result;
        
        // last position for each character
        for(int i=S.size()-1; i>=0; i--) {
            char c = S[i];
            if( last_pos.find(c) == last_pos.end() ) {
                last_pos[c] = i;
            }
        }
        
        // find the lengths
        for(int i=0; i<S.size(); i++) {
            int start_index = i, end_index = last_pos[ S[i] ];
            for(int j=i; j<=end_index && j<S.size(); j++) {
                end_index = max(end_index, last_pos[ S[j] ]);
            }
            result.push_back( end_index-start_index+1 );
            i = end_index;
        }
        
        return result;
    }
};
