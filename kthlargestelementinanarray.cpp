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

//PQ solution
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &n: nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();
    }
};
//Q select
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        /*priority_queue<int, vector<int>, greater<int>> pq;
        for (auto &n: nums) {
            pq.push(n);
            if (pq.size() > k) pq.pop();
        }
        return pq.top();*/
        k = nums.size()-k;
        int i = 0;
        int j = nums.size()-1;
        while (i < j) {
            int p = partition(nums, i, j);
            if (p < k) {
                i = p + 1;
            }
            else if (p > k) {
                j = p - 1;
            }
            else break;
        }
        return nums[k];
    }
    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[high];
        int i = low-1;
        for (int j = low; j <= high-1; j++) {
            if (nums[j] <= pivot) {
                i++;
                swap(nums[i], nums[j]);
            }
        }
        swap(nums[i+1], nums[high]);
        return i+1;
    }
};
