class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(begin(arr), end(arr));
        const int offset = arr.size() / 20;
        const int sum = accumulate(begin(arr) + offset, end(arr) - offset, 0);
        return static_cast<double>(sum) / (arr.size() - 2 * offset);
    }
};
