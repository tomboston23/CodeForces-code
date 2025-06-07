def main():
    n = int(input())
    a, b = map(int, input().split())
    if solve(a,b,n):
        print("YES")
    else:
        print("NO")
            

def solve(a,b,n):
    delta = 1
    high = 1 
    low = 0
    for i in range(n):
        delta = delta/3
        mid1 = low+delta
        mid2 = high-delta
        if a < mid2*b and a > mid1*b:
            return 0
        elif a > mid2*b:
            low = mid2
        elif a < mid1*b:
            high = mid1
        else:
            return 1
    return 1

if __name__ == "__main__":
    main()