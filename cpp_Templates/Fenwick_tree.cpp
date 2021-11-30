class BIT {
private:
    vector<int> fen;
public:
    BIT(vector<int>& v) {
        for (int i=0;i<v.size();i++) {
            fen.push_back(v[i]);
        }
    }
    
    void update(int index, int val) {
        while (index <= 1e6+1e6+5) {
            if (fen[index]+val >= 0) fen[index] += val;
            else fen[index] = 0;
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

// vector<int> fen(1e6+5, 0)
// BIT bit(fen)
