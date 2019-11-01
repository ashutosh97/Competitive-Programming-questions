import socket
import subprocess
import sys
from datetime import datetime

subprocess.call('cls', shell=True)

# ask for input

remoteServer = raw_input("Enter a remort host to scan: ")
remoteServerIP = socket.gethostbyname(remoteServer)

print ("-"*60)
print ("Please wait, scanning remote host", remoteServer)
print ("-"*60)

#check when time began
t1=datetime.now()

#try
try:
    for port in range(1,1025):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        result = sock.connect_ex((remoteServerIP,port))
        if result ==0:
            print("Port {}: Open").format(port)
        sock.close()

except KeyboardInterrupt:
    print("You pressed Ctrl + C")
    sys.exit()

except socket.gaierror:
    print("Hostname could not be resolved.")
    sys.exit()

except socket.error:
    print(" Couldnt connect to server")

t2= datetime.now()

total = t2-t1

print (" scan completed in ", total)



