class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int teams = 0;
        for(int k = 1; k < n-1; k++) {
            int leftSmaller = 0, leftGreater = 0, rightSmaller = 0, rightGreater = 0;

            for(int i = 0; i < k; i++) {
                if(rating[i] > rating[k]) leftGreater++;
                if(rating[i] < rating[k]) leftSmaller++;
            }

            for(int j = k+1; j < n; j++) {
                if(rating[j] > rating[k]) rightGreater++;
                if(rating[j] < rating[k]) rightSmaller++;
            }

            teams += (leftGreater * rightSmaller) + (leftSmaller * rightGreater);
        }

        return teams;
    }
};
/*
Approach : in order to get triplets which are strictly increasing and strictly decreasing we need to consider the middle element only and count remaining

#increasing:- search for smaller on left side till middle element and search for greater on right till end and finally multiply both get the no of total pairs

#decreasing:- search for larger on left and smaller on right from the middle and finally get no of pairs by multiplying both 

*/