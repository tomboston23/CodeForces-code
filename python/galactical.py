def main():
    n = int(input())
    arr = []
    for i in range(n):
        arr.append(list(map(int,input().split())))
    k = int(input())
    results = []
    for _ in range(k):
        s = 0
        a,b,c = map(int, input().split())
        a-=1
        b-=1
        if c < arr[a][b]:
            arr[a][b] = c
            arr[b][a] = c
        for i in range(n-1):
            for j in range(i+1,n):
                dist = min(arr[i][j], arr[i][a] + c + arr[b][j], arr[i][b] + c + arr[a][j])
                arr[i][j] = arr[j][i] = dist
                s+= dist
        results.append(str(s))
    print(" ".join(results))

if __name__ == "__main__":
    main()
