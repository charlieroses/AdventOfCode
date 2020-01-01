
import math

def is_prime(n):
    sn = int(math.sqrt(n))

    for i in range(2, sn + 1):
        if n % i == 0:
            return False

    return True
    

def prime_factor(n):
    f = []

    for i in range(2, n+1):
        if is_prime(i):
            if n % i == 0:
                f.append(i)

    return f

if __name__ == "__main__":
    for i in range(20):
        print(i, ":", is_prime(i))

    print()
    for i in range(20):
        print(i, ":", prime_factor(i))
