import math

def solve():

    n = int(input())

    lc1 = 0
    qc1 = 0
    sc1 = 0
    lgc1 = 0
    c=0
    
    for _ in range(n):
        inputs = list(input().split())
        typ = inputs[0]
        if typ == "1":
            lc1 += float(inputs[1])
            c += float(inputs[2])

        elif typ == "2":
            
            qc1+= float(inputs[1])
            lc1 += float(inputs[2])
            c += float(inputs[3])

        elif typ == "sqrt":
            
            sc1 += math.sqrt(float(inputs[1]))
            c += float(inputs[2])

        elif typ == "log":

            lgc1 += float(inputs[1])
            c += float(inputs[2])

    def E(t):

        t_val = float(t)
        total = c

        total += float(lc1*t_val)

        total += float(qc1*t_val*t_val)

        total += float(sc1 * math.sqrt(t_val))
        
        if lgc1 > 0:
            if t == 0:
                lg = float('-inf')
            else:
                lg = float(lgc1*math.log(t_val))
            total += lg

        return total

    low = 0
    high = 43200

    while high - low > 5:
        mid1 = int(low + (high - low) // 3)
        mid2 = int(high - (high - low) // 3)

        if E(mid1) < E(mid2):
            low = mid1
        else:
            high = mid2

    best = -float("inf")
    for t in range(low, high+1):
        val = E(t)
        if val > best:
            best = val

    print(best)


if __name__ == '__main__':
    solve()
