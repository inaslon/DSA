import heapq

class Solution:
    def shortestPath(self, n, edges, labels, k):

        adj = [[] for _ in range(n)]

        for u, v, w in edges:
            adj[u].append((v, w))

        dis = [[float('inf')] * (k + 1) for _ in range(n)]

        pq = []

        heapq.heappush(pq, (0, 0, 1))

        dis[0][1] = 0

        while pq:

            d, u, consecutive = heapq.heappop(pq)

            if d > dis[u][consecutive]:
                continue

            if u == n - 1:
                return d

            for v, w in adj[u]:

                if labels[u] == labels[v]:
                    newconsecutive = consecutive + 1
                else:
                    newconsecutive = 1

                if (newconsecutive <= k and
                    dis[v][newconsecutive] > d + w):

                    dis[v][newconsecutive] = d + w

                    heapq.heappush(
                        pq, (d + w, v, newconsecutive)
                    )

        return -1