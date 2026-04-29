class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int l=0, res=1;
        string prev = "";
        for(int r=1; r<arr.size(); r++) {
            if(arr[r] == arr[r-1]) {
                l = r;
                prev = "";
            } else if(prev == "") {
                res = max(res, r-l+1);
                if(arr[r] > arr[r-1]) {
                    prev = ">";
                } else if(arr[r] < arr[r-1]) {
                    prev = "<";
                }
            } else if(prev == "<") {
                if(arr[r] < arr[r-1]) l = r-1;
                else prev = ">";
                res = max(res, r-l+1);
            } else if(prev == ">") {
                if(arr[r] > arr[r-1]) l=r-1;
                else prev = "<";
                res = max(res, r-l+1);
            }
        }
        return res;
    }
};