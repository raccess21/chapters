print("yo in double quotes")        #default value for end character is \n
print('yo but in single quotes')
print('\'yo\' but with single quotes in single quotes')
print("\"yo\" but with double quotes in double quotes")

#basically print predefined character in output using a "\" as in "C"


#single line strings
a1="yo in double quotes"
a2='yo but in single quotes'
a3='\'yo\' but with single quotes in single quotes'
a4="\"yo\" but with double quotes in double quotes"

print(a1+'\n'+a2+'\n'+a3+'\n'+a4+'\n')  #\n for newline
print(a1+'\t'+a2+'\t'+a3+'\t'+a4+'\t')  #\t for tab
print(a1+'\a'+a2+'\a'+a3+'\a'+a4+'\a')  #\a for audible bell or beep
print(a1, end="\n")                     #end to end a output with specified character
print(a1[10])
#----------------------------------------------------------------------------

#multiline strings ''' or """
mlStr='''yo in double quotes
yo but in single quotes
\'yo\' but with single quotes in single quotes
\"yo\" but with double quotes in double quotes'''
#==============================================================================


#implementation of string is in continous array of bytes
#looping through a string
len=len(mlStr)          #len() for string length check
print(len)              #len variable still supported
for i in a1:
    print(i, end="@ ")  #to end every i which is a sinle character part of mlStr with @

''' replace \n with \t
for i in range(0, length-1):
    if(mlStr[i]=='\n'):
        mlStr[i]='\t'       #assignment of item not supported by mlStr
print(mlStr)
'''
#------------------------------------------------------------------------------


#check support on strings
if "yo" in mlStr:
    print(mlStr)
else:
    print("no yo in mlStr")

#slincing string
print(mlStr)
print(mlStr[1:7])           #slicing from start, 1st to 7th, doesn't include 7th
print(mlStr[-7:-1])         #slicing from end, 7th last to 2nd last, not include 7th last
print(mlStr[7:3])
