#-*- coding: utf-8 -*-
import time
import urllib.request

while 1:
	# 1. 센서로 부터 측정된 데이터를 읽는다.
	tempfile = open("/sys/bus/w1/devices/28-03168b17c0ff/w1_slave")
	thetext = tempfile.read()
	tempfile.close()

	# 2. 데이터 형식에서 숫자값만 가져온다.
	tempdata = thetext.split("\n")[1].split(" ")[9]
	temperature = float(tempdata[2:])
	temperature = temperature / 1000
	print (temperature)

	# 3. 데이터를 웹서버에 전달한다.
	url = "http://localhost:3000/?temp=" + str(temperature)
	ret = urllib.request.urlopen(url)
	if ret:
		print ("localhost: success!")
	else:
		print ("localhost: fail!")

	# 4. 데이터를 Thingspeak에 전달한다.
	url = "https://api.thingspeak.com/update?api_key=L60O0PYGMWQ2QKQG&field2=" + str(temperature)
	ret = urllib.request.urlopen(url)
	if ret:
		print ("Thingspeak: success!")
	else:
		print ("localhost: fail!")

	# 5. 이 프로그램은 10초마다 반복된다.
	time.sleep(10)

