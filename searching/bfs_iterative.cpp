/**
 * @brief Program to implement Iterative Breadth First Search
 * @author Ajay Biswas
 *
 */
#include <iostream>
#include <vector>
#include <list>

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
 * Iterative Breadth First Search
 * 
 * Worst Case Time Complexity: O(V+E)
 * Type: Adjacency List
 *
 * @param V Vector representing adjacency list
 * @param current Current node
 * @param size Number of Nodes in the graph
 * @return void
 */
void bfs_iterative(std::vector<std::vector<int>> &V, int current, int size)
{
    static std::vector<int> visited(size, 0);
    std::list<int> queue;               // bfs requires queue data structure

    queue.push_back(current);
    visited[current] = 1; // current node is visited

    while (!queue.empty()) // repeat until queue is not empty
    {
        int value = queue.front(); // current node
        queue.pop_front();

        std::cout << value << " ";

        for (int i = 0; i < V[value].size(); i++)
        {
            if (!visited[V[value][i]]) // push unvisited node in queue
            {
                queue.push_back(V[value][i]);
                visited[V[value][i]] = 1; // mark node visited
            }
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
    bfs_iterative(v, start, size);

    return 0;
}