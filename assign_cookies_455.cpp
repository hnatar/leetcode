class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // sort the children by cookie demand
        std::sort( g.begin(), g.end() );
        // sort cookies by sizes
        std::sort( s.begin(), s.end() );


        int punks_satisfied = 0;

        // top tier parenting
        auto child = g.begin(), cookie = s.begin();
        for(; child!=g.end() && cookie!=s.end(); child++, cookie++) {
            while( *child > *cookie  && cookie != s.end() ) {
                cookie++;
            }
            if( cookie == s.end() ) break;
            punks_satisfied++;
        }

        return punks_satisfied;
    }
};