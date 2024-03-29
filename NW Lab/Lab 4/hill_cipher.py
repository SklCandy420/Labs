import numpy as np

CIPHER = ""


def encrypt(mssg):
    mssg = mssg.replace(" ", "")
    C = make_key()
    len_check = len(mssg) % 2 == 0
    if not len_check:
        mssg += "0"
    P = create_matrix_of_integers_from_string(mssg)
    mssg_len = int(len(mssg) / 2)
    encrypted_mssg = ""
    for i in range(mssg_len):
        row_0 = P[0][i] * C[0][0] + P[1][i] * C[0][1]
        integer = int(row_0 % 26 + 65)
        encrypted_mssg += chr(integer)
        row_1 = P[0][i] * C[1][0] + P[1][i] * C[1][1]
        integer = int(row_1 % 26 + 65)
        encrypted_mssg += chr(integer)
    return encrypted_mssg


def decrypt(encrypted_mssg, odd):
    C = make_key()
    determinant = C[0][0] * C[1][1] - C[0][1] * C[1][0]
    determinant = determinant % 26
    multiplicative_inverse = find_multiplicative_inverse(determinant)
    C_inverse = C
    C_inverse[0][0], C_inverse[1][1] = C_inverse[1, 1], C_inverse[0, 0]
    C[0][1] *= -1
    C[1][0] *= -1
    for row in range(2):
        for column in range(2):
            C_inverse[row][column] *= multiplicative_inverse
            C_inverse[row][column] = C_inverse[row][column] % 26

    P = create_matrix_of_integers_from_string(encrypted_mssg)
    mssg_len = int(len(encrypted_mssg) / 2)
    decrypted_mssg = ""
    for i in range(mssg_len):
        column_0 = P[0][i] * C_inverse[0][0] + P[1][i] * C_inverse[0][1]
        integer = int(column_0 % 26 + 65)
        decrypted_mssg += chr(integer)
        column_1 = P[0][i] * C_inverse[1][0] + P[1][i] * C_inverse[1][1]
        integer = int(column_1 % 26 + 65)
        decrypted_mssg += chr(integer)
    if odd:
        decrypted_mssg = decrypted_mssg[:-1]
    return decrypted_mssg


def find_multiplicative_inverse(determinant):
    multiplicative_inverse = -1
    for i in range(26):
        inverse = determinant * i
        if inverse % 26 == 1:
            multiplicative_inverse = i
            break
    return multiplicative_inverse


def make_key():
    determinant = 0
    C = None
    while True:
        cipher = CIPHER
        C = create_matrix_of_integers_from_string(cipher)
        determinant = C[0][0] * C[1][1] - C[0][1] * C[1][0]
        determinant = determinant % 26
        inverse_element = find_multiplicative_inverse(determinant)
        if inverse_element == -1:
            print("Determinant is not invertible")
        elif np.amax(C) > 26 and np.amin(C) < 0:
            print("Only a-z characters are accepted")
            print(np.amax(C), np.amin(C))
        else:
            break
    return C


def create_matrix_of_integers_from_string(string):
    integers = [chr_to_int(c) for c in string]
    length = len(integers)
    M = np.zeros((2, int(length / 2)), dtype=np.int32)
    iterator = 0
    for column in range(int(length / 2)):
        for row in range(2):
            M[row][column] = integers[iterator]
            iterator += 1
    return M


def chr_to_int(char):
    char = char.upper()
    integer = ord(char) - 65
    return integer


if __name__ == "__main__":
    mssg = input("Message: ")
    mssg = mssg.split()
    CIPHER = input("Enter Cipher : ")
    encrypted_mssg = []
    oddlen = []
    for i in mssg:
        encrypted_mssg.append(encrypt(i))
        oddlen.append(len(i) % 2)
    print(" ".join(encrypted_mssg))
    decrypted_mssg = []
    for i in range(len(encrypted_mssg)):
        decrypted_mssg.append(decrypt(encrypted_mssg[i], oddlen[i]).lower())
    print(" ".join(decrypted_mssg))