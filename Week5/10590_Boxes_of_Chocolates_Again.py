N = 5010
dp = [0] * N

def init():
    dp[0] = 1

    for i in range(1, N):
        for j in range(i, N):
            dp[j] += dp[j - i]

init()
while(True):
    try:
        n = int(input())
        print(dp[n])
    except:
        break