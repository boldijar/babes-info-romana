/*
 * FluxMax.cpp
 *
 *  Created on: May 27, 2014
 *      Author: Melinda
 */
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
#include <assert.h>
using namespace std;
#define V 8
int maxflux = 0;
//Returneaza true daca exista drum de la sursa la destinatie si nodurile continute
bool bfs(int rGraph[V][V], int s, int t, int parent[])
	{
	//Creeaza un vector de noduri vizitate si le marcheaza pe toate ca nevizitate
	bool visited[V];
	memset(visited, 0, sizeof(visited));
	queue <int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;
	    while (!q.empty())
	    {
	        int u = q.front();
	        q.pop();
	        for (int v=0; v<V; v++)
	        {
	            if (visited[v]==false && rGraph[u][v] > 0)
	            {
	                q.push(v);
	                parent[v] = u;
	                visited[v] = true;
	            }
	        }
	    }
	    return (visited[t] == true); // daca am gasit drum de la s la t
	}

	//Returneaza fluxul maxim de la s la t din graf
	int fordFulkerson(int graph[V][V], int s, int t)
	{
	    int u, v;
	    int rGraph[V][V];
	    for (u = 0; u < V; u++)
	        for (v = 0; v < V; v++)
	             rGraph[u][v] = graph[u][v];
	    int parent[V];
	    while (bfs(rGraph, s, t, parent))
	    {
	        int pathflux = INT_MAX;
	        for (v=t; v!=s; v=parent[v])
	        {
	            u = parent[v];
	            pathflux = min(pathflux, rGraph[u][v]);
	        }
	        for (v=t; v != s; v=parent[v])
	        {
	            u = parent[v];
	            rGraph[u][v] -= pathflux;
	            rGraph[v][u] += pathflux;
	        }
	        maxflux += pathflux;
	    }
	    return maxflux;
	}
int main()
{
	int graph[V][V] = { {0,10, 6, 10, 0, 0, 0, 0},
	                	{0, 0, 5, 0, 5, 0, 0, 0},
	                	{0, 0, 0, 5, 0, 15,0, 0},
	                	{0, 0, 0, 0, 0, 2, 7, 0},
	                	{0, 0, 0, 0, 0, 0, 0, 15},
	                	{0, 0, 0, 0, 0, 0, 4, 8},
	                	{0, 0, 0, 0, 0, 0, 0, 12},
	                	{0, 0, 0, 0, 0, 0, 0, 0}
                  	  };
	cout << "Fluxul maxim este: " << fordFulkerson(graph, 0, 7);
	assert (maxflux == 24);
	return 0;
}
