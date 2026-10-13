#include <bits/stdc++.h>
using namespace std;

// ── Notes ────────────────────────────────────────────────────

// T: O(V+2E) S: O(V)
class DFSTraversal {
  // Adjacency List:
  // Directed   → V + E
  // Undirected → V + 2E
  // Big-O for both → O(V + E)

  // DFS:
  // Time: O(V + E)
  // Space: O(V)
  // Auxiliary: recursion stack

  // BFS:
  // Time: O(V + E)
  // Space: O(V)
  // Auxiliary: queue

  // Cycle Detection:
  // Undirected → if child is visited && child != parent → cycle
  // Directed   → if child is visited && pathVisited[child] → cycle

  // Bipartite:
  // if visited child has same color as current → not bipartite
  // otherwise color child with opposite color

  // Topological Sort:
  // Only possible for DAG (Directed Acyclic Graph)
  // DFS  → push node after processing all children -> backtracking
  // BFS → Kahn's Algorithm using indegree
  // Cycle in Kahn's → processed nodes < V

  //
};
