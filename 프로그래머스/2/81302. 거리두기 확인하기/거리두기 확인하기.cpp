#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    
    for(auto &place : places){
        int ok = 1;
        
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                if(place[i][j] != 'P') continue;
                
                for(int d=0; d<4; d++){
                    int nx = i + dx[d];
                    int ny = j + dy[d];
                    if(nx>=0 && ny>=0 && nx<5 && ny<5){
                        if(place[nx][ny] == 'P') ok = 0;
                    }
                }
                
                int nx, ny;
                
                nx = i+2; ny = j;
                if(nx<5 && place[nx][ny]=='P' && place[i+1][j]!='X') ok=0;
                
                nx = i-2; ny = j;
                if(nx>=0 && place[nx][ny]=='P' && place[i-1][j]!='X') ok=0;
                
                nx = i; ny = j+2;
                if(ny<5 && place[nx][ny]=='P' && place[i][j+1]!='X') ok=0;
                
                nx = i; ny = j-2;
                if(ny>=0 && place[nx][ny]=='P' && place[i][j-1]!='X') ok=0;
                
                if(i+1<5 && j+1<5 && place[i+1][j+1]=='P'){
                    if(!(place[i][j+1]=='X' && place[i+1][j]=='X')) ok=0;
                }
                
                if(i+1<5 && j-1>=0 && place[i+1][j-1]=='P'){
                    if(!(place[i][j-1]=='X' && place[i+1][j]=='X')) ok=0;
                }
                
                if(i-1>=0 && j+1<5 && place[i-1][j+1]=='P'){
                    if(!(place[i][j+1]=='X' && place[i-1][j]=='X')) ok=0;
                }
                
                if(i-1>=0 && j-1>=0 && place[i-1][j-1]=='P'){
                    if(!(place[i][j-1]=='X' && place[i-1][j]=='X')) ok=0;
                }
            }
        }
        
        answer.push_back(ok);
    }
    
    return answer;
}