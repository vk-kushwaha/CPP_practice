#include <iostream>
using namespace std;
int count =0;
void Countpaths(int maze[][4],int rowNo,int colNo,int n)
{

	// if(maze[n-1][n-1]==0)
	// 	return;

	if(rowNo==n-1 && colNo==n-1)
    {
        count++;
		return;
    }
	if(rowNo>=n || colNo>=n)
		return;

	if(maze[rowNo][colNo]==0)
		return;

	Countpaths(maze,rowNo+1,colNo,n);
    Countpaths(maze,rowNo,colNo+1,n);
    

}

int main()
{

	int maze[][4]={	{1,1,1,1},
					{1,0,0,1},
					{1,0,0,1},
					{1,1,1,1}
					};

	int n=4;
	
    Countpaths(maze,0,0,n);
    cout<<"Total No of ways = "<<count;


}