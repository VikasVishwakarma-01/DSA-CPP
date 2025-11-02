class SeatManager {
public:
    set<int> total;
    SeatManager(int n) {
        for(int i = 1; i <= n; i++) 
            total.insert(i);
    }
    
    int reserve() {
        int x = *(total.begin());
        total.erase(total.begin());
        return x;
    }
    
    void unreserve(int seatNumber) {
        total.insert(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */