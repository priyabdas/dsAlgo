//
//
//  two_pointers
//
//  Created by priyadas on 17/03/22.
//
//
// 
//  dsquestions
//
//  Created by priyabrata das on 17/03/22.
//


#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>


using namespace std;

bool freqEqual(vector <int>a , vector<int>b){
    for (int i = 0 ; i < 26 ; i++){
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool checkInclusion(string s1, string s2) {
    vector <int> freqS1(26,0);
    for (auto c : s1)
        freqS1[c-'a']++;

    int start = 0 ;
    int end = 0 ;

    vector <int>freqS2 (26,0);


    while (end < s2.size()){
        freqS2[s2[end] - 'a']++;

        if (end - start+1 == s1.size()){
            if(freqEqual(freqS1,freqS2))
                return  true;
            //compare if both freq are same

        }

        if (end - start+1 < s1.size())
            end++;
        else{
            //remove frep2
            freqS2[s2[start]-'a']--;
            start++;
            end++;
        }



    }

    return false;
}

int main(int argc, const char * argv[]) {
    string s2 = "adcbafd";
    string s1 = "abc";
    cout << checkInclusion(s1,s2) << endl;
    //cout << checkInclusion(s1,s2) << endl;

    return 0;
}
