# Code-Library

A comprehensive collection of highly optimized algorithms and data structures specifically tailored for Competitive Programming. This library is structured for quick access during contests and is compatible with a `long long` based C++ template.

## 🚀 Template Overview

The library assumes the following environment:
- **Integer Type**: `#define int long long` (all snippets use `int` as 64-bit).
- **Infinity**: `inf = 1e18 + 10`.
- **Fast I/O**: `ios::sync_with_stdio(false), cin.tie(nullptr)`.
- **Macros**: `all(x)`, `sz(x)`, `endl`.

## 📂 Directory Structure

```text
Code-Library/
├── Template/               # CP Starter and Debugger
├── Data Structures/
│   ├── DSU/                # Disjoint Set Union (Size/Rank)
│   ├── Segment Tree/       # Point & Lazy Propagation
│   └── Ordered Set (PBDS)/ # Order Statistics Tree
├── Graph/
│   ├── Connectivity/       # SCC (Kosaraju's)
│   ├── Tree/               # HLD, LCA (Binary Lifting), Prim's MST
│   ├── Shortest Path/      # Dijkstra's Algorithm
│   └── Flow Matching/      # Hopcroft-Karp Bipartite Matching
├── Math/
│   ├── Primality/          # Miller-Rabin, Sieve
│   └── Exponentiation/     # Matrix & Permutation Expo
├── Geometry/               # 2D/3D Points, Line Intersections
├── String/
│   ├── Matching/           # KMP Algorithm
│   ├── Hashing/            # Double Rolling Hash
│   └── Advanced/           # Trie, Aho-Corasick, LCS
└── Miscellaneous/          # Custom Hashes, Randomness, Fast Math
