#-----------------------------Library---------------------------------------
#LIBRARY -> a location from where package/s can be loaded
#and used in another program 
#PACKAGE -> a collection r code / functions / data organized in a defined
#format to serve some purpose/s
#install.packages(pkg_name)    -> install package
#library(pkg_name)              -> use library in a script

library("tidyverse")

'
select
filter
arrange
distinct
group_by
summarize
'

storms <- read.csv("src4/storms/hurricanes.csv")
storms <- tibble(storms)                  #organize storms as dplyr tibble
dplyr::select(storms, !c(year))           #select columns, !select columns

'
contains
ends_with
starts_with
'

#select tibble's based on column name ending  
#filter tibble based on logical expression
dplyr::filter(
  dplyr::select(
    storms, c(year, wind, ends_with("me"))
  ),
  wind > 130
)

#----------------------pipe operator |> or %>5 --------------------------
#piping allows dataframe to be passed as first argument
#this enables left to right chaining 
storms |> 
  select(c(year, wind, ends_with('me'))) |>
  filter(wind > 150) |>
  arrange(desc(year), desc(wind))

#distinct checks all cols default
#.keeps_all flag display all cols
storms |> 
  distinct(name, year, .keep_all = TRUE) |>
  arrange(name)

storms |> 
  select(c(year, wind, ends_with('me'))) |>
  filter(wind > 150) |>
  arrange(desc(year), desc(wind)) |>
  distinct(name, year, .keep_all = TRUE) 
  #|> write.csv("hurricanes.csv", row.names = FALSE)


#-------------------------slicing---------------------------------------

#find max wind value of hurricane by year
'
slice_head    -> get 1st row of a group
slice_tail    -> get last row of a group
slice_max     -> get row of a group with max value of speciified col name
slice_min     -> get row of a group with min value of speciified col name
'
storms |>
  group_by(year) |>
  arrange(desc(wind)) |>
  slice_head()

#same result can be achieved by
storms |>
  group_by(year) |>
  slice_max(order_by = wind)

#number of hurricanes by year
#n() function returns number of rows in a group
#storms = names resulting column
storms |>
  group_by(year) |>
  summarize(storms = n())

#ungrouping -> ungroup 
st <- storms |> 
  group_by(year) |>
  ungroup()


#-----------------------------TIDYING--------------------------------------
'Tidy data principles
1. each row  is an observation and each observation is a row
2. each col  is a  variable    and each variable    is a col
3. each cell is a  value       and each value       is a cell 
'
library("tidyr")
students <- read.csv("src4/students/students.csv")

#pivot wider for making row values to columns
students <- pivot_wider(
  students,
  id_cols = student,
  names_from = attribute,
  values_from = value
)
students$GPA <- as.numeric(students$GPA)
students |>
  group_by(major) |>
  summarize(GPA = mean(GPA))


#pivot longer for making col values to rows


library("stringr")
shows <- read.csv("src4/shows/shows.csv")

'
str_trim()    -> trim spaces from left right
str_squish()  -> remove extra spaces from between strings
str_detect()  -> detect variations of same value
'
shows$show <-
  shows$show |>
  str_trim() |>
  str_squish() |>
  str_to_title()

#all shows that have string avatar name them avatar the last airbender
shows$show[str_detect(shows$show, "Avatar")] <- "Avatar : The Last AirBender"

shows |>
  group_by(show) |>
  summarize(votes = n()) |>
  ungroup() |>
  arrange(desc(votes))



