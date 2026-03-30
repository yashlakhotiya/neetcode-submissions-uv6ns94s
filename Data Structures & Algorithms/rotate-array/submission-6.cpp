class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k %= n;
        int count=0;
        for(int i=0; i<n; i++) {
            if(count == n) return;
            count += rotateCycle(arr, i, k);
        }
    }

    int rotateCycle(vector<int>& arr, int startIdx, int k) {
        int n = arr.size();
        int noOfElementsProcessed = 0, currIdx = (startIdx+k)%n, prevVal = arr[startIdx];
        while(currIdx != startIdx) {
            int currIdxVal = arr[currIdx];
            arr[currIdx] = prevVal;
            prevVal = currIdxVal;
            currIdx = (currIdx+k)%n;
            noOfElementsProcessed++;
        }
        arr[startIdx] = prevVal;
        noOfElementsProcessed++;
        return noOfElementsProcessed;
    }
};




