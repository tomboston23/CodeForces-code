

def main():
    a,b = map(int, input().split())
    dsets = [-1]*(a+1)

    def find(c):
        if dsets[c] < 0:
            return c
        else:
            dsets[c] = find(dsets[c])
            return dsets[c]

    def add(c1,c2):
        sa = find(c1)
        sb = find(c2)
        if sa == sb:
            return sa
        if dsets[sa] > dsets[sb]:
            dsets[sb] += dsets[sa]
            dsets[sa] = sb
        else:
            dsets[sa] += dsets[sb]
            dsets[sb] = sa

    for _ in range(b):
        l = list(input().split())
        if l[0] == "Union":
            add(int(l[1]), int(l[2]))
        else:
            print(-dsets[find(int(l[1]))])

if __name__ == "__main__":
    main()