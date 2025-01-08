#print in python
print("yo")

#if in python
if 5>2:
 print("5 is big")

#variable in python is assigned at creation
#no declaration like in "C"
i="ten"
print(i)
i=10
print(i)

"""multiline comment using
multiline string literal
not assigned
to any varaible"""

#type casting and type fetching of variable
print(
    type\
    (i)
    )
#using \ to break single command in multiline
#multiline commands inside () is also available


#case sensitive variable names
I=20;
print(i)
print(I)

#camel case  figureProfile
#snake case  figure_profile
#pascal case FigureProfile

#multiple assignment
i, j, k = 1, 2, "no"
print(i)
print(j)
print(k)

i=j=k=0
print(i+j+k)

#unpacking a list
names = ["name1", "name2", "name3"]
i, j, k = names
#print(i & j & k)   not supported
#print(names)       not supported
#print for multi variable output
print(i, j, k)
print(i+j+k)
print(i+' '+j+' '+k)
j=10
#print(i+' '+j+' '+k) not supported
#string + concatenation,  int + addition
print(i, j, k)
