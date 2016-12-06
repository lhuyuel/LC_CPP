/*
https://www.hackerrank.com/challenges/hackerland-radio-transmitters

Hackerland is a one-dimensional city with  houses, where each house  is located at some  on the -axis. The Mayor wants to install radio transmitters on the roofs of the city's houses. Each transmitter has a range, , meaning it can transmit a signal to all houses  units of distance away.

Given a map of Hackerland and the value of , can you find and print the minimum number of transmitters needed to cover every house in the city? (Every house must be covered by at least one transmitter) Each transmitter must be installed on top of an existing house.

*/
using namespace std;
int countTrans(vector<int> nums, int k) {
    int startIdx = 0, count = 0, n = nums.size();
    
    while (startIdx < n) {
        int left = startIdx, right = n - 1;
        // find the first num that is less than nums[startIdx] + k
        int target = nums[startIdx] + k;

        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] <= target) {
                startIdx = mid;
                if (nums[mid] == target)
                    break;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        ++count; // found a house or not, we need one to cover startIdx to k range
        
        // find the first num that is larger than nums[startIdx] + k, this should be the new start point
        target = nums[startIdx] + k;
        left  = startIdx, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            if (nums[mid] > target) {
                startIdx = mid;
                if (nums[mid] == target) {
                    ++startIdx; // the num that is larger than target
                    break;
                }
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        if (nums[startIdx] < target) break; // no house left
    }
    return count;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> x(n);
    
    for(int x_i = 0;x_i < n;x_i++){
       cin >> x[x_i];
    }
    sort(x.begin(), x.end());
    cout << countTrans(x, k) << endl;
    return 0;
}
