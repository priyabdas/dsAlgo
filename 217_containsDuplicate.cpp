//
//
//  containsDuplicate
//
//  Created by priyadas on 17/03/22.
//
//
//
//  Created by priyabrata das on 17/03/22.
//


#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>


using namespace std;

bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for (int i = 1 ; i < nums.size();i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;

}

int main(int argc, const char * argv[]) {
    vector <int> nums {1,1,1,3,3,4,3,2,4,2};
    cout << containsDuplicate(nums) << endl;
    //cout << checkInclusion(s1,s2) << endl;

    return 0;
}
