#!/usr/bin/python

import smtplib

mymail= "email"

pwd = raw_input("Pass: ")
number = int(raw_input("How many emails? "))

server = smtplib.SMTP('smtp.gmail.com', 587)
server.starttls()
server.login(mymail,pwd)

msg = "\nMessage"
for i in range(number):
	print "[*] Sending message: {}".format(i+1)
	server.sendmail(mymail, "destination", msg)
server.quit()
