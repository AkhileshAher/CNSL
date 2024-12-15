import socket
import select

# Server configuration
UDP_IP = "127.0.0.1"
IN_PORT = 5005
timeout = 3

# Create a UDP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, IN_PORT))

print(f"Server is listening on {UDP_IP}:{IN_PORT}...")

while True:
    # Receive the file name from the client
    data, addr = sock.recvfrom(1024)
    if data:
        print("File name received:", data.decode())
        file_name = data.strip().decode()  # Convert bytes to string
        f = open(file_name, 'wb')  # Open the file in write-binary mode

        # Receiving the file data in chunks
        while True:
            ready = select.select([sock], [], [], timeout)  # Wait for data with a timeout
            if ready[0]:
                data, addr = sock.recvfrom(1024)
                f.write(data)  # Write the received data to the file
            else:
                print(f"{file_name} transfer finished!")
                f.close()  # Close the file when finished
                break
