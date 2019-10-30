class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        listLen = 0; 
    }
    
    void addNum(int num) {
        if (m.count(num)) {
            m[num]++;
        }
        listLen++;
    }
    
    double findMedian() {
        int index = 0;
        map<int, int> iterator::pre = map.begin();
        for (auto &it : m) {
            index += it->second;
            if (index == listLen / 2) {
                if (listLen % 2 == 0 && it->second == 1) {
                    return (it->first + pre->first) / 2.0;
                } else {
                    return it->first;
                }
            }
            pre = it;
        }
    }
private:
    int listLen;
    map<int, int> m;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */