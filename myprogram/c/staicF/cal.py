
#this is sample calculator program

def add(x,y):
	return(x+y)

def subtrac(x,y):
	return(x-y)

def multiply(x,y):
	return(x*y)

def parseInput(promt):
	value = input(promt)
	while not value.isnumeric():
		print("enter a number")
		value = input("enter again")
	return int(value)

promt = ['c']
promt = input()
print(promt)
