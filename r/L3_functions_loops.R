#------------------------------LOOPS-------------------------------------

#repeat something
i <- 0
repeat {
  print("Yo")
  i <- i + 1
  if (i > 3) {
    break
  }
}

#while some condition is true
while(i > 0) {
  print("Bo")
  i <- i - 1
}

#for some values, while some condition is true, do and update
for (i in 1:4) {
  print("Lo")
}


#--------------------------------functions-----------------------

#named parameter received as dictionaries
#nameless parameters as arrays based on position
get_votes <- function(prompt = "Enter votes: ", z=1) {
  votes <- suppressWarnings(as.integer(readline(prompt)))
  cat(prompt, z)
  ifelse(is.na(votes), 0, votes)
}

mario <- get_votes("Enter votes for mario: ")
peach <- get_votes(z=2, prompt = "Enter votes for peach: ")
bowser <- get_votes("Enter votes for bowser: ", 3)

total <- sum(mario, peach, bowser)



#--------------------------function and loops---------------------------
get_votes <- function(prompt = "Enter votes: ") {
  repeat {
    votes <- suppressWarnings(as.integer(readline(prompt)))
    if(!is.na(votes)){
      return(votes)
    }
  }
}

total <- 0
for (name in c("Mario", "Peach", "Bowser")){
  votes <- get_votes(paste("Enter votes for", name, ":"))
  total <- total + votes
}

cat("Total votes:", total)


votes <- data.frame(
  poll = c(37, 43, 84),
  mail = c(63, 107, 36),
  row.names = c("Mario", "Peach", "Bowser")
)

#count total votes per candidate
total_votes <- c()
for (name in rownames(votes)) {
  total_votes <- c(total_votes, sum(votes[name, ]))
}
votes$total_votes <- total_votes

#count total votes per vote type
total_vtype <- c()

for (vtype in colnames(votes)) {
  total_vtype <- c(total_vtype, sum(votes[, vtype]))  
}

names <- rownames(votes)
rownames(votes) <- c(names[1: length(names)-1], "Total")

#using apply for sum of row(margin 1) or column(margin 2)
apply(votes, MARGIN=1, FUN=sum)
total <- apply(votes, MARGIN=2, FUN=sum)

#----------------------------SORTING------------------------------------
sort(total, decreasing = TRUE)