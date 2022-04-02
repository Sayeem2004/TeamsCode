# Solved By Nicholas Tarsis
from math import ceil

t, k = map(int, input().split())
ans = 0
for i in range(t):
    a, b = map(int, input().split())
    c = (a//k)*k
    d = ceil(a/k)*k
    mod = a % k
    e = (a-c)+abs(b-a//k)
    f = (d-a)+abs(b-d//k)
    ans += min(e, f)
print(ans)
