#include <iostream>

#include <vector> #include <string> using namespace std; #define V 6 #define INF 99999 string locationNames[V] = {"Main Gate", "Academic Block", "Library", "Hostel", "Cafeteria",
"Admin Office"}; int minDistance(int
dist[], bool visited[]) { int min = INF, min_index; for (int v = 0; v < V; v++) if (!visited[v] && dist[v] <= min)
min = dist[v], min_index = v; return min_index;
} void dijkstra(int graph[V][V], int src) { int dist[V]; bool visited[V];
for (int i = 0; i < V; i++) dist[i] = INF, visited[i] = false; dist[src] = 0; for (int count = 0; count < V - 1; count++) { int u = minDistance(dist, visited);
visited[u] = true; for (int v = 0; v < V; v++) if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) dist[v] = dist[u] + graph[u][v];

}
cout << "\nShortest distances from " << locationNames[src] << ":\n"; for (int i = 0; i < V; i++)
cout << locationNames[src] << " -> " << locationNames[i] << " = " << dist[i] << " meters\n";
}
int main() { int graph[V][V] = {
{0, 100, 300, 500, 200, 400}, {100, 0, 250, 400, 150, 300}, {300, 250, 0, 450, 350, 500}, {500, 400, 450, 0, 100, 250}, {200, 150, 350, 100, 0, 200},
{400, 300, 500, 250, 200, 0} };
int choice; do { cout << "\nCampus Navigation System - Chandigarh University"; cout << "\n1. View Locations";
cout << "\n2. Find Shortest Path"; cout << "\n3. Exit"; cout << "\nEnter your choice: "; cin >> choice;

switch (choice) { case 1:
cout << "\nAvailable Locations:\n"; for (int i = 0; i < V; i++) cout << i << ". " << locationNames[i] << endl; break; case 2: { int src, dest; cout << "\nEnter source location number: "; cin >> src; cout << "Enter destination location number: "; cin >> dest;
if (src >= 0 && src < V && dest >= 0 && dest < V) { dijkstra(graph, src);
} else { cout << "\nInvalid location selection.\n";
} break; }
case 3:
cout << "\nExiting the system.\n";
break; default:
cout << "\nInvalid choice. Try again.\n";
}
} while (choice != 3);

return 0; }