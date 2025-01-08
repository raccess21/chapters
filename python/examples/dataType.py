#text       str
#numeric    int, float, complex
#sequence   list, tuple, range
#mapping    dict
#set        set, frozen
#boolean    bool
#binary     bytes, bytearray, memoryview
#none       NoneType

#function type() to get data type of a variable

x=5
print(type(x))


#testing every data type
#string
text="ten"

#numeric
numericInt=10
numericFloat=123456.12345678901234567890
numericComplex=1.9+1j

#sequence
sequenceList = ["one", "list", "ten"]
sequenceTuple = ("one", "tuple", "ten")
sequenceRange = range(1, 10)

#mapping
mappingDict = {"numUp" : 1, "numDown" : "ten"}

#set
setSet = {"one", "set", "ten"}
setFrozenset = frozenset({"one", "fset", "ten"})

#boolean
booleanBool = False

#binary
binaryBytes = b"one byte ten"
binaryBytearray = bytearray(10)
binaryMemoryview = memoryview(bytes(5))

#none
noneNoneType = None


#output test every data type
#string
print(text, type(text))

#numeric
print(numericInt, type(numericInt))
print(numericFloat, type(numericFloat))
print(numericComplex, type(numericComplex))
print(numericInt+numericFloat, type(numericInt+numericFloat))
#sequence
print(sequenceList, type(sequenceList))
print(sequenceTuple, type(sequenceTuple))
print(sequenceRange, type(sequenceRange))

#mapping
print(mappingDict, type(mappingDict))

#set
print(setSet, type(setSet))
print(setFrozenset, type(setFrozenset))

#boolean
print(booleanBool, type(booleanBool))

#binary
print(binaryBytes, type(binaryBytes))
print(binaryBytearray, type(binaryBytearray))
print(binaryMemoryview, type(binaryMemoryview))

#none
print(noneNoneType, type(noneNoneType))

k=bytes(5)
print(k)


#type casting supported
x=1
y=float(x)

#printing random numbers
import random
print(random.randrange(1,100))

#adding two floats creates automatic extra precision
