class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();

        int i = 0, j = n-1;
        int refill = 0;
        int a = capacityA, b = capacityB;
        while(i <= j) {
            if(i == j) {
                if(b > a) {
                    if(plants[j] > b) {
                        b = capacityB;
                        refill++;
                        b -= plants[j];
                    }
                    else {
                        b -= plants[j];
                    }
                }
                else {
                    if(plants[i] > a) {
                        a = capacityA;
                        refill++;
                        a -= plants[i];
                    }
                    else {
                        a -= plants[i];
                    }
                }
                break;
            }

            if(plants[i] > a) {
                refill++;
                a = capacityA;
                a -= plants[i];
            }
            else {
                a -= plants[i];
            }

            if(plants[j] > b) {
                refill++;
                b = capacityB;
                b -= plants[j];
            }
            else {
                b -= plants[j];
            }

            i++;
            j--;
        }

        return refill;
    }
};