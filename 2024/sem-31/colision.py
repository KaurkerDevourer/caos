import random
import string

# hash = (hash * p + str[i]) % mod

def simple_hash(s, p, mod):
    h = 0
    min_char = ord('a')
    for c in s:
        h = (h * p + ord(c) - min_char) % mod
    return h


def random_string(length=10):
    return ''.join(random.choices(string.ascii_letters, k=length))

def find_collision(p=257, mod=int(1e9 + 7), max_tries=100000):
    print(f"p = {p}, mod = {mod}")
    seen = {}
    for i in range(max_tries):
        s = random_string()
        h = simple_hash(s, p, mod)
        if h in seen:
            print(f"Коллизия найдена:")
            print(f"Строка 1: {seen[h]}, хеш: {h}")
            print(f"Строка 2: {s}, хеш: {h}")
            print(f"Попыток было: {i}")
            return (seen[h], s)
        seen[h] = s
    print("Коллизия не найдена (увеличьте max_tries)")
    return None

collision = find_collision()
