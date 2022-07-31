class BIT {
private:
    vector<int> fen;
public:
    BIT(int n) {
        fen.assign(n+1, 0);
    }
    
    void update(int index, int val) {
        while (index <= 1e6+1e6+5) {
            fen[index] += val;
            index += (index & (-index));
        }
    }

    int sum(int r) {
        int s = 0;
        while (r > 0) {
            s += fen[r];
            r -= (r & (-r));
        }
        return s;
    }

    int sumRange(int l, int r) {
        return sum(r) - sum(l-1);
    }

    int fen_lower_bound(int s) {
        int i, low = 0, index = 0;
        for (i=19;i>=0;i--) {
            if (fen[index + (1 << i)] + low < s) {
                index += (1 << i);
                low += fen[index];
            } 
        }
        return index+1;
    }
};

// vector<int> nums;
// BIT *bit = new BIT(n);
// for (i=0;i<n;i++) bit->update(i+1, nums[i]);

