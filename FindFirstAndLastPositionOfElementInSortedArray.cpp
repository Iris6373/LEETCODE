class Solution {
public:
    vector<int> searchRange(vector<int>& v, int t) {
        vector<int> ans;
        if (v.size() == 0) return {-1,-1};
        // Search for the left most 't' by modified binary search
        // If mid element is t, we move towards left, inorder to find the left most one
        int i, l=0, h=v.size()-1, m=0, a=-1;
        while (l <= h) {
            m = l + (h-l)/2;
            if (v[m] == t) {
                a = m;
                h = m-1;    
            }
            else if (v[m] < t) l = m+1;
            else h = m-1;
        }
        
        // If even 1 instance of t is not found, then we can return {-1,-1}
        if (a != -1) ans.push_back(a);
        else return {-1,-1};
        
        // Search for the right most 't' by modified binary search
        // If mid element is t, we move towards rightt, inorder to find the right most one
        l=0, h=v.size()-1, m=0, a=-1;
        while (l <= h) {
            m = l + (h-l)/2;
            if (v[m] == t) {
                a = m;
                l = m+1;    
            }
            else if (v[m] < t) l = m+1;
            else h = m-1;
        }
        
        ans.push_back(a);
        return ans;
    }
};

//Below code improves IO runtime
static const int _ = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
