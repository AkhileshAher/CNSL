import socket

s = socket.socket()
s.bind(('localhost', 9998))
print("Server started, waiting for connection...")
s.listen(5)

while True:
    c, addr = s.accept()
    print("Client connected:", addr)
    
    option = int(c.recv(1024).decode())
    
    # 1. Send Message
    if option == 1:
        msg = c.recv(1024).decode()
        print("Message from the client:", msg)
    
    # 2. Calculator
    elif option == 2:
        while True:
            operation = int(c.recv(1024).decode())  # Receive operation from client
            if operation == 5:  # Exit
                break
            
            n1 = int(c.recv(1024).decode())
            n2 = int(c.recv(1024).decode())
            
            if operation == 1:
                result = n1 + n2
            elif operation == 2:
                result = n1 - n2
            elif operation == 3:
                result = n1 * n2
            elif operation == 4:
                result = n1 / n2
            
            c.send(bytes(str(result), "utf-8"))
    
    c.close()
