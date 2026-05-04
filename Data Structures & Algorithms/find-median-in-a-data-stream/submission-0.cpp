class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        nums.push_back(num);
    }
    
    double findMedian() {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n % 2 == 0){
            int a = double(nums[(n - 1) / 2]);
            int b = double(nums[((n -1) / 2) + 1]);
            cout << a << " " << b << " = " << (a + b) / 2.0 << endl;
            return (a + b) / 2.0;
        }
        else {
            return double(nums[n / 2]);
        }
    }
};
