def main():

    n,m = map(int, input().split())
    dsets = [-1]*(2*n) # for element x, x+n is its complement

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

    for _ in range(m):
        inputs = list(input().split())
        a = int(inputs[0][1:]) - 1
        b = int(inputs[4][1:]) - 1
        a_t = inputs[2]
        b_t = inputs[6]
        if a_t == "true" and b_t == "true":
            add(a,b)
        elif a_t == "true" and b_t == "false":
            add(a, b+n)
        elif a_t == "false" and b_t == "true":
            add(a, b+n)
        elif a_t == "false" and b_t == "false":
            add(a+n, b+n)

    
    for i in range(n):
        if find(i) == find(i+n):
            print("NO")
            return
    print("YES")
    

if __name__ == "__main__":
    main()