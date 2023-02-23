from bisect import bisect_left

N = int(input())
arr = [0] + list(map(int,input().split()))
main_branch = [-float('inf')]
dp = [0]*(N+1)

for i in range(1,N+1):
if(arr[i] > main_branch[-1]):
        main_branch.append(arr[i])
        dp[i] = len(main_branch)-1
    else:
        dp[i] = bisect_left(main_branch, arr[i])
        main_branch[dp[i]] = arr[i]
        
max_dp = max(dp)
print(max_dp)
ans = []
for i in range(N,0,-1):
    if(max_dp == dp[i]):
        ans.append(arr[i])
        max_dp = max_dp-1
        
print(*ans[::-1])
