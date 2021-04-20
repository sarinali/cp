# wtf is this code??? thank god i dont do python anymore LOLLLL

def numtoroman(finalnum, sym, values):
    roman_num = ''#the string
    i = 12
    while finalnum:#while there are still any digits left
        div = finalnum // values[i] #divide it by the values if possible, starting big to small
        finalnum %= values[i]
 
        while div:
            roman_num += sym[i]
            div -= 1
        i -= 1 #starts atthe ed of the list and goes down

    return roman_num

roman = {'I':1,'V':5,'X':10,'L':50,'C':100,'D':500,'M':1000,'IV':4,'IX':9,'XL':40,'XC':90,'CD':400,'CM':900}
sym = ["I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"]
values = [1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000]
#dictionaries and lists for conversions
times = int(input())

for k in range(times):
    firstsecondstringraw = input()
    firstsecondstring = firstsecondstringraw[:-1] #removes "I+I=" the=
    first, second = firstsecondstring.split("+") # splits input
    i = 0 #resets counters and variables
    f = 0
    num = 0
    num2 = 0

    while i<len(first): #while there r still more digits to check
        if i+1<len(first) and first[i:i+2] in roman: 
            num+=roman[first[i:i+2]] # in the case that IX or IV etc exsist
            i+=2 # since we skipped 2 digits
        else:
            num+=roman[first[i]] # regular case, the next one is larger or equal
            i+=1

    while f<len(second):
        if f+1<len(second) and second[f:f+2] in roman:
            num2 += roman[second[f:f+2]]
            f+=2
        else:
            num2 += roman[second[f]]
            f+=1

    finalnum = num + num2 #adds both of my inputs in base 10 form

    if finalnum >= 1000:
        print("{}CONCORDIA CUM VERITATE".format(firstsecondstringraw))
    else:
        print("{}{}".format(firstsecondstringraw,numtoroman(finalnum, sym, values)))
        # function converts to roman form