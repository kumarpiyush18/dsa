#include<bits/stdc++.h>
using namespace std;

#define N 8

int isSafe(int x,int y,int sol[N][N]){
    return (x>=0 && x <N && y >=0 && y<N && sol[x][y]==-1) ;
}

void printsolution(int sol[N][N]){
    for(int x=0;x<N;x++){
        for(int y=0;y<N;y++){
            cout<<sol[x][y]<<" ";
        }
        cout<<endl;
    }
}


int solveKTHelper(int x,int y,int move,int sol[N][N], int xMove[8],int yMove[8]){

    int k, nxt_x,nxt_y;
    if(move == N*N){
        return 1;
    }

    // try all the 8 move of the knigh
    for (k=0;k<8;k++){
        nxt_x = x + xMove[k];
        nxt_y = y + yMove[k];

        if(isSafe(nxt_x,nxt_y,sol)){
            sol[nxt_x][nxt_y] = move;
            if(solveKTHelper(nxt_x,nxt_y,move+1,sol,xMove,yMove)==1){
                return 1;
            }
            else{
                //backtracking
                sol[nxt_x][nxt_y]=-1;
            }
        }
    }
    return 0;
}


void solveKT(){
    int sol[N][N];

    // initialize solution matrix with -1
    memset(sol,-1,sizeof(int));

    // direction of kinght in next move
    int xMove[8]={2,1,-1,-2,-2,-1,1,2};
    int yMove[8]={1,2,2,1,-1,-2,-2,-2};

    sol[0][0]=0;

    if(solveKTHelper(0,0,1,sol,xMove,yMove)==0){
        cout<<"Solution does not exist";
        return;
    }
    else{
        printsolution(sol);
    }

}


int main(){
    solveKT();

    return 0;
}