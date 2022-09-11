#include<iostream>
using namespace std;
class Solution {
public:
    

    int longestCommonSubsequence(string text1, string text2) {
        
        
        int state[text1.length() + 1][text2.length() + 1];
        
        for (int row = 1; row <= text1.length(); row++) {
            for (int col = 1; col <= text2.length(); col++) {
                if (text1[row - 1] == text2[row - 2]) {
                    state[row][col] = state[row - 1][col - 1] + 1;
                } else {
                    state[row][col] = max(state[row - 1][col], state[row][col - 1]);
                }
            }
        }
        
        return state[text1.length()][text2.length()];
        
    }
};