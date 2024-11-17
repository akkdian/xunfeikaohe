def readfile(filepath):
    with open(filepath,'rb') as file:
        return file.read()
def generate_key(key_str):
    return key_str.encode('utf-8')
def xor_data(data,key):
    return bytes([b ^ key[i%len(key)]for i,b in enumerate(data)])
def write_encrypted_file(file_path, data):
    with open(file_path, 'wb') as file:
        file.write(data)
def encrypt_file(input_path, output_path, key_str):
    data = readfile(input_path)
    key = generate_key(key_str)
    encrypted_data = xor_data(data, key)
    write_encrypted_file(output_path, encrypted_data)
print('输入所需加密文件地址')
input_filepath=input()
print('输入想要将它加密到的位置')
output_filepath=input()
print('输入密钥')
key=input()
encrypt_file(input_filepath, output_filepath, key)



