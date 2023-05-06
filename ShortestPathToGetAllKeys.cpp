/*
You are given an m x n grid grid where:
'.' is an empty cell.
'#' is a wall.
'@' is the starting point.
Lowercase letters represent keys.
Uppercase letters represent locks.
You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.
If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.
For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.
Return the lowest number of moves to acquire all keys. If it is impossible, return -1.

Example 1:
Input: grid = ["@.a..","###.#","b.A.B"]
Output: 8
Explanation: Note that the goal is to obtain all the keys not to open all the locks.

Example 2:
Input: grid = ["@..aA","..B#.","....b"]
Output: 6

Example 3:
Input: grid = ["@Aa"]
Output: -1
*/

class Solution {
    int dirx[4]={1,0,-1,0};
    int diry[4]={0,1,0,-1};
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n=grid.size(),m=grid[0].size();
        int sx,sy;
        map<char,int> mkey;
        for(int x=0;x<n;x++){
            for(int y=0;y<m;y++){
                if(grid[x][y]=='@'){
                    sx=x;sy=y;
                }
                else if('a'<=grid[x][y] and grid[x][y]<='z')
                    mkey[grid[x][y]]=1;
            }
        }
        int k=0;
        for(auto &a:mkey)
            a.second=k++;
        int ans=(1<<k)-1;
        map<tuple<int,int,int>,int> visited;
        queue<tuple<int,int,int>> q;//{x,y,k}
        q.push({sx,sy,0});
        visited[{sx,sy,0}]=1;
        while(q.size()){
            auto [xx,yy,key]=q.front();
            q.pop();
            if(key==ans)
                return visited[{xx,yy,key}]-1;
            for(int dir=0;dir<4;dir++){
                int nx=xx+dirx[dir];
                int ny=yy+diry[dir];
                int nkey=key;
                if(nx>=0 and nx<n and
                   ny>=0 and ny<m and
                   grid[nx][ny]!='#'
                  ){
                    if(mkey.find(grid[nx][ny])!=mkey.end())
                        nkey|=(1<<mkey[grid[nx][ny]]);
                    if('A'<=grid[nx][ny] and grid[nx][ny]<='Z'){
                        int lock=mkey[grid[nx][ny]-'A'+'a'];
                        if(((nkey>>lock)&1)==0)
                            continue;
                    }
                    tuple<int,int,int> nstate={nx,ny,nkey};
                    if(visited[nstate]>0)
                        continue;
                    visited[nstate]=visited[{xx,yy,key}]+1;
                    q.push(nstate);
                }
            }
        }
        return -1;
    }
};
