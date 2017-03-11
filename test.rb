def func1(a, b, c)
	return a * Math.log2(b) * Math.log2(c); 
end

def func2(a, b, c)
	return a * b * c
end

a = 60000
b = 60000
c = 60000

puts func2(a, b, c) / func1(a, b, c)