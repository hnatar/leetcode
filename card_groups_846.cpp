class Solution {
public:
    bool form_card_group(vector<int> &hand, int W) {
        for(int i=0; i<hand.size(); i++) {
            if(hand[i] == -1) continue; // card group previous func. call
            else {
                vector<int> group;
                group.push_back(i);
                
                int index=0;
                while( group.size()<W && index<hand.size() ) {
                    if(index==i) {
                        index+=1;
                        continue;
                    }
                    
                    if( hand[index] == hand[group.back()]+1 ) {
                        group.push_back(index);
                    }
                    index += 1;
                }
                
                // check if group was formed
                if( group.size() == W ) {
                    for(auto &i: group) {
                        hand[i] = -1;
                    }
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        // entire group is -1, should not happen sanity check
        return false;
    }
    
    bool isNStraightHand(vector<int>& hand, int W) {
        // fail fast
        if( hand.size() % W ) {
            return false;
        }
        
        // sorting will not affect outcome
        std::sort(hand.begin(), hand.end());
        
        // there will be a lowest num. card which is not grouped
        // yet. take it and form new group, or fail.
        int total_iter = hand.size() / W;
        for(int iter=0; iter< total_iter; iter++) {
            bool r = form_card_group(hand, W);
            if(!r) return false;
        }
        return true;
    }
};