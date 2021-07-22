/**
 * @brief Program to find no. of islands (8-connected components)
 * @author Ajay Biswas
 *
 */
#include<iostream>
#include<vector>

/**
 * Construct adjacency list of a node
 *
 * @param V 2D vector representing map of a place (binary image)
 * @param i y axis location of the current node
 * @param j x axis location of the current
 * @return vector containing coordinates of adjacent nodes 
 */
std::vector<std::pair<int,int> > eight_connected(std::vector<std::vector<int> > V, int i, int j)
{
    std::vector<std::pair<int,int>> adj;      // stores adjacent nodes

    // getting y and x limits
    int m = V.size();
    int n = V[0].size();

    // scan in eight directions
    // N
    if(i-1 >= 0)
    {
        if(V[i-1][j] == 1)
        {
            adj.push_back(std::make_pair(i-1,j));
        }
    }

    // S
    if(i+1 < m)
    {
        if(V[i+1][j] == 1)
        {
            adj.push_back(std::make_pair(i+1,j));
        }
    }

    // W
    if(j-1 >= 0)
    {
        if(V[i][j-1] == 1)
        {
            adj.push_back(std::make_pair(i,j-1));
        }
    }

    // E
    if(j+1 < n)
    {
        if(V[i][j+1] == 1)
        {
            adj.push_back(std::make_pair(i,j+1));
        }
    }

    // NW
    if(j-1 >= 0 && i-1 >= 0)
    {
        if(V[i-1][j-1] == 1)
        {
            adj.push_back(std::make_pair(i-1,j-1));
        }
    }

    // NE
    if(j+1 < n && i-1 >= 0)
    {
        if(V[i-1][j+1] == 1)
        {
            adj.push_back(std::make_pair(i-1,j+1));
        }
    }

    // SW
    if(j-1 >= 0 && i+1 < m)
    {
        if(V[i+1][j-1] == 1)
        {
            adj.push_back(std::make_pair(i+1,j-1));
        }
    }

    // SE
    if(j+1 < n && i+1 < m)
    {
        if(V[i+1][j+1] == 1)
        {
            adj.push_back(std::make_pair(i+1,j+1));
        }
    }

    return adj;
}

/**
 * Recursive Depth First Search to search 
 * all nodes of an island (0 as water, 1 as land) 
 * 
 * Worst Case Time Complexity: O(V+E)
 * Type: Adjacency List
 *
 * @param V 2D vector representing map of a place (binary image)
 * @param visited 2D matrix representing visited and unvisited nodes
 * @param current_i y axis location of the current node
 * @param current_j x axis location of the current
 * @return void
 */
void dfs(std::vector<std::vector<int> > V, std::vector<std::vector<int> > &visited, int current_i, int current_j)
{
    visited[current_i][current_j] = 1;

    // construction of adjacency list for the current node
    std::vector<std::pair<int,int>> adj = eight_connected(V,current_i,current_j);

    // traverse all adjacent nodes
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[adj[i].first][adj[i].second]) // push unvisited node on stack
        {
            dfs(V, visited, adj[i].first,adj[i].second);
        }
    }
}

/**
 * Find number of islands present in a 2D binary image
 * (0 as water, 1 as land) 
 *
 * @param V 2D vector representing map of a place (binary image)
 * @return int Number of islands
 */
int islands(std::vector<std::vector<int> > V)
{
    int m = V.size();
    int n = V[0].size();
    int count = 0;

    std::vector<std::vector<int> > visited(m,std::vector<int>(n,0));

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(!visited[i][j] && V[i][j] == 1)
            {
                dfs(V,visited,i,j);
                count++;
            }
        }
    }
    return count;
}

// main function
int main()
{   
    // Binary image in 2D vector form
    std::vector<std::vector<int> > V = {{0,1,1,0,0},
                                        {0,1,1,0,0},
                                        {0,0,0,1,1},
                                        {0,1,0,0,0},
                                        {0,1,0,1,0}};

    std::cout<<islands(V)<<std::endl;      
    return 0;
}