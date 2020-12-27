import math
# Handle input
first_line_in = input().rstrip().split()
n = int(first_line_in[0])
k = int(first_line_in[1])
S = list(map(int, input().rstrip().split()))

# Counts of each remainder modulo k
# for elements in S
S_mod_k = [0] * k

for el in S:
    S_mod_k[el % k] += 1

# print("S:", S)
# print("Mod k counts:", S_mod_k)

sub_cnt = 0
for i in range(1, math.ceil(k / 2)):
    sub_cnt += max(S_mod_k[i], S_mod_k[k-i])

if S_mod_k[0] > 0:
    sub_cnt += 1

if k % 2 == 0 and S_mod_k[k//2] > 0:
    sub_cnt += 1

print("Result:", sub_cnt)