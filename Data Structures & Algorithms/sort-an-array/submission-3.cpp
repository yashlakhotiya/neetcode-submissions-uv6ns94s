class Sort {
    public:
    static void mergeSort(vector<int>& nums, int left, int right) {
        if(left >= right) return;
        int mid = left + (right-left)/2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }

    static void merge(vector<int>& nums, int left, int mid, int right) {
        int i = left, j = mid+1;
        vector<int> temp;
        while(i <= mid && j <= right) {
            if(nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while(i <= mid) temp.push_back(nums[i++]);
        while(j <= right) temp.push_back(nums[j++]);
        for(int i=left; i<= right; i++){
            nums[i] = temp[i-left];
        }
    }

    static void quickSort(vector<int>& arr, int left, int right) {
        if(left < 0 || left >= arr.size() || right < 0 || right >= arr.size()) return;
        if(left >= right) return;
        int partitionIndex = partition(arr, left, right);
        quickSort(arr, left, partitionIndex-1);
        quickSort(arr, partitionIndex+1, right);
    }

    static int partition(vector<int> &arr, int left, int right) {
        int pivotIndex = right, pivotElement = arr[right];
        int l = left, r = pivotIndex-1, m = left;
        while(m <= right && l <= r) {
            if(arr[m] <= pivotElement) {
                swap(arr, l++, m++);
            } else if(arr[m] > pivotElement) {
                swap(arr, r--, m);
            }
        }
        swap(arr, l, pivotIndex);
        return l;
    }

    static void swap(vector<int>& arr, int i, int j) {
        int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        Sort::quickSort(nums, 0, nums.size()-1);
        return nums;
    }
};