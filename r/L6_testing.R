#--------------------------TESTING PROGRAMS----------------------------

#check for errors and return messages
'
message   <- to notify current state
warning   <- to notify potential issues/errors
stop      <- to notify error and stop further functioning
'
average <- function(x) {
  x <- try(as.numeric(x))
  
  if(length(x) == 0) {
    stop("No value given")  
  }
  
  if(any(is.na(x))) {
    warning("'X contains NA values..")
    return(NA)
  }
  
  message("Average is being calculated...")
  sum(x) / length(x)
}

greet <- function(name="lem lem") {
  paste("Hello,", name)
}
#cat(average(c()))

