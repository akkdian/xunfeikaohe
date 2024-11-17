import socket

def start_server(host='localhost', port=8000):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as server_socket:
        # 绑定套接字到指定的地址和端口
        server_socket.bind((host, port))
        # 开始监听传入连接
        server_socket.listen(1)
        print(f"Server listening on {host}:{port}")

        while True:
            # 接受客户端连接
            client_socket, client_address = server_socket.accept()
            with client_socket:
                print(f"Connection from {client_address} has been established")
                while True:
                    # 接收数据，最大字节数为 1024
                    data = client_socket.recv(1024)
                    if not data:
                        # 如果没有接收到数据，则表示客户端已关闭连接
                        break
                    # 回显接收到的数据
                    client_socket.sendall(data)
                    print(f"data is {data}")

if __name__ == "__main__":
    start_server()