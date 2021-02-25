from decimal import Decimal


def gcd(a, b):
    while b:
        a, b = b, a % b
    return a


def generatePvtk(p, q):
    n = p * q
    phi = (p - 1) * (q - 1)
    e = 0
    for i in range(2, phi):
        if gcd(i, phi) == 1:
            e = i
            break
    x = 1
    while True:
        x += 1
        k = (1 + (x * phi)) % (e)
        if k == 0:
            d = int((1 + (x * phi)) / (e))
            break
    return (e, n), (d, n)


def encrypt(no, pubk):
    c = Decimal(0)
    c = pow(no, pubk[0])
    ct = c % pubk[1]
    return ct


def decrypt(no, privk):
    d = Decimal(0)
    d = pow(no, privk[0])
    dt = d % privk[1]
    return dt


def stoi(st):
    ret = []
    for i in st:
        c = ord(i)
        ret.append(c)
    return ret


def iost(it):
    string = ""
    for i in it:
        string += chr(i)
    return string


pubk, pvtk = generatePvtk(397, 401)

enc = []
for i in stoi("Syed Mohammad Raza"):
    enc.append(encrypt(i, pubk))

print(pubk)
print(pvtk)

print(enc)

dec = []
for i in enc:
    dec.append(decrypt(i, pvtk))

dec = iost(dec)

print(dec)