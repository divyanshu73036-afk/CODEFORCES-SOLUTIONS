class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if (k == 1) {
            return max(arr[0], arr[1]);
        }
        if (k >= arr.size()) {
            return *max_element(arr.begin(), arr.end());
        }

        int winner= arr[0];
        int wins = 0;
         for (int i = 1; i < arr.size(); ++i) {
            if (winner> arr[i]) {
                wins++;
            } else {
                winner= arr[i];
                wins = 1;
            }

            if (wins == k) {
                return winner;
            }
        }

        return winner;


    }
};