def is_prime(n):
    return n > 1 and all(n % i for i in range(2, int(n**0.5) + 1))
# for i in range(1,1000):
#     if is_prime(i):
#         print("The number {0} is a prime number.".format(i))


