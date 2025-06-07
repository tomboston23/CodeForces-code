def main():
    n = int(input())
    arr = []
    for i in range(n):
        arr.append(list(map(int,input().split())))
        for j in range(n):
            if i != j and arr[i][j] == 0:
                arr[i][j] = float('inf')

    for k in range(n):
        for i in range(n):
            for j in range(n):
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j])

    for i in range(n):
        for j in range(n):
            if i == j:
                continue
            if arr[i][j] == float('inf'):
                arr[i][j] = -1
    
    for row in arr:
        print(" ".join(map(str, row)))


if __name__ == "__main__":
    main()
