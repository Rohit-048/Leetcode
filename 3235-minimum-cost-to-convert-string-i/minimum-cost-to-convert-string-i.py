class Solution(object):
    def minimumCost(self, source, target, original, changed, cost):
        """
        :type source: str
        :type target: str
        :type original: List[str]
        :type changed: List[str]
        :type cost: List[int]
        :rtype: int
        """
        import sys
        from collections import defaultdict

        n = len(source)
        
        # Initialize the cost matrix
        INF = float('inf')
        cost_matrix = [[INF] * 26 for _ in range(26)]
        
        # Set cost to 0 for transforming a character to itself
        for i in range(26):
            cost_matrix[i][i] = 0
        
        # Fill the cost matrix with the given transformations
        for o, c, z in zip(original, changed, cost):
            cost_matrix[ord(o) - ord('a')][ord(c) - ord('a')] = min(cost_matrix[ord(o) - ord('a')][ord(c) - ord('a')], z)
        
        # Apply Floyd-Warshall algorithm to find the shortest paths between all pairs of nodes
        for k in range(26):
            for i in range(26):
                for j in range(26):
                    if cost_matrix[i][k] < INF and cost_matrix[k][j] < INF:
                        cost_matrix[i][j] = min(cost_matrix[i][j], cost_matrix[i][k] + cost_matrix[k][j])
        
        # Calculate the minimum cost to transform the source to the target
        total_cost = 0
        for i in range(n):
            s_char = source[i]
            t_char = target[i]
            s_idx = ord(s_char) - ord('a')
            t_idx = ord(t_char) - ord('a')
            if cost_matrix[s_idx][t_idx] == INF:
                return -1
            total_cost += cost_matrix[s_idx][t_idx]
        
        return total_cost