#dynamically typed

#name variable, 
#readline function reads from the console, 
# <- assignment operator, assigns based on direction, left to right or R2L
# paste function used for string concatenation, default separator space
name <- readline("What's your name: ")
greeting <- paste("Hello,", name)
print(greeting)

# readline reads data from the console
readline("What's your game: ") -> game
print(paste("Hello, ", game, sep=''))


rm(name, greeting)            #removes name and greeting from current working env
rm(list = ls())               #removes everything from curr working env


#type casting as.integer, as.character, as.double
mario <- as.integer(readline("Enter votes for Mario : "))
peach <- as.integer(readline("Enter votes for Peach : "))
bowser <- as.integer(readline("Enter votes for Bowser: "))

#binary operators + - * /
total <- mario + peach + bowser
sumtotal <- sum(mario, peach, bowser)
print(paste("Total votes are:", total))
print(paste("Sum votes are:", sumtotal))

#print single value hi lega to print+paste ke bdle cat hi q na use kre

#------------------------reading table-------------------------
votes <- read.table(
  "lecture_source/src1/tabulate/votes.csv", 
  sep = ',', 
  header = TRUE
)

#inbuilt csv reading functionality
csvotes = read.csv("lecture_source/src1/tabulate/votes.csv")
View(csvotes)
nrow(csvotes)           #number of rows in csvotes
ncol(csvotes)           #number of cols in csvotes

#------------------------accessing table------------------------
#using index values starts at 1
csvotes[1, 1]                      #First row first col
csvotes[2, ]                       #Entire second row
csvotes[, 3]                       #Entire third column
csvotes[1]                         #Entire first column dataframe

#using row and column name
csvotes$candidate
csvotes$poll
csvotes$mail

#extraction examples
csvotes[1,]$candidate
csvotes$poll[1]

#note: extraction techniques return vector data structures 
#i.e data with same storage mode, vector function automatically 
#detect and operate on entire vector (similar to python list)
sum(csvotes$poll)               #sum of all values in poll
sum(csvotes$mail)               #sum of all values in mail
mean(csvotes$poll)              #mean of all values in poll
csvotes$poll + csvotes$mail     #all n of poll + all n of mail = vector of len n
csvotes$poll + csvotes[, 3]     #all n of poll + all n of mail = vector of len n

#----------------------adding new column------------------------------------
#len of new col should be equal to len of all other cols
csvotes$total <- csvotes$poll + csvotes$mail


#---------------------------write csv file-----------------------------------
write.csv(csvotes, "lecture_out/src1/total.csv", row.names = FALSE)


#--------------------------external data------------------------------------
# Demonstrates reading data from a URL

#url <- "https://github.com/fivethirtyeight/data/raw/master/non-voters/nonvoters_data.csv"
#voters <- read.csv(url)
voters <- read.csv("lecture_source/src1/voters.csv")

#-------------------------special values----------------------------------------
# inf, -inf       infinity
# NaN             not a number
# NA              not available
# NULL            nothing

unique(voters$voter_category)           #unique values in a vector
factor(voters$voter_category)           #factors all data based on unique values in a vector
factor(
  voters$Q21,                           #unique -1, 1, 2, 3 convert to categorised levels
  labels = c("Yes", "No", "Unsure"),    #added labels to values
  exclude = c(-1)                       #exclude all -1  
)  
