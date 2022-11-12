#include <bits/stdc++.h>
using namespace std;

//class Solution {
//public:
//    vector<int> twoSum(vector<int>& nums, int target) {
//        vector<int> result;
//        for (int i = 0; i <= nums.size(); ++i)
//            for (int j = 0; j <= nums.size(); ++j){
//                if (i==j)
//                    continue;
//                if (nums[i] + nums[j] == target){
//                    result.insert(result.end(), { i, j });
//                    return result;
//                }
//            }
//        return result;
//    }
//};

int main() {
    // Solution solve;
    int target;
    // vector<int> nums;
    // while(cin >> target)
    // solve.twoSum(nums, 6);
    cin >> target;
    cout << "Your number is: "<< target << endl;
    return 0;
}
