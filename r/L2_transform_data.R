temps <- c(12, 3, 4, 5, 6, -1, 102, 7, -5)

#---------------------outliers -> data outside of valid range-----------------
#indexing using vector
temps[c(1, 6, 9)]                         #fetch values at indexes
temps[-c(1, 6, 9)]                        #fetch values except at indexes


#---------------------logical expressions-------------------------------------
#   ==  !=  <   >   <=  >=
# returns TRUE T    or FALSE F
# && and    || or     for single value
# & and    | or       for vector
temps < 0
temps > 50
which(temps < 0 | temps > 50)         #which under condition returns -- vector
any(temps < 0 | temps > 50)           #any under condition returns true or false
all(temps < 0 | temps > 50)           #all under condition returns true or false

# vector -> logical vector filter --> subset vector
temps[which(temps < 0 | temps > 50)]  #vector under this condition
temps[temps < 0 | temps > 50]         #achieving same result without which
temps[which(!(temps < 0 | temps > 50))]  #negation of condition
temps[!(temps < 0 | temps > 50)]         #negation of condition

#writing transformed data
no_outliers = temps[!(temps < 0 | temps > 50)]
save(no_outliers, file = "no_outliers.RData")


#-----------------------conditionals---------------------------------------

#find mean weight of chicks based on feed
sum(is.na(chicks$weight))             #total na in weight field
nrow(chicks[is.na(chicks$weight), ])  #total na in weight field

#---------------------dealing with  na values-------------------------------
mean(chicks$weight, na.rm = TRUE)                      #all chicks
chicks <- chicks[which(!is.na(chicks$weight)), ]

#subset takes dataframe and vector condition
chicks <- subset(chicks, !is.na(weight))

#removing rows leaves missing row numbers
rownames(chicks) <- NULL                    #r builds rownames again

#------------------------data based on feed---------------------
#using indices
chicks[c(1, 2, 3), ]          #chicks at indices 1 - 3
chicks[1:3, ]                 #chicks at indices 1 - 3

#using conditional subsetting
mean(chicks[chicks$feed == "casein", ]$weight)
mean(chicks[chicks$feed == "fava", ]$weight)

#using subset function
mean(subset(chicks, feed == "fava")$weight)
mean(subset(chicks, feed == "meatmeal")$weight)


#------------------------------menus---------------------------------------
chicks <- read.csv("chicks.csv")
chicks <- subset(chicks, !is.na(weight))

feeds <- unique(chicks$feed)
cat(paste0(1:length(feeds), ". ", feeds), sep="\n")
feed_choice <- as.integer(readline("Feed type: "))

#------------------------------conditional---------------------------------
if(feed_choice < 1 || feed_choice > 6) {
  cat("Invalid choice")  
} else {
  chosen <- feeds[feed_choice]
  print(subset(chicks, feed == chosen))
}

#----------------------------binding multiple tables-------------------------
q1 <- read.csv("src2/sales/Q1.csv")
q1$quarter <- "Q1"
q2 <- read.csv("src2/sales/Q2.csv")
q2$quarter <- "Q2"
q3 <- read.csv("src2/sales/Q3.csv")
q3$quarter <- "Q3"
q4 <- read.csv("src2/sales/Q4.csv")
q4$quarter <- "Q4"

#rbind binds dataframes, !column number should be same
sales <- rbind(q1, q2, q3, q4)

#adding vector based on conditional
sales$value <- ifelse (sales$sale_amount > 100, "High", "Regular")



