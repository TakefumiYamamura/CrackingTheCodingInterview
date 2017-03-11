# @param {String} s
# @return {Integer}
def isInteger?(str)
  Integer(str)
  true
rescue ArgumentError
  false
end

def createRPN(s)
  hash = {}
  hash["("] = 0
  hash["+"] = 1
  hash["-"] = 1
  hash["*"] = 2
  hash["/"] = 2
  hash[")"] = 4
  stack = []
  rpn = []
  tmpInt = ""
  count = 0
  while count < s.size
    ch = s[count]
    next if ch == " "
    if isInteger?(ch)
      tmpStr = ch
      while count + 1 < s.size && isInteger?(s[(count+1)])
        count += 1
        tmpStr += s[count]
      end
      rpn << tmpStr
    elsif ch == "("
      stack << ch
    elsif ch == ")"
        while stack.last != "("
          rpn << stack.pop
        end
        stack.pop
    else
      if stack.empty? || (hash[stack.last] < hash[ch]) 
        stack << ch
      else
        while !stack.empty?  && hash[stack.last] >= hash[ch]
          rpn << stack.pop
        end
        stack << ch
      end
    end
    count += 1
  end
  while !stack.empty?
    rpn << stack.pop
  end
  return rpn
end

def checkValid?(s)
  s.chars do |ch|
    if !isInteger?(ch) && ch != "+" && ch != "-" && ch != "*" && ch != "/" && ch != "(" && ch != ")"
      return false
    end
  end
  return true
end

def calculate(s)
  if !checkValid?(s)
    return false 
  end
  s.delete!(" ")
  rpn = createRPN(s)
  stack = []
  rpn.each do |ch|
    if isInteger?(ch)
      stack << Integer(ch)
    else
      second = stack.pop
      first = stack.pop
      if ch == "+"
        stack << first + second
      elsif ch == "-"
        stack << first - second
      elsif ch == "*"
        stack << first * second
      else
        stack << first / second
      end
    end
  end
  return stack.pop
end

# p calculate "1*2-3/4+5*6-7*8+9/10"
