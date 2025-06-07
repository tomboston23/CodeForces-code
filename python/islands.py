

def numIslands(grid):
    #find a point with a 1
    h = len(grid)
    w = len(grid[0])
    q = []
    ct = 0
    for i in range(h):
        if 'L' not in grid[i]:
            continue
        for j in range(w):
            if grid[i][j] == 'L':
                q.append([i,j])
                grid[i][j] = 'O'
                ct += 1
                while len(q) > 0:
                    p = q.pop(0)
                    if p[0] > 0 and grid[p[0]-1][p[1]] == 'L':#go left
                        q.append([p[0]-1,p[1]])
                        grid[p[0]-1][p[1]] = 'O'
                    if p[0]+1 < h and grid[p[0]+1][p[1]] == 'L':
                        q.append([p[0]+1,p[1]])
                        grid[p[0]+1][p[1]] = 'O'
                    if p[1] > 0 and grid[p[0]][p[1]-1] == 'L':
                        q.append([p[0], p[1]-1])
                        grid[p[0]][p[1]-1] = 'O'
                    if p[1] < w-1 and grid[p[0]][p[1]+1] == 'L':
                        q.append([p[0],p[1]+1])
                        grid[p[0]][p[1]+1] = 'O'
    return ct 

        
def main():
    a,b = map(int, input().split())
    grid = []
    for _ in range(a):
        inputs = list(input().strip())
        grid.append(inputs)
    print(max(numIslands(grid)-1,0))
    


if __name__ == "__main__":
    main()