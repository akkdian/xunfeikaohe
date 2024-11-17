
import socket

def start_client(host='localhost', port=8000, message='haha'):
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as client_socket:
        client_socket.connect((host, port))
        client_socket.send(message.encode())
        data = client_socket.recv(1024)
        print(f"Received from server: {data.decode()}")

if __name__ == "__main__":
    start_client()