/**
 * @brief Program to implement Topological Sort
 * @author Ajay Biswas
 *
 */
#include <iostream>
#include <vector>
#include <stack>

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
 * @param visited Vector representing nodes visited or not
 * @param Stack Stack to hold 
 * @param current Current node
 * @return void
 */
void dfs_topological(std::vector<std::vector<int>> &V,
                     std::vector<int> &visited,
                     std::stack<int> &Stack,
                     int current)
{
    visited[current] = 1; // current node is visited

    // traverse all adjacent nodes
    for (int i = 0; i < V[current].size(); i++)
    {
        if (!visited[V[current][i]]) // call dfs for unvisited neighbor nodes
        {
            dfs_topological(V, visited, Stack, V[current][i]);
        }
    }
    Stack.push(current); // push the current element when no unvisited neighbor
}

/**
 * Topological Sorting of a graph
 *
 * @param V Vector representing adjacency list
 * @param size Number of nodes
 * @return void
 */
void topologicalSort(std::vector<std::vector<int>> &V, int size)
{

    std::vector<int> visited(size);
    std::stack<int> Stack;

    for (int i = 0; i < size; i++)
    {
        if (!visited[i])            // explore unvisited node
        {
            dfs_topological(V, visited, Stack, i);
        }
    }

    while (!Stack.empty())          // topological order sequence
    {
        std::cout << Stack.top() << " ";
        Stack.pop();
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
    topologicalSort(v, size);

    return 0;
}