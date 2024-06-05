/*
Implement the RandomizedSet class:

RandomizedSet() Initializes the RandomizedSet object.
bool insert(int val) Inserts an item val into the set if not present. Returns true if the item was not present, false otherwise.
bool remove(int val) Removes an item val from the set if present. Returns true if the item was present, false otherwise.
int getRandom() Returns a random element from the current set of elements (it's guaranteed that at least one element exists when this method is called). 
Each element must have the same probability of being returned.
You must implement the functions of the class such that each function works in average O(1) time complexity.
*/

class RandomizedSet {
    unordered_map<int, int> m; // {val, index in v}
    vector<int> v;

public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (m.find(val) == m.end()) { // does not already exist
            v.push_back(val);
            m[val] = v.size() - 1; // save as index where that val exists in v
            return true;
        }

        return false;
    }
    
    bool remove(int val) {
        if (m.find(val) != m.end()) { // already exists
            // basically swapping val with whatever is at the back of v, and updating the map accordingly

            auto it = m.find(val);
            v[it->second] = v.back();
            v.pop_back();
            m[v[it->second]] = it->second;
            m.erase(val);

            return true;
        }

        return false;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
