def readfile(filepath):
    with open(filepath,'rb') as file:
        return file.read()
def generate_key(key_str):
    return key_str.decode('utf-8')
def xor_decrypt(ciphertext, key):
    plaintext = ''
    for i in range(len(ciphertext)):
        decrypted_char = chr(ord(ciphertext[i]) ^ ord(key[i % len(key)]))
        plaintext += decrypted_char
    return plaintext
