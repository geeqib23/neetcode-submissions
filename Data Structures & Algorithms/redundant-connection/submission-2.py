from typing import List

class DSU:
    def __init__(self, n: int):
        # 1-indexed: sz is size of component, par[i] is parent of i
        self.sz = [1] * (n + 1)
        self.par = list(range(n + 1))

    def find(self, i: int) -> int:
        if i == self.par[i]:
            return i
        self.par[i] = self.find(self.par[i])  # Path compression
        return self.par[i]

    def union(self, i: int, j: int) -> bool:
        root_i = self.find(i)
        root_j = self.find(j)
        
        if root_i == root_j:
            return True  # A cycle is detected
        
        # Union by size
        if self.sz[root_i] < self.sz[root_j]:
            root_i, root_j = root_j, root_i
            
        self.sz[root_i] += self.sz[root_j]
        self.par[root_j] = root_i
        return False


class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        n = len(edges)
        dsu = DSU(n)
        
        # In Python, you can unpack pairs directly: for u, v in edges
        for u, v in edges:
            if dsu.union(u, v):
                return [u, v]
                
        return []