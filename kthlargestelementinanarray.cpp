class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        vector<int> minHeap;
        for (auto &n: nums) {
            minHeap.push_back(-n);
            push_heap(minHeap.begin(), minHeap.end());
            if (minHeap.size() > k) {
                pop_heap(minHeap.begin(), minHeap.end());
                minHeap.pop_back();
            }
        }
        return minHeap.front()*-1;
    }
};
