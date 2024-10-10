#--------------------------------UNIT TEST-----------------------------------
source("L6_testing.R")
library("testthat")

test_average <- function() {
  if(average(c(1,2,3)) == 2) {
    cat("Average passed test 1 :)\n")
  } else {
    cat("Average failed the test 1 :(\n")
  }
  
  if(average(c(-1,-2,-3)) == -2) {
    cat("Average passed test 2 :)\n")
  } else {
    cat("Average failed the test 2 :(\n")
  }
}


#--------------------------Testing using testthat--------------------------
#test with floating point tolerance
test_that("Average calculates mean", {
  expect_equal(average(c(1,2,3)), 2)
  expect_equal(average(c(1,'2',3)), 2)
  expect_equal(average(c(0.1,'0.2',0.3)), 0.2, tolerance = 1e-7)
  expect_equal(average(c(-1,-2,-3)), -2)
})

test_that("Average returns warnings", {
  expect_warning(average(c('a', 'b')))
  expect_warning(average(c(NA, NA)))
})

test_that("'average' returns NA", {
  expect_warning(suppressWarnings(average(c('a', 'b'))), NA)
  expect_warning(suppressWarnings(average(c(NA, NA))), NA)  
})

test_that("'average' stops", {
  expect_error(average(c()))
})


#------------------TEST DRIVEN DEVELOPMENT------------------------------------
#create test/expection of a function and code function
test_that("'greet' returns value", {
  expect_equal(greet('rem rem'), "Hello, rem rem")
})


#------------------BEHAVIOUR DRIVEN DEVELOPMENT------------------------------------
#describe behavior of a function and code function
describe("greet()", {
  it("can say hello to a 'user'", {
    name <- "rem rem"
    expect_equal(greet("rem rem"), "Hello, rem rem")
  })
  
  it("can say hello to lem lem", {
    expect_equal(greet(), "Hello, lem lem")
  })
})


#---------------------------TEST COVERAGE--------------------------------
#meaasure how much and how reliably functions in a script have been tested