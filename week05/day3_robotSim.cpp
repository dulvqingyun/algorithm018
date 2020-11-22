class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair< int,int > > obstacleSet;
        for(auto s:obstacles)
            obstacleSet.insert({s[0],s[1]});

        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int x=0,y=0;
        int direct =0;
        int ans = 0;
        for(auto cmd:commands){
            if(cmd==-2)
                direct = ( direct + 3) % 4;
            else if(cmd==-1)
                direct = (direct +1 ) % 4;
            else{
                for(int k=0;k<cmd;k++){
                    int nx = x + dx[direct];
                    int ny = y + dy[direct];
                    if(obstacleSet.find({nx,ny})==obstacleSet.end()){
                        x= nx;
                        y = ny;
                        ans = max(ans,x*x+y*y);
                    }
                    else
                        break;

                }
            }

        }

        return ans;

    }
};