#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> nums) {
    int answer = 0;
    for(int i=0; i<nums.size()-2;i++){
        for(int j=i+1;j<nums.size()-1;j++){
            for(int k=j+1;k<nums.size();k++){
                for(int l=2;l<nums[i]+nums[j]+nums[k];l++){
                    if((nums[i]+nums[j]+nums[k])%l==0){
                        l=nums[i]+nums[j]+nums[k];
                    }
                    else if(l==nums[i]+nums[k]+nums[j]-1){
                        answer++;
                    }
                }
            }
        }
    }

    return answer;
}