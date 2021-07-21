/**
 * @brief Program to implement Breadth First Search (BFS)
 * @author Ajay Biswas
 *
 */
#include <iostream>
#include <vector>
#include <queue>

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
 * Recursive Breadth First Search
 * Worst Case Time Complexity: O(V+E)
 * Type: Adjacency List
 *
 * @param V Vector representing adjacency list
 * @param queue Queue holding nodes
 * @param size Number of Nodes in the graph
 * @return void
 */
void bfs(std::vector<std::vector<int>> &V, std::queue<int> &queue, int size)
{
    static std::vector<int> visited(size, 0);

    if (queue.empty()) // stop process if queue is empty
    {
        return;
    }

    int value = queue.front(); // current node
    queue.pop();

    visited[value] = 1; // current node is visited
    std::cout << value << " ";

    for (int i = 0; i < V[value].size(); i++) // push all adjacent nodes in the queue
    {
        if (!visited[V[value][i]])
        {
            visited[V[value][i]] = 1;
            queue.push(V[value][i]);
        }
    }

    bfs(V, queue, size); // call bfs
}

int main()
{
    int start = 0;
    int size = 5;
    std::vector<std::vector<int>> v(size);
    std::queue<int> queue;

    insert(v, 0, 1);
    insert(v, 0, 2);
    insert(v, 1, 3);
    insert(v, 1, 4);
    insert(v, 1, 0);
    insert(v, 2, 0);
    insert(v, 3, 1);
    insert(v, 4, 1);

    queue.push(start); // Initialize queue with start node
    bfs(v, queue, size);

    return 0;
}