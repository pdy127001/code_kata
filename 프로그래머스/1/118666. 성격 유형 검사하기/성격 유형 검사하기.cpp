#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    unordered_map<char,int> umap;
    umap['R']=0;
    umap['T']=0;
    umap['C']=0;
    umap['F']=0;
    umap['J']=0;
    umap['M']=0;
    umap['A']=0;
    umap['N']=0;
    for(int i=0;i<survey.size();i++){
        if(choices[i]==4){
            continue;
        }
        else if(choices[i]<4){
            umap[survey[i][0]]+=4-choices[i];
        }
        else{
            umap[survey[i][1]]+=choices[i]-4;
        }
    }
    if(umap['R']==umap['T']or umap['R']>umap['T']){
        answer+='R';
    }
    else{
        answer+='T';
    }
     if(umap['C']==umap['F']or umap['C']>umap['F']){
        answer+='C';
    }
    else{
        answer+='F';
    }
     if(umap['J']==umap['M']or umap['J']>umap['M']){
        answer+='J';
    }
    else{
        answer+='M';
    }
     if(umap['A']==umap['N']or umap['A']>umap['N']){
        answer+='A';
    }
    else{
        answer+='N';
    }
    return answer;
}