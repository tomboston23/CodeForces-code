def main():
    p = list(map(int, input().split()))
    n = p[0]
    q = p[1]
    l = p[2]

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

    count = 0

    dsets = [0]*(n+1)
    hairs = list(map(int, input().split()))
    for i in range(n):
        if hairs[i] > l:
            if dsets[i+1] == 0:
                dsets[i+1] = -1
            if i > 0 and dsets[i] != 0:
                add(i+1,i)
            else:
                count += 1

    for _ in range(q):
        p_i = list(map(int, input().split()))
        if p_i[0] == 0:
            print(count)
        else:
            idx = p_i[1]
            hairs[idx-1] += p_i[2]
            if hairs[idx-1] > l:
                dsets[idx] = -1
                if dsets[idx-1] != 0 and idx < n and dsets[idx+1] != 0:
                    add(idx, idx-1)
                    add(idx, idx+1)
                    count -=1
                elif dsets[idx-1] != 0:
                    add(idx, idx-1)
                elif idx < n and dsets[idx+1] != 0:
                    add(idx, idx+1)
                else:
                    count += 1
                    
                

if __name__ == "__main__":
    main()