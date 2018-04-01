import serial
ser = serial.Serial('com8',9600)
data = open("data.txt","w+")
print("hello \n")
b = 7
a = True
while a:
	line = ser.readline()
	line = line.decode("utf-8")
	print(line[:-2])
	line = line[:-2]
	line = line + "\n"
	data.write(line)
	if (b==1):
		a = False
	b -= 1
