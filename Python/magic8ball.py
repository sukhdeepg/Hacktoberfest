# -*- coding: utf-8 -*-
"""
Created on Sat Jul 28 10:40:14 2018

@author: user
"""

import random
responses = ['It is decided','Yes-Definitely','No Doubt',
             'Yes Certainly','Most Probably','Try Again']
print('Welcome to Magic 8 Ball, Tell me your name')
name = input()
print('Welcome'+name)
def magic8ball():
    print('Ask Your Question')
    input()
    print(responses[random.randint(0,len(responses)-1)])
    print('I hope that was helpful')
    again()
    
def again():
    print('Do you have other problems ?[Y/N]')
    reply = input()
    if(reply == 'Y'):
        magic8ball()
    if(reply == 'N'):
        exit()
        
magic8ball()
