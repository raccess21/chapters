#source code -> compile binary -> package
'
Description ->  description of package, version info
Namespace   ->  functions in package end user can use
man/        ->  documentation of package
R/          ->  .R files with function definition
tests/      ->  tests for code

----------------------------------------------------------------------

library(devtools) 
use_testthat  -> indicates use of test_that for testing creates file-folders
use_test(pkg) -> write automated tests for package
use_r(pkg)    -> create r folder-files
load_all()    -> export all functions in NAMESPACE

test()        -> run all tests

man/          -> manual folder (function.Rd)
'

#------------------building R package-------------------
'
build         -> build in R console (r wrapper for cmd build)
R CMD build   -> build in terminal
'

#------------------building R package-------------------
'
install        -> install in R console (r wrapper for cmd install)
R CMD install  -> install in terminal
'

library(ducksay)

phrase <- readline("What's your name: ")
cat(ducksay(paste("Hello,", phrase)))

