#include "../include/MinLenghtProblem.h"

using namespace std;

MinLenghtProblem::MinLenghtProblem(Graph G){
    this->G = G;
}


void MinLenghtProblem::Generate_graph()
{
    node n1;
    node n2;

    GenGraph GenG;

    cout<<"Node\tpos x\t\tpos y"<<endl;

    for(int i = 0; i < 20; i+=2)
    {
        n1.n = i;
        n1.x = rand();
        n1.y = rand()/20;


        cout<<n1.n<<"\t"<<n1.x<<"\t\t"<<n1.y<<endl;

        n2.n = i + 1;
        n2.x = rand()*pow(i,2);
        n2.y = sqrt(rand());

        cout<<n2.n<<"\t"<<n2.x<<"\t\t"<<n2.y<<endl;


        GenG.add_edge(n1, n2);
    }

    G = GenG.getGraph();
}


float MinLenghtProblem::SimpleSolution(int node_pair[2])
{
    vector<int> nodelist = G.get_NodeList();
    int numnodes = G.get_numNodes();
    float minimal = G.get_distance(nodelist[0], nodelist[1]);
    node_pair[0] = nodelist[0];
    node_pair[1] = nodelist[1];

    cout<<"Number of nodes: "<<numnodes<<endl;

    for(int i = 0; i < numnodes; i++)
    {
        for(int j = 0; j < numnodes; j++)
        {
            if(i != j){
                float new_min = G.get_distance(nodelist[i], nodelist[j]);
                cout<<"Distance "<<i<<" - "<<j<<": "<<new_min<<endl;
                if(new_min < minimal)
                {
                    minimal = new_min;
                    node_pair[0] = nodelist[i];
                    node_pair[1] = nodelist[j];
                }
            }
        }
    }
    return minimal;
}

void MinLenghtProblem::DCSolution()
{

}


