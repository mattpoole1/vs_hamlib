#!/usr/bin env python

import socket
import sys
import time

def debug_print(*args):
    if DEBUG:
        message = ""
        for arg in args:
            message = message + str(arg)
        print message


def forward_to_controller(data):

    rig = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    rig.connect((TCP_IP, RIG_PORT))
    rig.send(data)

    rig_data = rig.recv(BUFFER_SIZE)
    rig.close()
 
    return rig_data


DEBUG = 0
TCP_IP = 'localhost' # Denotes localhost
GP_PORT = int(sys.argv[1]) #Second argument
RIG_PORT = int(sys.argv[2]) #Third



BUFFER_SIZE = 1024

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, GP_PORT))
s.listen(5)

(gp, address) = s.accept()

while 1:
    data = gp.recv(BUFFER_SIZE)
    print data
    reply_data = forward_to_controller(data)
    print "!!" + reply_data + "!!"
    gp.send(reply_data)


        
    

