a=[12,0,1,3,0,4,11,0,5,9,0]

def shiftzero(a,n):
	print(a)
	count=0
	for i in range(n):
		if a[i] != 0:
			temp = a[count]
			a[count] = a[i]
			a[i] = temp
			count +=1
	
	#print(a)

	#while count < n:
	#	a[count] =0
	#	count +=1 

	print(a)

shiftzero(a,len(a))

