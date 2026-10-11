class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();   // total flowers

        if((long long)m * k > n){   // total flowers less than bouquets formation impossible 
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());   // Sabse chhota bloom day: minimum possible answer
        int high = *max_element(bloomDay.begin(), bloomDay.end());   // Sabse bada bloom day: maximum possible answer

        while(low < high){
            int mid = low + (high - low) / 2;

            int flowers = 0;  // count krega kitne flowers khile hue hai 
            int bouquets = 0;  // count krega ki aab tk kitne bouquets bne hai 

            for(int i=0;i<n;i++){   // har flower ko check kro
                if(bloomDay[i] <= mid){    // Agar flower mid day tak khil chuka hai
                    flowers++;
                }
                else{
                    flowers = 0;   // nhi khila to khile hue flowers ka count reset kro 
                }

                if(flowers == k){    // Agar k lagataar flowers mil gaye
                    bouquets++;  // ek bouquet bn gya 
                    flowers = 0;   // clount ni krna 
                }
            }

            if(bouquets >= m){   // Agar required m bouquets ban gaye
                high = mid;  // mid possiblee ans kam days me ka bhi try kro
            }
            else{
                low = mid + 1;  // bouquets km bne to zyada din chahiye 
            }
        }
        return low;   // low high mil gye ye hee min possible day hai 
    }
};