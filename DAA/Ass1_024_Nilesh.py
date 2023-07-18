def recursive_fib(n):
	if n<=1:
		return n
	else:
		return recursive_fib(n-1) + recursive_fib(n-2)


def non_recursive_fib(n):
	first=0
	second=1
	
	print(first)
	print(second)
	
	while n-2>0:
		third = first + second
		first = second
		second = third
		print(third)
		n-=1
		
if __name__=="__main__":
	n=5
	for i in range(n):
		print(recursive_fib(i))
	print(non_recursive_fib(n))
	
