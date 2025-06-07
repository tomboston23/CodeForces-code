def fib(n):
    dp = [0]*(n+1)
    for i in range(n+1):
        if i <= 1:
            dp[i] = i
        else:
            dp[i] = dp[i-1]+dp[i-2]
    for i in range(n+1):
        print(dp[i])
    
    return dp[n]
    
a = int(input())
fib(a)
