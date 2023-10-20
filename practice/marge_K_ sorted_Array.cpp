#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int K, N;
    cin >> K >> N;

    vector<vector<int>> arrays(K, vector<int>(N));

    // Read the K*N space-separated integers
    for (int i = 0; i < K; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> arrays[i][j];
        }
    }

    // Create a min-heap of pairs (element, array index)
    // priority_queue<pair<int, int>, vector<pair<int, int>, greater<pair<int, int>>> min_heap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

    // Initialize the heap with the first elements from each array
    for (int i = 0; i < K; i++)
    {
        min_heap.push({arrays[i][0], i});
    }

    vector<int> sorted_array;

    while (!min_heap.empty())
    {
        pair<int, int> top = min_heap.top();
        min_heap.pop();

        int element = top.first;
        int array_index = top.second;

        sorted_array.push_back(element);

        // If there are more elements in the current array, push the next element into the heap
        if (array_index < N - 1)
        {
            min_heap.push({arrays[array_index][array_index + 1], array_index});
        }
    }

    // Output the sorted array
    for (int i = 0; i < sorted_array.size(); i++)
    {
        cout << sorted_array[i] << " ";
    }

    return 0;
}
