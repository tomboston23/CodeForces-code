def main():
    n,m = map(int, input().split())
    value = list(map(int,input().split()))
    fathers = list(map(int,input().split()))
    left = [-1]*n
    right = [-1] * n

    def updateSubtree(u, k):
        value[u] += k
        if left[u] != -1:
            updateSubtree(left[u], k)
        if right[u] != -1:
            updateSubtree(right[u], k)
         

    for i in range(len(fathers)):
        idx = fathers[i] - 1 #index of parent node
        parent = value[idx] #value of parent node  
        cur = value[i+1]      #value of current node
        if cur > parent:
            right[idx] = i+1
        else:
            left[idx] = i+1

    def validate(u, low, high):
        if u == -1:
            return True
        if value[u] < low or value[u] > high:
            return False
        return validate(left[u], low, value[u]) and validate(right[u], value[u], high)

    for _ in range(m):
        L = list(input().split())
        v = int(L[1])
        k = int(L[2])
        if L[0] == '-':
            k = -k
        updateSubtree(v-1, k)
        if validate(0, float('-inf'), float('inf')):
            print("YES")
        else:
            print("NO")


if __name__ == "__main__":
    main()

