import socket

c = socket.socket()
c.connect(('localhost', 9998))

print("1. Send a Message")
print("2. Calculator")
choice = int(input("Enter your choice: "))
c.send(str(choice).encode())

# 1. Send Message
if choice == 1:
    msg = input("Enter the message to send: ")
    c.send(bytes(msg, 'utf-8'))
    print("Message sent to the server.")

# 2. Calculator
elif choice == 2:
    while True:
        print("\n*******Menu*******")
        print("1. Addition")
        print("2. Subtraction")
        print("3. Multiplication")
        print("4. Division")
        print("5. Exit")
        operation = int(input("Enter choice: "))
        c.send(str(operation).encode())
        
        if operation == 5:
            break
        
        n1 = int(input("Enter first number: "))
        n2 = int(input("Enter second number: "))
        
        c.send(str(n1).encode())
        c.send(str(n2).encode())
        
        result = c.recv(1024).decode()
        print("Result:", result)

c.close()
