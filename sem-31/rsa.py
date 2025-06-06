import random
from math import gcd

def generate_keys(p, q):
    n = p * q
    phi = (p-1) * (q-1)

    e = random.randint(2, phi-1)
    while gcd(e, phi) != 1:
        e = random.randint(2, phi-1)

    d = pow(e, -1, phi)
    
    return (e, n), (d, n)

def encrypt(m, public_key):
    e, n = public_key
    return pow(m, e, n)

def decrypt(c, private_key):
    d, n = private_key
    return pow(c, d, n)

p, q = 61, 53
public_key, private_key = generate_keys(p, q)
m = 123

c = encrypt(m, public_key)
decrypted = decrypt(c, private_key)

print(f"Открытый ключ: {public_key}")
print(f"Секретный ключ: {private_key}")
print(f"Шифровка: {c}")
print(f"Расшифровка: {decrypted}")
