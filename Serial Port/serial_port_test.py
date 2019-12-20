#!/usr/bin/env python3

import os
import requests
import sys
import serial
import serial.tools.list_ports
import time
import webbrowser
import microbit
import pty
import unittest

class TestMicrobit(unittest.TestCase):

    def test_send_id(self,id):
        master, slave = pty.openpty()
        s_name = os.ttyname(slave)

        microbit.send_id(s_name,id)

        self.assertEqual(id,os.read(master,10))

    def test_generate_full_url(self):
        timeout = 60
        question = "melhor_clube"
        option1 = "benfica"
        option2 = "porto"

        self.assertEqual(microbit.generate_full_url(timeout,question,option1,option2),
                        microbit.survey_base_url+"melhor_clube?&timeout=60&benfica&porto")

    def test_voting(self):

        master, slave = pty.openpty()
        s_name = os.ttyname(slave)
        ser = serial.Serial(s_name)

        timeout = 5
        question = "Which_came_first?The_chicken_or_the_egg?"
        option1 = "Both"
        option2 = "THE_SPANISH_INQUISITION!"

        votes_yes = microbit.voting(timeout,question,option1,option2)
        ser.write("Y_eah_boi")

        self.assertEqual(votes_yes,1)

    
# use -v in command line to see more
if __name__ == '__main__':
    # begin the unittest.main()
    unittest.main()