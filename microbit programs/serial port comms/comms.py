#!/usr/bin/env python3

import serial
import serial.tools.list_ports

def getMicrobitPort():

    serial_ports = list(serial.tools.list_ports.comports())

    for port in serial_ports:
        sep = str(port.description).find(' (')
        port_description = str(port.description)[:sep]
        if port_description == 'mbed Serial Port':
            return port.device;

def writeFileToFile (port,filename) :

    mb_port = serial.Serial(port,19200)
    f = open(filename,"r")

    for line in f:
        print(line)
        mb_port.write(line),

    f.close()
    mb_port.close()
    
    return;

def readFileToFile (port,filename) :

    mb_port = serial.Serial(port,19200)
    f = open(filename,"w")
    line = mb_port.readline()

    while line:
        print(line)
        f.write(line),

    f.close()
    mb_port.close()
    
    return;

def writeConsoleToConsole (port) :

    mb_port = serial.Serial(port,19200,timeout=20)
    i = input()

    mb_port.write(str.encode(i))

    mb_port.close()
    
    return;

def readConsoleToConsole(port):

    mb_port = serial.Serial(port,19200,timeout=20)
    i = mb_port.read(10)

    print(i)

    mb_port.close()

    return;

def readConsoleToFile(port,filename):
    
    mb_port = serial.Serial(port,19200,timeout=20)
    i = mb_port.read(10)

    f = open(filename,"w")
    f.write(str(i))
    f.close()

    mb_port.close()
    
    return;

microbit_port = getMicrobitPort()

print("Send(S) or Receive(R):")
i = input()
if i == 'S':
    writeConsoleToConsole('COM1')
elif i == 'R':
    readConsoleToFile('COM3','text.txt')
else : print("Invalid input!")







