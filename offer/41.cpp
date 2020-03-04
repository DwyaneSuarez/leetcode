class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (data.empty()) {
            data.insert(num);
            mid = data.begin();
        } else {
            int n = data.size();
            data.insert(num);
            if (n & 1) {
                if (num < *mid)
                    --mid;
            } else {
                if (num >= *mid)
                    ++mid;
            }
        }
    }
    
    double findMedian() {
        int n = data.size();
        if (n & 1)
            return *mid;
        else {
            double ret = *mid;
            ++mid;
            ret = (ret + *mid) / 2;
            --mid;
            return ret;
        }
    }
private:
    multiset<int> data;
    multiset<int>::iterator mid;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */