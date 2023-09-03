//sum of Subset
#include <iostream>
#include <vector>

using namespace std;

void findSubsets(vector<int>& nums, int target, vector<int>& current, int index) {
    if (target == 0) {
        
        cout << "Subset found: ";
        for (int num : current) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    if (index == nums.size() || target < 0) {
        
        return;
    }

   
    current.push_back(nums[index]);
    findSubsets(nums, target - nums[index], current, index + 1);

    
    current.pop_back();
    findSubsets(nums, target, current, index + 1);
}

int main() {
    vector<int> nums = {1, 2, 5, 6, 8};
    int target = 9;

    vector<int> current;
    findSubsets(nums, target, current, 0);

    return 0;
}


