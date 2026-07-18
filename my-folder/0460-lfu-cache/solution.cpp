class LFUCache {
    struct Node {
        int key, value, freq;
        Node(int k, int v, int f) : key(k), value(v), freq(f) {}
    };

    int capacity;
    int minFreq;
    unordered_map<int, list<Node>> freqList;
    unordered_map<int, list<Node>::iterator> keyIter;

public:
    LFUCache(int capacity) : capacity(capacity), minFreq(0) {}

    int get(int key) {
        auto it = keyIter.find(key);
        if (it == keyIter.end()) return -1;

        auto nodeIt = it->second;
        int val = nodeIt->value;
        touch(nodeIt);
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        auto it = keyIter.find(key);
        if (it != keyIter.end()) {
            it->second->value = value;
            touch(it->second);
            return;
        }

        if ((int)keyIter.size() == capacity) {
            auto &lst = freqList[minFreq];
            int evictKey = lst.back().key;
            lst.pop_back();
            if (lst.empty()) freqList.erase(minFreq);
            keyIter.erase(evictKey);
        }

        freqList[1].push_front(Node(key, value, 1));
        keyIter[key] = freqList[1].begin();
        minFreq = 1;
    }

private:
    void touch(list<Node>::iterator nodeIt) {
        int freq = nodeIt->freq;
        int key = nodeIt->key;
        int value = nodeIt->value;
        freqList[freq].erase(nodeIt);
        if (freqList[freq].empty()) {
            freqList.erase(freq);
            if (minFreq == freq) minFreq++;
        }
        freqList[freq + 1].push_front(Node(key, value, freq + 1));
        keyIter[key] = freqList[freq + 1].begin();
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
