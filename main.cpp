#include "include.h"



class CMain{};
int main()
{
    char nodes[12] = {'A','B','C','D','E','F','G','H','I','J','K','L'};
    CCharGraph g;
    
    for (int i = 0; i < 12; i++)
        g.InsertNode(nodes[i]);
        
    g.InsertEdge(g.GetNode(1), g.GetNode(0), 1, 1);            g.InsertEdge(g.GetNode(4), g.GetNode(0), 1, 1);      g.InsertEdge(g.GetNode(5), g.GetNode(0), 1, 1);
    g.InsertEdge(g.GetNode(2), g.GetNode(1), 1, 1);            g.InsertEdge(g.GetNode(5), g.GetNode(1), 1, 1);
    g.InsertEdge(g.GetNode(3), g.GetNode(2), 1, 1);            g.InsertEdge(g.GetNode(6), g.GetNode(2), 1, 1);
    g.InsertEdge(g.GetNode(6), g.GetNode(3), 1, 1);            g.InsertEdge(g.GetNode(7), g.GetNode(3), 1, 1);
    g.InsertEdge(g.GetNode(5), g.GetNode(4), 1, 1);            g.InsertEdge(g.GetNode(8), g.GetNode(4), 1, 1);
    g.InsertEdge(g.GetNode(6), g.GetNode(5), 1, 1);            g.InsertEdge(g.GetNode(9), g.GetNode(5), 1, 1);      g.InsertEdge(g.GetNode(10), g.GetNode(5), 1, 1);
    g.InsertEdge(g.GetNode(7), g.GetNode(6), 1, 1);            g.InsertEdge(g.GetNode(10), g.GetNode(6), 1, 1);
    g.InsertEdge(g.GetNode(11), g.GetNode(7), 1, 1);
    g.InsertEdge(g.GetNode(9), g.GetNode(8), 1, 1);
    g.InsertEdge(g.GetNode(10), g.GetNode(9), 1, 1);
    g.InsertEdge(g.GetNode(11), g.GetNode(10), 1, 1);
    
    std::cout<<"\nTriangles: "<<g.TriangleCounting();
    std::cout<<"\nQuads: "<<g.QuadCounting();
}