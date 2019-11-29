#!/usr/bin/env python3

import os
import serial
import serial.tools.list_ports


def get_microbit_port():
    serial_ports = list(serial.tools.list_ports.comports())

    for port in serial_ports:
        sep = str(port.description).find(' (')
        port_description = str(port.description)[:sep]
        if port_description == 'mbed Serial Port':
            return port.device


def write_file_to_file(port, filename):
    mb_port = serial.Serial(port, 19200)
    f = open(filename, "r")

    for line in f:
        print(line)
        mb_port.write(line)

    f.close()
    mb_port.close()


def read_file_to_file(port, filename):
    mb_port = serial.Serial(port, 19200)
    f = open(filename, "w")
    line = mb_port.readline()

    while line:
        print(line)
        f.write(line),

    f.close()
    mb_port.close()


def write_console_to_console(port):
    mb_port = serial.Serial(port, 19200, timeout=20)
    i = input()

    mb_port.write(str.encode(i))

    mb_port.close()


def read_console_to_console(port):
    mb_port = serial.Serial(port, 19200, timeout=20)
    i = mb_port.read(10)

    print(i)

    mb_port.close()


def read_console_to_file(port, filename):
    mb_port = serial.Serial(port, 19200, timeout=20)
    i = mb_port.read(10)

    f = open(filename, "w")
    f.write(str(i))
    f.close()

    mb_port.close()


microbit_port = get_microbit_port()

print("Send(S) or Receive(R):")
i = input()
if i == 'S':
    write_console_to_console(os.getenv('port', default='COM3'))
elif i == 'R':
    read_console_to_file(os.getenv('port', default='COM3'), 'text.txt')
else:
    print("Invalid input!")
