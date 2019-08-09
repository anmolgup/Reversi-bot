# include <iostream>
# include <cstdio>
# include <cstdlib>
# include <vector>
using namespace std;
int curPlayer,otherPlayer;
int pointBoard[10][10];
void printState(int **a)
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
            cout<<a[i][j]<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}
bool turn=0;

void makePointBoard()
{
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if((i==0 || i==9) && (j==0 || j==9))
                pointBoard[i][j]=500000;
            else if((i==0 || i==9) && (j>=2 && j<=7))
                pointBoard[i][j]=10000;
            else if((j==0 || j==9) && (i>=2 && i<=7))
                pointBoard[i][j]=10000;
			else if((i==0 || i==9) && (j==1 || j==8))
				pointBoard[i][j]=500000;
			else if((j==0 || j==9) && (i==1 || i==8))
				pointBoard[i][j]=500000;
			else if((i==1 || i==8) && (j==1 || j==8))
				pointBoard[i][j]=500000;
            else
                pointBoard[i][j]=1000;
        }
    }
	for(int i=2;i<=7;i++)
		pointBoard[i][i]=5000;
	for(int i=7;i>=2;i--)
		pointBoard[i][9-i]=5000;
	
}

int** getNewState(int **a,int firstPlayer,int index)
{
    int secondPlayer,row,col;
    if(firstPlayer==1)
        secondPlayer=2;
    else
        secondPlayer=1;
    row=index/10;
    col=index%10;
	int **newGame=(int **)calloc(sizeof(int *),10);
	for(int i=0;i<10;i++)
		newGame[i]=(int *)calloc(sizeof(int),10);
    for(int i=0;i<10;i++)
        for(int j=0;j<10;j++)
            newGame[i][j]=a[i][j];
    int flag=0;
	// this is down direction
    for(int k=row+1;k<10;k++)
    {
        if(a[k][col]==secondPlayer)
            continue;
        else if(a[k][col]==firstPlayer)
        {
            flag=1;
            break;
        }
        else
            break;
    }
    ////////cout<<"this is the old state\n";
    ////////printState(a);
    ////////cout<<"\n";
    if(flag)
    {
        ////////cout<<"up direction matched\n";
        newGame[row][col]=firstPlayer;
        for(int k=row+1;k<10;k++)
        {
            if(a[k][col]==secondPlayer)
                newGame[k][col]=firstPlayer;
            else if(a[k][col]==firstPlayer)
                break;
        }
        ////////cout<<"this is the new state\n\n";
        ////////printState(newGame);
        ////////getchar();
    }
    flag=0;
    // now the up direction
    for(int k=row-1;k>=0;k--)
    {
        if(a[k][col]==secondPlayer)
            continue;
        else if(a[k][col]==firstPlayer)
        {
            flag=1;
            break;
        }
        else
            break;
    }
    if(flag)
    {
        ////////printf("down direction matched\n");
        newGame[row][col]=firstPlayer;
        for(int k=row-1;k>=0;k--)
        {
            if(a[k][col]==secondPlayer)
                newGame[k][col]=firstPlayer;
            else if(a[k][col]==firstPlayer)
                break;
        }
        ////////cout<<"this is the new state\n\n";
        ////////printState(newGame);
        ////////getchar();
    }
    // now the right direction
    flag=0;
    for(int k=col+1;k<10;k++)
    {
        if(a[row][k]==secondPlayer)
            continue;
        else if(a[row][k]==firstPlayer)
        {
            flag=1;
            break;
        }
        else
            break;
    }
    if(flag)
    {
        ////////printf("right direction mached\n");
        newGame[row][col]=firstPlayer;
        for(int k=col+1;k<10;k++)
        {
            if(a[row][k]==secondPlayer)
                newGame[row][k]=firstPlayer;
            else if(a[row][k]==firstPlayer)
                break;
        }
        ////////cout<<"this is the new state\n\n";
        ////////printState(newGame);
        ////////getchar();
    }
    // now the left direction
    flag=0;
    for(int k=col-1;k>=0;k--)
    {
        if(a[row][k]==secondPlayer)
            continue;
        else if(a[row][k]==firstPlayer)
        {
            flag=1;
            break;
        }
        else
            break;
    }
    if(flag)
    {
        ////////cout<<"left direction matched\n";
        newGame[row][col]=firstPlayer;
        for(int k=col-1;k>=0;k--)
        {
            if(a[row][k]==secondPlayer)
                newGame[row][k]=firstPlayer;
            else if(a[row][k]==firstPlayer)
                break;
        }
        ////////cout<<"this is the new state\n\n";
        ////////printState(newGame);
        ////////getchar();
    }
    // now the down right direction
    flag=0;
    for(int k=col+1,p=row+1;(k<10 && p<10);k++,p++)
    {
        if(a[p][k]==secondPlayer)
            continue;
        else if(a[p][k]==firstPlayer)
        {
            flag=1;
            break;
        }
        else
            break;
    }
    if(flag)
    {
        ////////cout<<"down right direction matched\n";
        newGame[row][col]=firstPlayer;
        for(int k=col+1,p=row+1;(k<10 && p<10);k++,p++)
        {
            if(a[p][k]==secondPlayer)
                newGame[p][k]=firstPlayer;
            else if(a[p][k]==firstPlayer)
                break;
        }
        ////////cout<<"this is the new state\n\n";
        ////////printState(newGame);
        ////////getchar();
    }
    // now the up left direction
    flag=0;
    for(int k=col-1,p=row-1;(k>=0 && p>=0);k--,p--)
    {
        if(a[p][k]==secondPlayer)
            continue;
        else if(a[p][k]==firstPlayer)
        {
            flag=1;
            break;
        }
        else
            break;
    }
    if(flag)
    {
        ////////cout<<"up left matched\n";
        newGame[row][col]=firstPlayer;
        for(int k=col-1,p=row-1;(k>=0 && p>=0);k--,p--)
        {
            if(a[p][k]==secondPlayer)
                newGame[p][k]=firstPlayer;
            else if(a[p][k]==firstPlayer)
                break;
        }
        ////////cout<<"this is the new state\n\n";
        ////////printState(newGame);
        ////////getchar();
    }
    // now the up right direction
    flag=0;
    for(int k=col+1,p=row-1;(k<10 && p>=0);k++,p--)
    {
        if(a[p][k]==secondPlayer)
            continue;
        else if(a[p][k]==firstPlayer)
        {
            flag=1;
            break;
        }
        else
            break;
    }
    if(flag)
    {
        ////////cout<<"up right matched\n";
        newGame[row][col]=firstPlayer;
        for(int k=col+1,p=row-1;(k<10 && p>=0);k++,p--)
        {
            if(a[p][k]==secondPlayer)
                newGame[p][k]=firstPlayer;
            else if(a[p][k]==firstPlayer)
                break;
        }
        ////////cout<<"this is the new state\n\n";
        ////////printState(newGame);
        ////////getchar();
    }
    // now the down left direction finally
    flag=0;
    for(int k=col-1,p=row+1;(k>=0 && p<10);k--,p++)
    {
        if(a[p][k]==secondPlayer)
            continue;
        else if(a[p][k]==firstPlayer)
        {
            flag=1;
            break;
        }
        else
            break;
    }
    if(flag)
    {
        ////////cout<<"down left matched\n";
        newGame[row][col]=firstPlayer;
        for(int k=col-1,p=row+1;(k>=0 && p<10);k--,p++)
        {
            if(a[p][k]==secondPlayer)
                newGame[p][k]=firstPlayer;
            else if(a[p][k]==firstPlayer)
                break;
        }
        ////////cout<<"this is the new state\n\n";
        ////////printState(newGame);
        ////////getchar();
    }
    ////////cout<<" this is the new state on applying previous move\n";
    ////////printState(newGame);
    ////////getchar();
	return newGame;
}


bool* moveGen(int **a,int firstPlayer)
{
    ////////cout<<" inside the move generation function\n";
    bool *position=(bool *)calloc(sizeof(bool),100);
    bool flag=0;
    int secondPlayer=0;
    int index=0;
    if(firstPlayer==1)
        secondPlayer=2;
    else
        secondPlayer=1;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            // down direction. will place up
            if(a[i][j]==secondPlayer && (i-1)>=0 && a[i-1][j]==0)
            {
               // ////////cout<<"\nup\n";
                ////////printf("i=%d and j=%d other\n",i,j);
                index=(i-1)*10+j;
                flag=0;
                for(int k=i+1;k<10;k++)
                {
                    if(a[k][j]==secondPlayer)
                        continue;
                    else if(a[k][j]==firstPlayer)
                    {
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
                if(flag)
                {
                    ////////cout<<"match found\n";
                    int row=index/10;
                    int col=index%10;
                    ////////printf("row=%d and col=%d\n\n",row,col);
                    position[index]=1;
                }
                ////////getchar();
            }
            // now the up direction. Will place new piece in down direc.
            if(a[i][j]==secondPlayer && (i+1)<10 && a[i+1][j]==0)
            {
                ////////cout<<"\ndown\n";
                ////////printf("i=%d and j=%d other\n",i,j);
                index=(i+1)*10+j;
                flag=0;
                for(int k=i-1;k>=0;k--)
                {
                    if(a[k][j]==secondPlayer)
                        continue;
                    else if(a[k][j]==firstPlayer)
                    {
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
                if(flag)
                {
                    int row=index/10;
                    int col=index%10;
                    ////////printf("row=%d and col=%d\n",row,col);
                    position[index]=1;
                }
                ////////getchar();
            }
            // now the new piece in left direction
            if(a[i][j]==secondPlayer && (j-1)>=0 && a[i][j-1]==0)
            {
                ////////cout<<"\nleft\n";
                ////////printf("i=%d and j=%d other\n",i,j);
                index=(i)*10+j-1;
                flag=0;
                for(int k=j+1;k<10;k++)
                {
                    if(a[i][k]==secondPlayer)
                        continue;
                    else if(a[i][k]==firstPlayer)
                    {
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
                if(flag)
                {
                    int row=index/10;
                    int col=index%10;
                    ////////printf("row=%d and col=%d\n",row,col);
                    position[index]=1;
                }
                ////////getchar();
            }
            // new piece in right direction
            if(a[i][j]==secondPlayer && (j+1)<10 && a[i][j+1]==0)
            {
                ////////cout<<"\nright\n";
                ////////printf("i=%d and j=%d other\n",i,j);
                index=(i)*10+j+1;
                flag=0;
                for(int k=j-1;k>=0;k--)
                {
                    if(a[i][k]==secondPlayer)
                        continue;
                    else if(a[i][k]==firstPlayer)
                    {
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
                if(flag)
                {
                    int row=index/10;
                    int col=index%10;
                   // ////////printf("row=%d and col=%d\n",row,col);
                    position[index]=1;
                }
                ////////getchar();
            }
            // right right direction
            if(a[i][j]==secondPlayer && (j+1<10 && i+1<10) &&  a[i+1][j+1]==0)
            {
                ////////cout<<"\ndown right\n";
                ////////printf("i=%d and j=%d other\n",i,j);
                index=(i+1)*10+j+1;
                flag=0;
                for(int k=j-1,p=i-1;(k>=0 && p>=0);(k--,p--))
                {
                    if(a[p][k]==secondPlayer)
                        continue;
                    else if(a[p][k]==firstPlayer)
                    {
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
                if(flag)
                {
                    int row=index/10;
                    int col=index%10;
                 //   ////////printf("row=%d and col=%d\n",row,col);
                    position[index]=1;
                }
                ////////getchar();
            }
            // left left direction
            if(a[i][j]==secondPlayer && (j-1>=0 && i-1>=0) &&  a[i-1][j-1]==0)
            {
                ////////cout<<"\nup left\n";
                ////////printf("i=%d and j=%d other\n",i,j);
                index=(i-1)*10+j-1;
                flag=0;
                for(int k=j+1,p=i+1;(k<10 && p<10);(k++,p++))
                {
                    if(a[p][k]==secondPlayer)
                        continue;
                    else if(a[p][k]==firstPlayer)
                    {
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
                if(flag)
                {
                    int row=index/10;
                    int col=index%10;
                 //   ////////printf("row=%d and col=%d\n",row,col);
                    position[index]=1;
                }
                ////////getchar();
            }
            // right up direction
            if(a[i][j]==secondPlayer && (j+1<10 && i-1>=0) &&  a[i-1][j+1]==0)
            {
                ////////cout<<"\nup right\n";
                ////////printf("i=%d and j=%d other\n",i,j);
                index=(i-1)*10+j+1;
                flag=0;
                for(int k=j-1,p=i+1;(k>=0 && p<10);(k--,p++))
                {
                    if(a[p][k]==secondPlayer)
                        continue;
                    else if(a[p][k]==firstPlayer)
                    {
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
                if(flag)
                {
                    int row=index/10;
                    int col=index%10;
                 //   ////////printf("row=%d and col=%d\n",row,col);
                    position[index]=1;
                }
                ////////getchar();
            }
            // down left direction
            if(a[i][j]==secondPlayer && (j-1>=0 && i+1<10) &&  a[i+1][j-1]==0)
            {
                ////////cout<<"\ndown left direction\n";
                ////////printf("i=%d and j=%d other\n",i,j);
                index=(i+1)*10+j-1;
                flag=0;
                for(int k=j+1,p=i-1;(k<10 && p>=0);(k++,p--))
                {
                    if(a[p][k]==secondPlayer)
                        continue;
                    else if(a[p][k]==firstPlayer)
                    {
                        flag=1;
                        break;
                    }
                    else
                        break;
                }
                if(flag)
                {
                    int row=index/10;
                    int col=index%10;
                  //  ////////printf("row=%d and col=%d\n",row,col);
                    position[index]=1;
                }
                ////////getchar();
            }
        }
    }
    return position;
}
// The following is the evaluation function of the board since the board 
// can't be traversed compeletely.At starting I am trying to keep it really
// baisc. It will evaluate on the basis of difference of the no of players
// colors. Also on observing it is noticed that the human player has to 
// avoid getting on the 2nd last position of the corner cells and try to
// get to the corner cells. And hence the vice versa is true. So the
// function must also takes these points in mind.Also on further observing
// it is noticed that the player's colors shouldn't be in groups together
// since it increases the chances of them being cut by the second player
// directly as a whole.so less the no of pairs the more it is good. But keep
// aside these subtle points which make the evaluation function a little
// thorough and instead aim for making a simple function first.
int evaluation(int **a)
{
    int points=0;
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            if((i==0 || i==9) && (j==1 || j==8))
            {
                if(a[i][j]==otherPlayer)
                {
					int flag=0;
					if(i==0 && j==1 && (a[0][0]==otherPlayer || a[0][0]==curPlayer))
						flag=1;
					else if(i==0 && j==8 && (a[0][9]==otherPlayer || a[0][9]==curPlayer))
						flag=1;
					else if(i==9 && j==1 && (a[9][0]==otherPlayer || a[9][0]==curPlayer))
						flag=1;
					else if(i==9 && j==8 && (a[9][9]==otherPlayer || a[9][9]==curPlayer))
						flag=1;
					/*else if(i==0 && j==1 && a[0][0]==curPlayer)
					{
						for(int k=2;k<10;k++)
						{
							if(a[0][k]==0)
							{
								flag=0;
								break;
							}
							else if(a[0][k]==curPlayer)
							{
								flag=1;
								break;
							}
						}
					}
					else if(i==0 && j==8 && a[0][9]==curPlayer)
					{
						for(int k=7;k>=0;k--)
						{
							if(a[0][k]==0)
							{
								flag=0;
								break;
							}
							else if(a[0][k]==curPlayer)
							{
								flag=1;
								break;
							}
						}
					}
					else if(i==9 && j==1 && a[9][0]==curPlayer)
					{
						for(int k=2;k<10;k++)
						{
							if(a[0][k]==0)
							{
								flag=0;
								break;
							}
							else if(a[0][k]==curPlayer)
							{
								flag=1;
								break;
							}
						}
					}
					else if(i==9 && j==8 && a[9][9]==curPlayer)
					{
						for(int k=7;k>=0;k--)
						{
							if(a[0][k]==0)
							{
								flag=0;
								break;
							}
							else if(a[0][k]==curPlayer)
							{
								flag=1;
								break;
							}
						}
					}*/
					else
					{
		                for(int k=0;k<10;k++)
		                {
		                    if(a[i][k]==curPlayer)
		                    {
		                        flag=0;
		                        break;
		                    }
		                }
					}
                    if(flag)
                        points-=(pointBoard[i][j]*1);
                    else
                        points+=(pointBoard[i][j]*1);
                }
                else if(a[i][j]==curPlayer)
                {
                    if((i==0 && j==1))
                    {
                        if(a[0][0]==curPlayer || a[0][0]==otherPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                    else if((i==0 && j==8))
                    {
                        if(a[0][9]==curPlayer || a[0][9]==otherPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                    else if((i==9 && j==1))
                    {
                        if(a[9][0]==curPlayer || a[9][0]==otherPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                    else if((i==9 && j==8))
                    {
                        if(a[9][9]==curPlayer || a[9][9]==otherPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                }
            }
            else if((j==0 || j==9) && (i==1 || i==8))
            {
                if(a[i][j]==otherPlayer)
                {
					int flag=0;
					if(j==0 && i==1 && (a[0][0]==otherPlayer || a[0][0]==curPlayer))
						flag=1;
					else if(j==9 && i==1 && (a[0][9]==otherPlayer || a[0][9]==curPlayer))
						flag=1;
					else if(j==0 && i==8 && (a[9][0]==otherPlayer || a[9][0]==curPlayer))
						flag=1;
					else if(j==9 && i==8 && (a[9][9]==otherPlayer || a[9][9]==curPlayer))
						flag=1;
                    for(int k=0;k<10;k++)
                    {
                        if(a[k][j]==curPlayer)
                        {
                            flag=1;
                            break;
                        }
                    }
                    if(flag)
                        points-=(pointBoard[i][j]*1);
                    else
                        points+=(pointBoard[i][j]*1);
                }
                else if(a[i][j]==curPlayer)
                {
                    if(j==0 && i==1)
                    {
                        if(a[0][0]==curPlayer || a[0][0]==otherPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                    else if(j==9 && i==1)
                    {
                        if(a[0][9]==curPlayer || a[0][9]==otherPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                    else if(j==0 && i==8)
                    {
                        if(a[9][0]==curPlayer || a[9][0]==otherPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                    else if(j==9 && i==8)
                    {
                        if(a[9][9]==curPlayer || a[9][9]==otherPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                }
            }
            else if((j==1 || j==8) && (i==1 || i==8))
            {
                if(a[i][j]==otherPlayer)
				{
					int flag=0;
					if(i==1 && j==1 && a[0][0]==0)
						flag=1;
					else if(i==1 && j==8 && a[0][9]==0)
						flag=1;
					else if(i==8 && j==1 && a[9][0]==0)
						flag=1;
					else if(i==8 && j==8 && a[9][9]==0)
						flag=1;
					if(flag)
						points+=pointBoard[i][j];
					else
						points-=pointBoard[i][j];
				}
                else if(a[i][j]==curPlayer)
                {
                    if(j==1 && i==1)
                    {
                        if(a[0][0]==curPlayer && a[0][1]==curPlayer && a[1][0]==curPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                    else if(j==8 && i==1)
                    {
                        if(a[0][9]==curPlayer && a[0][8]==curPlayer && a[1][9]==curPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                    else if(j==1 && i==8)
                    {
                        if(a[9][0]==curPlayer && a[8][0]==curPlayer && a[9][1]==curPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                           points-=(pointBoard[i][j]*1);
                    }
                    else if(j==8 && i==8)
                    {
                        if(a[9][9]==curPlayer && a[9][8]==curPlayer && a[8][9]==curPlayer)
                            points+=(pointBoard[i][j]*1);
                        else
                            points-=(pointBoard[i][j]*1);
                    }
                }
            }
            else if(a[i][j]==curPlayer)
                points+=pointBoard[i][j];
            else if(a[i][j]==otherPlayer)
                points-=pointBoard[i][j];
			else
			{
				// left corner is there
				if(a[0][0]==curPlayer)
				{
					for(int k=1;k<10;k++)
					{
						if(a[0][k]==curPlayer)
							points+=60000;
						else
							break;
					}
					for(int k=1;k<10;k++)
					{
						if(a[k][0]==curPlayer)
							points+=60000;
						else
							break;
					}
				}
				else if(a[0][9]==curPlayer)  // right corner
				{
					for(int k=8;k>=0;k--)
					{
						if(a[0][k]==curPlayer)
							points+=60000;
						else
							break;
					}
					for(int k=1;k<10;k++)
					{
						if(a[k][9]==curPlayer)
							points+=60000;
						else
							break;
					}
				}
				else if(a[9][0]==curPlayer)  // bottom left corner
				{
					for(int k=8;k>=0;k--)
					{
						if(a[k][0]==curPlayer)
							points+=60000;
						else
							break;
					}
					for(int k=1;k<10;k++)
					{
						if(a[9][k]==curPlayer)
							points+=60000;
						else
							break;
					}
				}
				else if(a[9][9]==curPlayer)  // bottom right corner
				{
					for(int k=8;k>=0;k--)
					{
						if(a[k][9]==curPlayer)
							points+=60000;
						else
							break;
					}
					for(int k=8;k>=0;k--)
					{
						if(a[9][k]==curPlayer)
							points+=60000;
						else
							break;
					}
				}
			}
	
        }
    }
    return points;
}
int noOfStates=0;

int minimax(int **a,int depth,int states)
{
    //printf("depth=%d and states=%d\n",depth,states);
    //getchar();
    int ans=0;
    int counter=0;
	int minValue=100000000,temp=0;
    int maxValue=-100000000;
    if(depth%2==1) // it is the chance of the human player bot so we will
        // choose the maximum node
    {
		//////getchar();
        //cout<<"initial state\n";
        //printState(a);
        //using move generator get all the possible moves for the player 1
        //and then using those moves generate a state for each of them and 
        //then apply evaluation function on those
        ////getchar();
        bool *moves=moveGen(a,curPlayer);
        // movegen is now compelete. we have got valid moves. We have to 
        // now make game state for each valid move and recurse up to a
        // sufficient depth
        // now make game states for all the moves in the moves array
        //cout<<"all possible moves are\n";
        for(int i=0;i<100;i++)
        {
            if(moves[i])
            {
                counter++;
                //printf("row=%d and col=%d\n",i/10,i%10);
            }
        }
        //printf("no of moves=%d\n",counter);
        if(counter>states || counter==0)
        {
            noOfStates++;
            //printf("less than no of states so returning\n");
            ////getchar();
            return evaluation(a);
        }
        //cout<<"Now taking them one by one\n\n";
        int statesLevel=states/counter;
        int left=states-counter*statesLevel;
        for(int i=0;i<100;i++)
        {
            if(moves[i])
            {
                int row=i/10;
                int col=i%10;
                //printf("\nrow=%d and col=%d\n",row,col);
                // here we will change the game state. Make a function 
                // do it inside here only
                // check the eight directions that you can go and see whether
                // you are able to covert the other player pieces into yours
                // make a new array statically but after getting the 
                // evaluation if the array is dynamic you can clear the 
                // memory used by it.
                
                // down direction
                //cout<<"this is the previous state\n";
                //printState(a);
                //cout<<"\n";
				int **newGameState=getNewState(a,curPlayer,i);
                //cout<<"this is the new state\n";
                //printState(newGameState);
                //getchar();
                if(left>0)
                {
                    temp=minimax(newGameState,depth+1,statesLevel+1);
                    left--;
                }
                else
                    temp=minimax(newGameState,depth+1,statesLevel);
                //printf("depth =%d temp=%d\n",depth,temp);
                if(temp>maxValue)
                    maxValue=temp;
            }
        }
        //printf("depth=%d maxValue=%d\n",depth,maxValue);
        //getchar();
        return maxValue;
    }
    else
    {
        ////getchar();
        //cout<<"initial state\n";
        //printState(a);
        bool *moves=moveGen(a,otherPlayer);
        //cout<<"all possible moves are\n";
        for(int i=0;i<100;i++)
        {
            if(moves[i])
            {
                counter++;
                //printf("row=%d and col=%d\n",i/10,i%10);
            }
        }
        if(counter>states || counter==0)
        {
            noOfStates++;
            //printf("no of moves greater than states so returning\n");
            //getchar();
            return evaluation(a);
        }
        //cout<<"Now taking them one by one\n\n";
        int statesLevel=states/counter;
        int left=states-counter*statesLevel;
        for(int i=0;i<100;i++)
        {
            if(moves[i])
            {
                int row=i/10;
                int col=i%10;
                //printf("\nrow=%d and col=%d\n",row,col);
                //here we will change the game state. Make a function 
                // do it inside here only
                // check the eight directions that you can go and see whether
                // you are able to covert the other player pieces into yours
                // make a new array statically but after getting the 
                // evaluation if the array is dynamic you can clear the 
                // memory used by it.
                
                // down direction
                //cout<<"this is the previous state\n";
                //printState(a);
                //cout<<"\n";
				int **newGameState=getNewState(a,otherPlayer,i);
                //cout<<"this is the new state\n";
                //printState(newGameState);
                if(left>0)
                {
                    temp=minimax(newGameState,depth+1,statesLevel+1);
                    left--;
                }
                else
                    temp=minimax(newGameState,depth+1,statesLevel);
                //printf(" depth=%d temp=%d\n",depth,temp);
                //getchar();
                if(temp<minValue)
                    minValue=temp;
            }
        }
        //printf("depth=%d and minValue=%d\n",depth,minValue);
        //getchar();
        return minValue;
    }
}

int main(void)
{
    int **game=(int **)calloc(sizeof(int *),10);
    for(int i=0;i<10;i++)
        game[i]=(int *)calloc(sizeof(int),10);
    makePointBoard();
    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            scanf("%d",&game[i][j]);
            if(game[i][j]==3)
                game[i][j]=0;
        }
    }
    scanf("%d",&curPlayer);
    if(curPlayer==1)
        otherPlayer=2;
    else
        otherPlayer=1;
    int depth=0;
    bool *moves=moveGen(game,curPlayer);
    int bestMove=0,maxVal=-1000000000,minVal=1000000000,temp=0;
    int counter=0;
    for(int i=0;i<100;i++)
    {
        if(moves[i])
        {
            counter++;
            //////printf("row=%d and col=%d\n",i/10,i%10);
        }
    }
    depth=1;
    int states=380000;
    //if(depth%2==0)
     //   g=1;
    int statesLevel=states/counter;
    int left=states-counter*statesLevel;
    for(int i=0;i<100;i++)
    {
        if(moves[i])
        {
            int row=i/10,col=i%10;
            int **newGameState=getNewState(game,curPlayer,i);
            //printf("row=%d and col=%d\n",row,col);
            //printf("new game state\n");
            //printState(newGameState);
            if(left>0)
            {
                temp=minimax(newGameState,depth+1,statesLevel+1);
                left--;
            }
            else
                temp=minimax(newGameState,depth+1,statesLevel);
            // remember to take the corner pieces immediately
            //printf("temp=%d\n",temp);
            ////getchar();
            if(temp>maxVal)
            {
                maxVal=temp;
                bestMove=i;
            }
        }
    }   
    printf("%d %d\n",bestMove/10,bestMove%10);
    //cout<<maxVal<<endl;;
    cout<<noOfStates<<endl;
    return 0;
}
