#!/bin/python3
import math


def nonDivisibleSubset(k, s):
    # Counts remainder modulo k
    # for each element in s
    s_mod_k = [0] * k
    for el in s:
        s_mod_k[el % k] += 1
    sub_cnt = 0
    for i in range(1, math.ceil(k / 2)):
        sub_cnt += max(s_mod_k[i], s_mod_k[k - i])

    if s_mod_k[0] > 0:
        sub_cnt += 1

    if k % 2 == 0 and s_mod_k[k // 2] > 0:
        sub_cnt += 1

    return sub_cnt


if __name__ == '__main__':

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    s = list(map(int, input().rstrip().split()))

    print(nonDivisibleSubset(k, s))
