class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
	int count=0;
	for(int x: arr) if(!x) count++;
	  int n = arr.size();
        for (int i = n - 1; i >= 0; i--) {
            if (!arr[i]) count--;
            if (i + count < n) {
                arr[i + count] = arr[i];
                if (!arr[i] && i + count + 1 < n)
                    arr[i + count + 1] = 0;
            }
        }
    }
};
