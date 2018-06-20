#!/usr/bin env python

import socket
import sys
import time
import serial

def debug_print(*args):
    if DEBUG:
        message = ""
        for arg in args:
            message = message + str(arg)
        print message

def direct_to_unit(data):
    debug_print("[AZ_SERIAL]: Connecting directly to the serial port\n")
    az_serial = serial.Serial(AZ_SERIAL, BAUD, timeout=1)
    debug_print("[AZ_SERIAL]: Direct serial link to Azimuth control is open\n")
    az_serial.write(data.encode('utf-8'))
    debug_print("[AZ_SERIAL]: Data written to Azimuth serial port\n")
    az_serial.close()
    debug_print("[AZ_SERIAL]: Serial port closed\n")
    debug_print("[EL_SERIAL]: Connecting Directly to the serial port\n")
    el_serial = serial.Serial(EL_SERIAL, BAUD, timeout=1)
    debug_print("[EL_SERIAL]: Direct serial link to Elevation control is open\n")
    el_serial.write(data.encode('utf-8'))
    debug_print("[EL_SERIAL]: Data written to Elevation serial port\n")
    el_serial.close()
    debug_print("[EL_SERIAL]: Serial port closed\n")

def forward_to_controller(data):
    debug_print("[AZ_CLIENT]: Connecting to Azimuth TCP Server at ", TCP_IP, " on port ", AZ_PORT, "...\n")
    az = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    el = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    az.connect((TCP_IP, AZ_PORT))
    debug_print("[AZ_CLIENT]: Connection established.\n")
    debug_print("[AZ_CLIENT]: Forwarding data...\n")
    az.send(data)
    debug_print("[AZ_CLIENT]: Data sent.\n")
    debug_print("[AZ_CLIENT]: Receiving response...\n")
    az_data = az.recv(BUFFER_SIZE)
    debug_print("[AZ_CLIENT]: Response received.\n")
    debug_print("[AZ_CLIENT]: Closing connection...\n")
    az.close()
    debug_print("[AZ_CLIENT]: Connection closed\n")  
    debug_print("[EL_CLIENT]: Connecting to Elevation TCP Server at", TCP_IP, "on port", EL_PORT, "...\n")    
    el.connect((TCP_IP, EL_PORT))
    debug_print("[EL_CLIENT]: Connection established.\n")
    debug_print("[EL_CLIENT]: Forwarding data...\n")
    el.send(data)
    debug_print("[EL_CLIENT]: Data sent.\n")
    debug_print("[EL_CLIENT]: Receiving response...\n")
    el_data = el.recv(BUFFER_SIZE) 
    debug_print("[EL_CLIENT]: Response received.\n")
    debug_print("[EL_CLIENT]: Closing connection...\n")
    el.close()
    debug_print("[EL_CLIENT]: Connection closed\n")  
    return (az_data, el_data)


DEBUG = 1
TCP_IP = 'localhost' # Denotes localhost
GP_PORT = int(sys.argv[1]) #Second argument
AZ_PORT = int(sys.argv[2]) #Third
EL_PORT = int(sys.argv[3]) #Fourth
AZ_SERIAL = "/dev/ttyMP0"
EL_SERIAL = "/dev/ttyMP1"
BAUD = 9600

flags = sys.argv[4:]

if "-v" in flags:
    DEBUG = 1

BUFFER_SIZE = 1024

debug_print("[INIT]: Initializing TCP server at", TCP_IP, "on port", GP_PORT, "...\n")


if "-c" in flags:
    debug_print("[INIT]: Calibration required\n")
    data = "C1n;"
    debug_print("[TCP_SERVER]: Recognized response. Forwarding to positioner...\n")
    debug_print("[TCP_SERVER]: Handing over to client\n")
    direct_to_unit(data)

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, GP_PORT))
s.listen(5)
debug_print("[INIT]: Initialization successful\n")
debug_print("[INIT]: Accepting connection from Gpredict...\n")
(gp, address) = s.accept()
debug_print("[INIT]: Connection established\n")
while 1:
    debug_print("[TCP_SERVER]: Collecting data from Gpredict...\n")
    data = gp.recv(BUFFER_SIZE)
    debug_print("[TCP_SERVER]: Data collected.\n")
    debug_print("[TCP_SERVER]: Received Data: ", data)
    if data == "p\n":
        debug_print("[TCP_SERVER]: Recognized response. Forwarding to positioner...\n")
        debug_print("[TCP_SERVER]: Handing over to client\n")
        (az_data, el_data) = forward_to_controller(data);
        debug_print("Received from Az:\n")
        debug_print(az_data)
        debug_print("Received from El:\n")
        debug_print(el_data)
        debug_print("Processing data...\n")
        az_data = az_data.split('\n')[0]
        el_data = el_data.split('\n')[1]
        reply_data = az_data + '\n' + el_data + '\n'
        debug_print("Handing back to TCP Server\n")
        debug_print("[TCP_SERVER]: Sending data to Gpredict...\n")
        gp.send(reply_data)
        debug_print("[TCP_SERVER]: Data sent\n")
    elif (data[0] == 'P' or data[0] == 'S' or data[0] == 'F' or data[0] == 't'):
        debug_print("[TCP_SERVER]: Recognized response. Forwarding to positioner...\n")
        debug_print("[TCP_SERVER]: Handing over to client\n")
        (az_data, el_data) = forward_to_controller(data);
        debug_print("Received from Az:\n")
        debug_print(az_data)
        debug_print("Received from El:\n")
        debug_print(el_data)
        debug_print("Processing data...\n")
        if (az_data == el_data):
            reply_data = az_data
        else:
            reply_data = "RPRT -1\n"
        debug_print("Handing back to TCP Server\n")
        debug_print("[TCP_SERVER]: Sending data to Gpredict...\n")
        gp.send(reply_data)
        debug_print("[TCP_SERVER]: Data sent\n")
        if data[0] == 'S':
            debug_print("[TCP_SERVER]: Closing connection...\n")
            print "Got command to disengage"
            gp.close()
            print "Closed"
            debug_print("[TCP_SERVER]: Connection closed.\n")
            print "Ready again"
            (gp, address) = s.accept()
            

    else:
        debug_print("Unexpected command")
        debug_print(data)
        
    

