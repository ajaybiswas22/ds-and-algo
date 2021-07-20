/**
 * @brief Program to implement Depth First Search (DFS)
 * @author Ajay Biswas
 *
 */
#include <iostream>
#include <vector>

/**
 * Making adjacency list by adding adjacent elements
 *
 * @param V Vector representing adjacency list
 * @param a Current node
 * @param b Node to be added in the adjacency list
 * @return void
 */
void insert(std::vector<std::vector<int>> &V, int a, int b)
{
    V[a].push_back(b); // directed graph
}

/**
 * Recursive Depth First Search
 * Worst Case Time Complexity: O(V+E)
 * Type: Adjacency List
 *
 * @param V Vector representing adjacency list
 * @param current Current node
 * @param size Number of Nodes in the graph
 * @return void
 */
void dfs(std::vector<std::vector<int>> &V, int current, int size)
{
    static std::vector<int> visited(size, 0);

    visited[current] = 1; // current node is visited
    std::cout << current << " ";

    // traverse all adjacent nodes
    for (int i = 0; i < V[current].size(); i++)
    {
        if (!visited[V[current][i]]) // push unvisited node on stack
        {
            dfs(V, V[current][i], size);
        }
    }
}

int main()
{
    int start = 0;
    int size = 5;
    std::vector<std::vector<int>> v(size);
    insert(v, 0, 1);
    insert(v, 0, 2);
    insert(v, 1, 3);
    insert(v, 1, 4);
    insert(v, 1, 0);
    insert(v, 2, 0);
    insert(v, 3, 1);
    insert(v, 4, 1);
    dfs(v, start, size);

    return 0;
}