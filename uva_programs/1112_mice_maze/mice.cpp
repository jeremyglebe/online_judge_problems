#include <climits>
#include <iostream>
#include <queue>
#include <vector>
using std::cin;
using std::cout;
using std::priority_queue;
using std::vector;

int main()
{
    // Number of input cases
    int num_cases;
    cin >> num_cases;
    // Loop for each input case
    for (int this_case = 1; this_case <= num_cases; this_case++)
    {
        // Number of cells in the maze
        int num_cells;
        cin >> num_cells;
        // Numeric id of the exit cell
        int exit_id;
        cin >> exit_id;
        // Maximum "time" (weight) of the path from mouse to exit
        int max_time;
        cin >> max_time;
        // Number of connections (edges) between the cells (graph)
        int num_edges;
        cin >> num_edges;
        // Create an adjacency matrix representing the graph of cells and edges
        // INT_MAX represents no connection, otherwise each array slot contains the
        // weight of the edge. Indices start at 1 (as the problem uses values
        // starting at 1) and we just accept the slight wasted space.
        int **matrix = new int *[num_cells + 1];
        for (int r = 1; r <= num_cells; r++)
        {
            matrix[r] = new int[num_cells + 1];
            for (int c = 1; c <= num_cells; c++)
                matrix[r][c] = INT_MAX;
        }
        // Read in each edge and add it to the matrix
        for (int i = 0; i < num_edges; i++)
        {
            int id1, id2, weight;
            cin >> id1 >> id2 >> weight;
            matrix[id1][id2] = weight;
        }

        // We're counting the number of "mice" with paths short enough to the
        // exit.
        int num_lucky_mice = 0;

        // Determine shortest path for each "mouse" (cell)
        for (int mouse = 1; mouse <= num_cells; mouse++)
        {
            /*START OF DIJKSTRA'S ALGORITHM IMPLEMENTATION*/
            // Tracks whether each cell has been visited
            bool *visited = new bool[num_cells + 1];
            // Tracks the shortest distance to each cell
            int *d_values = new int[num_cells + 1];
            // Tracks the previous cell for each cell's shortest path
            int *p_values = new int[num_cells + 1];
            // Initialize values in each array
            for (int i = 1; i <= num_cells; i++)
            {
                visited[i] = false;
                // INT_MAX represents infinity
                d_values[i] = INT_MAX;
                // INT_MAX represents no previous item (not connected or start node)
                p_values[i] = INT_MAX;
            }
            // 0 distance from mouse to mouse
            d_values[mouse] = 0;
            // Using lambda to compare elements.
            auto cmp = [d_values](int left, int right) { return d_values[left] > d_values[right]; };
            // Queue to track which cells should be visited next
            priority_queue<int, vector<int>, decltype(cmp)> to_visit(cmp);
            // Queue up the mouse as the first node to visit
            to_visit.push(mouse);
            // Keep checking paths until we've emptied the queue of cells to visit
            while (!to_visit.empty())
            {
                // Store the current node
                int this_node = to_visit.top();
                // It's possible to accidentally queue up a node twice, so we check for that
                if (!visited[this_node])
                {
                    // Find each node which is adjacent to the current
                    for (int id = 1; id <= num_cells; id++)
                    {
                        if (matrix[this_node][id] != INT_MAX)
                        {
                            // Check if we should update adjacent's shortest path. (If
                            // our path is shorter or if the adjacent does not yet have
                            // a d value)
                            if (d_values[this_node] + matrix[this_node][id] < d_values[id])
                            {
                                d_values[id] = d_values[this_node] + matrix[this_node][id];
                                p_values[id] = this_node;
                            }
                            // Check if we should visit that neighbor
                            if (!visited[id])
                            {
                                to_visit.push(id);
                            }
                        }
                    }
                }
                // Mark the node as visited once all adjacents have been checked
                visited[this_node] = true;
                // Pop the node from the queue
                to_visit.pop();
            }
            /*END OF DIJKSTRA'S ALGORITHM IMPLEMENTATION*/
            if (d_values[exit_id] >= 0 && d_values[exit_id] <= max_time)
                num_lucky_mice++;
            // else
            // {
            //     cout << "Mouse: " << mouse << ", Distance: " << d_values[exit_id] << '\n';
            // }
        }

        // Create a blank line if this isn't the first case
        if (this_case != 1)
        {
            cout << '\n';
        }
        // Print the graph matrix
        // for (int cell = 1; cell <= num_cells; cell++)
        // {
        //     cout << "Cell: " << cell << ", Visited: " << visited[cell]
        //          << ", Distance: " << d_values[cell] << ", Prev: "
        //          << p_values[cell] << '\n';
        // }
        // Print the results
        cout << num_lucky_mice << '\n';
    }
}