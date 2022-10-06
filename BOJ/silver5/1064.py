import sys
import math
x_a, y_a, x_b, y_b, x_c, y_c = map(float, sys.stdin.readline().split())

length_ab = math.sqrt((x_a-x_b)**2 + (y_a-y_b)**2)
length_bc = math.sqrt((x_b-x_c)**2 + (y_b-y_c)**2)
length_ca = math.sqrt((x_c-x_a)**2 + (y_c-y_a)**2)

add_ab_bc = 2 * (length_ab + length_bc)
add_bc_ca = 2 * (length_bc + length_ca)
add_ca_ab = 2 * (length_ca + length_ab)

gradient_ab = float()
if x_a == x_b:
    gradient_ab = float("inf")
else:
    gradient_ab = (y_a-y_b) / (x_a-x_b)

gradient_bc = float()
if x_b == x_c:
    gradient_bc = float("inf")
else:
    gradient_bc = (y_b-y_c) / (x_b-x_c)

result = -1.0
if gradient_ab != gradient_bc:
    result = max(add_ab_bc, add_bc_ca, add_ca_ab) - min(add_ab_bc, add_bc_ca, add_ca_ab)

print(result)