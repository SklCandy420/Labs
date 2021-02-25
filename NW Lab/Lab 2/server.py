import socket

server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server.bind((socket.gethostname(), 1234))

server.listen(5)

clientsocket, address = server.accept()
print(f"Connection from {address} has been established.")

while True:
    mssg = clientsocket.recv(8)
    if mssg:
        print(f'The message from client  is {mssg.decode("utf-8")} ')
