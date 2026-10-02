class MyHashSet {
    unordered_set<int> set;
public:
    MyHashSet() {
        
    }
    
    void add(int key) {
        set.insert(key);
    }
    
    void remove(int key) {
        set.erase(key);
    }
    
    bool contains(int key) {
        return set.count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */