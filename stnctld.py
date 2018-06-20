#!/usr/bin env python
from pyModbusTCP.client import ModbusClient
import socket
import sys
import time
import serial

def convert_to_dec(args):

  n = len(args)
  for i in range(0, n):
    args[i] = args[i] * (16 ** (i*4))
  raw = sum(args)
  sign = raw // (2 ** 31)
  exp = (raw % (2 ** 31)) // (2 ** 23)
  mantissa = 1 + (float(raw % (2 ** 23))) / (2 ** 23)
  ana = (-1) ** sign * (2 ** (exp - 127)) * mantissa
  return ana

def parse_data(data):
    command = data[0]
    try:
        dest = int(data[1:3])
    except:
        dest = -1
    args = data[3:]
    return (command, dest, args)

def modbus_request(command, dest, args):
    if (command == 'g'):
        # read coils
        bits = c.read_coils(0, 8) + c.read_coils(8, 8)
        print "Read coil" + str(dest) + "as " + str(bits[dest-1])
        if (bits[dest-1]):
            return str(1)
        else:
            return str(0)  
    elif (command == 'r'):
        # read discrete inputs
        bits = c.read_discrete_inputs(0, 8) + c.read_discrete_inputs(8, 8)
        if (bits[dest-1]):
            return str(1)
        elif not (bits[dest-1]):
            return str(0)
        else:
            return 'E'
    elif (command == 'm'):
        # read analog inputs
        bits = c.read_holding_registers(16, 8)
        start = dest*2-2
        end = dest*2
        ana = convert_to_dec(bits[start:end])
        return str(ana)
    elif (command == 's'):
        # write coil
        c.write_single_coil(dest-1, bool(int(args)))     
        return "RPRT 0"
    elif (command == 'q'):
        return "q"
    else:
        print "Invalid Command"
    return str(-1)
    


BUFFER_SIZE = 1024

TCP_IP = 'localhost'
GP_PORT = 4520
MODBUS_HOST = '192.168.0.251'
MODBUS_PORT = 502

s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.bind((TCP_IP, GP_PORT))
s.listen(5)

(gp, address) = s.accept()

c = ModbusClient(host=MODBUS_HOST, port=MODBUS_PORT, auto_open=True)
c.debug(False)

while 1:
    if not c.is_open():
        if not c.open():
            print "Unable to connect to %s" % (MODBUS_HOST)
    data = gp.recv(BUFFER_SIZE)
    (command, dest, args) = parse_data(data)
    reply_data = modbus_request(command, dest, args)
    if (reply_data == "q"):
        print "Got command to quit"
        gp.close()
        print "Closed"
        (gp, address) = s.accept()
        print "Connected again"
    else:
        gp.send(reply_data)



