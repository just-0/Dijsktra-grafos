#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <SFML/Graphics.hpp>


using namespace std;

template<class G>
struct CNode
{
    typedef typename G::Edge Edge;
    typedef typename G::N    N;
    
    CNode(N v)
    {   value = v; }
    
    list<Edge*> edges;
    N value;
};

template<class G>
struct CEdge
{
    typedef typename G::Node Node;
    typedef typename G::E    E;
    
    CEdge(Node* a, Node*b, E e, bool d)
    {
        nodes[0] = a; nodes[1] = b;
        value = e; dir = d;
        nodes[0]->edges.push_back(this);
        nodes[1]->edges.push_back(this);
    }
    
    ~CEdge()
    {
        CEdge* edge_a, *edge_b;
        edge_a = RemoveEdgeFromNode(nodes[0], value);
        edge_b = RemoveEdgeFromNode(nodes[1], value);
        assert(edge_a == edge_b);
    }
        
    Node* nodes[2];
    E value;
    bool dir; //0=bidireccional, 1 = nodes[0]=>nodes[1]
};

template<class _N, class _E>
class CGraph
{
public:
    typedef CGraph<_N,_E>   G;
    typedef _N              N;
    typedef _E              E;
    typedef CNode<G>        Node;
    typedef CEdge<G>        Edge;

    bool InsertNode(N n)
    {
        Node* node = new Node(n);
        nodes.push_back(node);
        return 1;
    }
    
    bool InsertEdge(Node* a, Node* b, E e, bool dir)
    {
        new Edge(a,b,e,dir);
        return 1;
    }
    
    bool RemoveEdge(Node* a, Node* b, E e)
    {
        Edge* edge_a, *edge_b;
        edge_a = RemoveEdgeFromNode(nodes[0], e);
        edge_b = RemoveEdgeFromNode(nodes[1], e);
        assert(edge_a == edge_b);
        delete edge_a;
        return true;
    }
    
    Edge* RemoveEdgeFromNode(Node* n, E e)
    {
        for ( auto i : n->edges )
            if ( i->value == e )
            {   n->edges.erase(i);
                return *i;
            }
        return 0;
    }
    
    bool RemoveNode(Node* n)
    {
        for ( auto i : n->edges )
            RemoveEdge(i->nodes[0], i->nodes[1], i->value);
        for ( auto ni : nodes )
            if ( *ni == n )
            {
                nodes.erase(ni);
                return 1;
            }
        return 0;
    }

    Node* GetNode(int i)
    {
        return nodes[i];
    }
    
public:
    vector<Node*> nodes;
};

class CCharGraph : public CGraph<char,int>
{
public:
    int TriangleCounting()
    {
        return 0;
    }

    int QuadCounting()
    {
        return 0;
    }
};
