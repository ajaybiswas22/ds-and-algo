/**
 * @brief Program to implement Iterative Depth First Search (DFS)
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
 * Iterative Depth First Search
 * Worst Case Time Complexity: O(V+E)
 * Type: Adjacency List
 *
 * @param V Vector representing adjacency list
 * @param current Current node
 * @param size Number of Nodes in the graph
 * @return void
 */
void dfsIterative(std::vector<std::vector<int>> &V, int current, int size)
{
    static std::vector<int> visited(size, 0);
    std::stack<int> st;

    st.push(current);       // inserted first element

    while(!st.empty())      // repeat until stack is not empty
    {
        int value = st.top();   // get top of the stack
        st.pop();

        if(!visited[value])     // print the node
        {
            std::cout<<value<<" ";
            visited[value] = true;
        }
        
        for(int i=0;i<V[value].size();i++)      // discover all adjacent nodes
        {
            if(!visited[V[value][i]])
            {
                st.push(V[value][i]);
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
    dfsIterative(v, start, size);

    return 0;
}