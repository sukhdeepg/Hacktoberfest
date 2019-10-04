#!/usr/bin/python
import urllib2, re, random, os


def get_macs_list():
	url = "http://standards-oui.ieee.org/oui/oui.txt"
	lis = []
	for line in urllib2.urlopen(url):
		regex = r"[0-9a-fA-F][0-9a-fA-F][-][0-9a-fA-F][0-9a-fA-F][-][0-9a-fA-F][0-9a-fA-F]"
   		match = re.findall(regex, line)
   		for m in match: 
   			print m
   			lis.append((m.replace('-', ':') + " | " + " ".join(line.split()[2:]) + '\n' ))
   	with open('macs.txt', 'w') as file:
		for n in lis:
			file.write(n)

def hex():
	return random.choice('abcdef1234567890')

def get_random_mac():
	with open("MAC.txt", "r") as file:
		first = random.choice(file.readlines()).replace("-",":").lower()
		mac = first.strip() + ":" + hex() + hex() + ":" + hex() + hex() + ':' + hex() + hex()
		return mac
		
mac = get_random_mac()

print "\nOld MAC address:"
os.system("ifconfig en0 | grep ether | grep -oE [0-9abcdef:]{17}")

choice = raw_input("Do you want to change to this mac address: " + mac + "? ")
if choice.lower() == "yes":
	os.system("sudo ifconfig en0 ether " + mac )
	print "\nNew MAC address:"
	os.system("ifconfig en0 | grep ether | grep -oE [0-9abcdef:]{17}")
else:
	sys.exit()