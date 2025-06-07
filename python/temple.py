def main():
    n,m,k = map(int, input().split())

    adj_list = []
    colors = [-1]*n
    
    
    for _ in range(n):
        adj_list.append([])
    for _ in range(m):
        a,b = map(int, input().split())
        a-=1
        b-=1
        adj_list[a].append(b)
        adj_list[b].append(a)

    deg = [len(adj_list[v]) for v in range(n)]
    buckets = [set() for _ in range(n)]
    for v in range(n):
        buckets[deg[v]].add(v)

    removal = []
    for _ in range(n):
        for d in range(n):
            if buckets[d]:
                v = buckets[d].pop()
                removal.append(v)
                for u in adj_list[v]:
                    if deg[u] is not None:
                        buckets[deg[u]].remove(u)
                        deg[u] -= 1
                        buckets[deg[u]].add(u)
                deg[v] = None
                break

    fail = False

    for v in reversed(removal):
        assigned = False
        used = [0]*k
        for u in adj_list[v]:
            if colors[u] >= 0:
                used[colors[u]] = 1
        for c in range(k):
            if not used[c]:
                colors[v]=c
                assigned = True
                break
        if not assigned:
            fail = True
    if fail is True:
        print(-1)
    else:
        for i in colors:
            print(i+1)


if __name__ == "__main__":
    main()


    