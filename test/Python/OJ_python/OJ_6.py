a=int(input())
for l in range(3):
	for i in range(1,a+1):
		for j in range(a-i):
			print(' ',end=' ')
		for k in range(i*2-1):
			print('*',end=' ')
	print(end='\n')
print()
