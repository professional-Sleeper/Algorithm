#include <stdio.h>
#include <vector>
using namespace std;

int R,C;
int map[510][510];
int D[510][510];
bool visit[510][510];
int dr[] = {0,0,-1,1};
int dc[] = {-1,1,0,0};

void input(void){
    
   for (int i=1; i<=R; i++){
        for (int j=1; j<=C; j++){
			scanf("%d",&map[i][j]);
            D[i][j] = -1;
        }
    } 
}

void make_DP(int r, int c){
	int nr,nc;
    
    int temp = 0;
    if ( r==1 && c==1 ) return;
    D[r][c] = 0;
    
    for (int i=0; i<4; i++){
    	nr = r + dr[i];   
        nc = c + dc[i];
        
        if (nr<1 || nc<1 || nr>R || nc>C ) continue;
        if (!visit[nr][nc] && map[r][c] < map[nr][nc]){
			make_DP(nr,nc);   
        }
        if (map[r][c] < map[nr][nc]){
            D[r][c] += D[nr][nc];  
        }
    	 
    }
    visit[r][c] = true;
    
    return;
}

int main(void){
	scanf("%d %d",&R,&C);
    
    input();
    visit[1][1] = true;
    D[1][1] = 1;
	make_DP(R,C);
    printf("%d\n",D[R][C]);
 return 0;   
} 
