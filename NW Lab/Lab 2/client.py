import socket 
s = socket.socket()  
import socket

client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client.connect((socket.gethostname(), 1234))

while True:
    mssg = input("Share Your Message: ")
    client.send(bytes(mssg, 'utf-8'))
