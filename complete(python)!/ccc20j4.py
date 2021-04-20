t = input()

s = input()

# the string slicing code

def instring(t, s):
    for i in range(len(s)):
        firsthalf = s[i:]
        secondhalf = s[:i]
        cycles = firsthalf + secondhalf
        if cycles in t:
            return True

    return False

if instring(t, s) == True:
    print("yes")
else:
    print("no")