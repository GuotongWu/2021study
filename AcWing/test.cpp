#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> PII;
class Solution {
public:
    int dr[4][2] = {
        -1, 0,
        1, 0,
        0, -1,
        0, 1,
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        queue<PII> q;
        q.push({sr,sc});
        image[sr][sc] = newColor;
        while(!q.empty()){
            int cr = q.top().first, cx = q.top().second;
            for(int i=0; i<4; ++i){
                int nr = cr + dr[i][0], nx = cr + dr[i][1];
                if(nr<image.size() && nr>=0 && nx<image[0].size() && nx>=0 && image[nr][nx] ==oldColor){
                    q.push({nr, nx});
                    image[nr][nx] = newColor;
                }
            }
            q.pop();
        }
        return image;
    }
};

int main(){
   queue<int> q;
   q.
}