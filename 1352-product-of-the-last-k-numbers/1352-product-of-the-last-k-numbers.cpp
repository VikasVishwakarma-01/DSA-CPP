class ProductOfNumbers {
public:
    vector<int> v;
    ProductOfNumbers() {}
    
    void add(int num) {
       v.push_back(num); 
    }
    
    int getProduct(int k) {
        int p = 1;
        int n = v.size();
        int t = 0;
        for(int i = n-1; i >= 0; i--) {
            if(t == k) return p;
            p *= v[i];
            t++;
        }

        return p;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */