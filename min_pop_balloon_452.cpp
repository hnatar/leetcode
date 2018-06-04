class Solution {
public:
    inline bool arrow_pops(const pair<int,int> &b, int arrow) {
        return b.first<=arrow && arrow<=b.second;
    }
    int findMinArrowShots(vector<pair<int, int>>& points) {
        // Every balloon must be burst.
        //
        // Transform by ordering the balloons by their
        // ending x-coordinates, x-end.
        //
        // The first balloon should be popped, so it will take
        // atleast one arrow. Overall number of arrows can be minimized
        // by firing such that many other balloons are popped with it.
        //
        // Shooting an arrow at x = x1end will give the best chance
        // of hitting multiple balloons.
        //
        // This balloon has lowest x-end, so the arrow cannot
        // miss any balloon "before" it. *NOT* shooting at x1end will
        // miss another balloon specified by [x1end-eps, x1end+eps].
        // So, shoot at the end of the first balloon remaining.
        //
        // Once fired, one (or more) ballons are popped. If any remain,
        // apply argument recursively.
        
        
        // sort ballons by their ending x-coordinates
        sort(points.begin(), points.end(), [](const pair<int,int> &a, const pair<int,int> &b) {
                return a.second < b.second;
            });
        
        // count arrows
        int num_arrows = 0;
        for(auto balloon = points.begin(); balloon != points.end();) {
            // atleast one arrow for this balloon
            num_arrows += 1;
            int arrow = balloon->second;
            
            // account for as many ballons as possible with this arrow
            auto pop_balloon = balloon+1;
            while( pop_balloon != points.end() && arrow_pops( (*pop_balloon), arrow) ) {
                pop_balloon++;
            }
            
            // unpopped ballon or end of array
            balloon = pop_balloon;
        }

        return num_arrows;
    }
};