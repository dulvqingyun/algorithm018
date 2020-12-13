 int n;
class Solution {
struct Node
    {
        int x, y, step;
        Node(int x1,int y1,int step1){x=x1;y=y1;step=step1;}
        friend bool operator>(const Node &a, const Node &b){
            return abs(a.x-(n-1))+ abs(a.y-(n-1)) +a.step> abs(b.x-(n-1))+ abs(b.y-(n-1)) + b.step;   
        }
    };

public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int N = grid.size();
        if(N==0) return -1;
        else if(N==1 && grid[0][0]==0 ) return 1;
        if(grid[0][0] || grid[N-1][N-1]) return -1;
        n=N;
        int dx[8]={-1, +0, +1, +1, +1, +0, -1, -1};
        int dy[8]={+1, +1, +1, +0, -1, -1, -1, +0};
        
        priority_queue<Node, vector<Node>, greater<Node> > pq;
        pq.push(Node(0,0,1));
        vector<int> openList(N * N, 0);
        openList[0]=1;

        while(!pq.empty()){
                auto node = pq.top();
                pq.pop();
                grid[node.x][node.y]=1; //相当于closelist
                for(int i=0; i<8; i++){
                    int x = node.x + dx[i];
                    int y = node.y + dy[i];
                    if( x>=0 && x<N && y>=0 && y<N && grid[x][y]==0){
                        if(x==N-1 && y==N-1) return openList[node.x*N+node.y]+1;
                        // 没有到走过该点或者当前的路线更优
                        if(openList[x*N+y]==0||openList[x*N+y]>openList[node.x*N+node.y]+1){
                            openList[x*N+y]=openList[node.x*N+node.y]+1;
                            pq.push(Node(x,y,openList[x*N+y]));
                        }                          
                    }
                }
        }
        return -1;
    }
};