import socket
import os

UDP_IP = "127.0.0.1"  # Server IP address
UDP_PORT = 5005       # Server port
buffer_size = 1024    # Size of the UDP packets to send

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# Select the file to send
file_name = input("Enter the name of the file to send: ")

if not os.path.exists(file_name):
    print("File does not exist!")
else:
    # Send the file name to the server
    sock.sendto(file_name.encode(), (UDP_IP, UDP_PORT))

    # Open the file in read-binary mode and start sending
    with open(file_name, 'rb') as f:
        while True:
            data = f.read(buffer_size)  # Read the file in chunks
            if not data:
                break  # End of file reached
            sock.sendto(data, (UDP_IP, UDP_PORT))

    print(f"File {file_name} sent successfully!")

sock.close()
