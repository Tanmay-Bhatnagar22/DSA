class SmallestInfiniteSet {
    int cur;
    set<int> added;

public:
    SmallestInfiniteSet() {
        cur = 1;
    }

    int popSmallest() {
        if (!added.empty()) {
            int x = *added.begin();
            added.erase(added.begin());
            return x;
        }
        return cur++;
    }

    void addBack(int num) {
        if (num < cur) {
            added.insert(num);
        }
    }
};