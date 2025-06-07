def main():
    n,m,k = map(int, input().split())
    roads = []
    eqs = []
    count = n

    rem = set()

    def find(c):
        if dsets[c] < 0:
            return c
        else:
            dsets[c] = find(dsets[c])
            return dsets[c]

    def add(c1,c2, count):
        sa = find(c1)
        sb = find(c2)
        if sa == sb:
            return count
        if dsets[sa] > dsets[sb]:
            dsets[sb] += dsets[sa]
            dsets[sa] = sb
        else:
            dsets[sa] += dsets[sb]
            dsets[sb] = sa
        return count - 1

    for _ in range(m):
        a,b = map(int, input().split())
        roads.append([min(a,b),max(a,b)])
    for _ in range(k):
        a,b = map(int, input().split())
        rem.add((min(a,b), max(a,b)))
        eqs.append([min(a,b),max(a,b)])
    rets = []
    dsets = [-1]*(n+1)
    for r in roads:
        if (r[0],r[1]) not in rem:
            count = add(r[0],r[1], count)

    for e in reversed(eqs):
        rets.append([-dsets[find(1)], count])
        count = add(e[0],e[1], count)
        


    l = len(rets)
    for i in reversed(range(l)):
        print(rets[i][0],rets[i][1])



if __name__ == "__main__":
    main()