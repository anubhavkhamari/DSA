//brute-force : TLE  : TC : O((kmodn)*n)
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        k = k%n;
        if(n == 1 || k == 0) return;

        for(int i=0; i<k; i++){
            int temp = arr[n-1];
            for(int j = n-2; j >= 0; j--){
                arr[j+1] = arr[j];
            }
            arr[0] = temp;
        }
    }
};