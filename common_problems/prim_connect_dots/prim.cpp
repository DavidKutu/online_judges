#include <iostream>
using namespace std;

#define ROW 7
#define COL 7
#define infi 5000  //infi for infinity

class prims
{
   float graph[ROW][COL];
   int nodes;
   public:
   prims();
   void createGraph();
   void primsAlgo();
};

prims :: prims()
{
    for(int i=0;i<ROW;i++)
        for(int j=0;j<COL;j++)
            graph[i][j]=0;
}

void prims :: createGraph()
{
    int i,j;
    cout<<"Enter Total Nodes : ";
    cin>>nodes;
    cout<<endl<<"Enter Adjacency Matrix : "<< endl;
    for(i=0;i<nodes;i++)
        for(j=0;j<nodes;j++)
			cin>>graph[i][j];

    //Assign infinity to all graph[i][j] where weight is 0.for(i=0;i<nodes;i++){
    for(j=0;j<nodes;j++)
    {
        if(graph[i][j]==0)
            graph[i][j]=infi;
    }
}


void prims :: primsAlgo()
{
    int selected[ROW],i,j,ne; //ne for no. of edges
    int x,y;
	float min;

    for(i=0;i<nodes;i++)
        selected[i]=false;

    selected[0]=true;
    ne=0;

    while(ne < nodes-1)
    {
        min=infi;
        for(i=0;i<nodes;i++)
        {
            if(selected[i]==true)
			{
                for(j=0;j<nodes;j++)
				{
                    if(selected[j]==false)
					{
                        if(min > graph[i][j])
                        {
                            min=graph[i][j];
                            x=i;
                            y=j;
                        }
                    }
                }
            }
        }
        selected[y]=true;
        cout<<endl<<x+1<<" --> "<<y+1 << "siiiii: "<< min << endl;
        ne=ne+1;
    }
}

int main()
{
    prims MST;
    cout<<"Prims Algorithm to find Minimum Spanning Tree"<< endl;
    MST.createGraph();
    MST.primsAlgo();
    return 0;
}