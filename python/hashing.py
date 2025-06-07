def main():
    n, m, k = map(int, input().split())
    a,b = map(int, input().split())

    dsets = [-1] * n
    lengths = [0]*n

    def find(c):
        if dsets[c] < 0:
            return c
        else:
            dsets[c] = find(dsets[c])
            return dsets[c]

    def join(a,b): # this function sets a to point to b, if b is not the root then it points to b's root
        rb = find(b)
        dsets[a] = rb
        dsets[rb] -= 1

    results = []

    for i in range(k):
        x = int(input())
        entry = int((a*x+b)%n)
        idx = find(entry)
        
        lengths[idx] = lengths[idx] + 1

        if lengths[idx] >= m:
            join(idx, (idx+1)%n)
        results.append(str(idx))

    print("\n".join(results))




if __name__ == "__main__":
    main()