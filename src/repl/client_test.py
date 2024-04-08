import logging
import socket 

logging.basicConfig(level=logging.INFO)


def main(host, port):
    logging.info("Start client TCP server")
    
    while True:
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((host, port))
        
        send_data: str = input("Enter data: ")
        client_socket.sendall(bytes(send_data, "utf-8"))
        
        if data := client_socket.recv(1024):
            print(f"Recieved: {repr(data)}")    
    
        client_socket.close()
        

if __name__ == "__main__":
    main(host="127.0.0.1", port=1234)
