t = int(input())

while(t > 0):
    t -= 1
    S = input()
    T = input()
    n = len(S)
    m = len(T)
    dp = [0] * (m + 1)

    dp[0] = 1
    
    for i in range(1, n + 1):
        for j in range(m, 0, -1):
            if S[i - 1] == T[j - 1]:
                dp[j] = dp[j] + dp[j - 1]

    print(dp[m])