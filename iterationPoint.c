#include<stdio.h>
#include<stdlib.h>

struct newPlayer{
    int age;
    char name[10];
} p[10];

// **** allocate the memory dynamically accordingly to the matrix size***** 
int ijpostionValue[]={1,2,3,4,5,6,7,8,9};

int playerChoice;
void game();
int positionSearch(int ijpostionValue[], int low, int high, int searchKey);
void newPlayer();
void scoreBoard();


int main(){
    while(1){
        printf("\n----menu----\n1.beginGame 2.ScoreBoard 3.exit\nenter your choice\n");
        scanf("%d",&playerChoice);
        switch(playerChoice){
            case 1: {
                game();
            }
            break;

            case 2: {
                scoreBoard();
            }
            break;

            case 3: exit(0);

            default: printf("invalid input\n");
        }   
    }
    return 0;
}

/* apply do-while loop, in while(apply all the conditions possible

eg., 
horizontal: 3 =>
((ijflag[0][0]==1) && (ijflag[0][1]==1) && (ijflag[0][2]==1)) || 
((ijflag[1][0]==1) && (ijflag[1][1]==1) && (ijflag[1][2]==1)) || 
((ijflag[2][0]==1) && (ijflag[2][1]==1) && (ijflag[2][2]==1)) || 

vertical: 3 =>
((ijflag[0][0]==1) && (ijflag[1][0]==1) && (ijflag[2][0]==1)) || 
((ijflag[0][1]==1) && (ijflag[1][1]==1) && (ijflag[2][1]==1)) || 
((ijflag[0][2]==1) && (ijflag[1][2]==1) && (ijflag[2][2]==1)) || 

diagonal: 2 =>
((ijflag[0][0]==1) && (ijflag[1][1]==1) && (ijflag[2][2]==1)) || 
((ijflag[0][2]==1) && (ijflag[1][1]==1) && (ijflag[2][0]==1))

*** this is just flag values, you have to apply that for X and O strings 
*** also this should switch players
*** (position replacement -> )
(0,0) = 1,
(0,1) = 2,
(0,2) = 3,
(1,0) = 4,
(1,1) = 5,
(1,2) = 6,
(2,0) = 7,
(2,1) = 8,
(2,2) = 9
***
to win 
*/

void game(){
    int m=0, n=0, i=0, j=0;
    int ijflag[3][3];
    int searchKey;
    
    printf("enter the size of matrix(m*n)\n");
    scanf("%d%d",&m,&n);
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            printf(" - ");
        }
        printf("\n");
    }

    printf("\nflag values:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            ijflag[i][j]=0;
            printf(" %d ",ijflag[i][j]);        
        }
        printf("\n");
    }
    for(int k=0; k<9;k++){
        printf("%d ",ijpostionValue[k]);   
    }

    printf("\navaliable units:\n");
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(ijflag[i][j]==0)
                printf("(%d,%d) ",i,j);       
        }
        printf("\n");
    }

    printf("enter the position\n");
    scanf("%d",&searchKey);

    int sizeOfArray  = sizeof(ijpostionValue)/sizeof(ijpostionValue[0]);
    
    int searchRes = positionSearch(ijpostionValue, 0, sizeOfArray-1, searchKey);
    
    (searchRes == -1)?printf("not found\n"):printf("found %d\n", searchRes);
    
}

// this function uses binary search for searching 
int positionSearch(int ijpostionvalue[], int low, int high, int searchKey){
    while(low<=high){
        int mid = low +(high-low)/2;

        if (ijpostionvalue[mid] == searchKey)
            return mid;

        if (ijpostionvalue[mid] < searchKey)
            low = mid + 1;
        else
            high = mid - 1; 
    }
    return -1;

}

void scoreBoard(){
    printf("\n");
}

void newPlayer(){
    printf("\n");
}