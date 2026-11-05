class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int count = 0;

        for(int i=0;i<arr1.size();i++){
            bool valid = true;

            for(int j=0;j<arr2.size();j++){
                // Dono elements ka difference check karenge
                if(abs(arr1[i] - arr2[j]) <= d){
                    valid = false;
                    break;
                }
            }

            // Inner loop complete hone ke baad check karenge
            if(valid == true) {
                count++;
            }
        }
        return count;
    }
};