library("ggplot2")
votes <- read.csv("lecture_source/src5/votes/votes.csv")

'
data      <- data for ggplot
aesthetic <- individual shapes (axes, scales) for data
geometry  <- visual setting in which data is to be plotted

scale types <- continuous and discreet
scale_x_contnious, scale_x_discreet
scale_y_contnious, scale_y_discreet

'

#plots are plotted in layers, layers are stacked 


#------------------------COLUMN/BAR-GRAPH------------------
#ggplot aesthetics data, azes names
p <- ggplot(votes, aes(x = candidate, y = votes)) +  
  
  #geometry aesthetics, type of graph, colors
  geom_col(aes(fill = candidate), show.legend = FALSE) +
  
  #add color friendly scale layer for color blinds named kanda
  scale_fill_viridis_d("Kanda") +
  
  #add scale layer on y axes to value 250 
  scale_y_continuous(limits = c(0, 250)) +
  
  #add label layer for x-y axes and plot name
  labs(
    x = "Candidates",
    y = "Votes",
    title = "Election Results"
  ) +
  
  #add theme layer
  theme_dark()

#save the plot as image file
ggsave(
  "lecture_out/src5/votes.png",
  plot = p,
  height = 1200,
  width = 1200,
  units = "px"
)


#-----------------------POINT PLOT--------------------------
load("lecture_source/src5/candy/candy.RData")

'
color
shape
size
fill
'

ggplot(candy, aes(
  x = price_percentile,
  y = sugar_percentile)
) +
  
  #geom point for point graph
  #jitter jitters observations if they overlap
  #color gives color to all instead of mapping onto each
  #class of observation
  geom_jitter(
    color = "darkorchid",
    fill = "orchid",
    shape = 21,
    size = 2
  ) +
  labs(
    x = "Price_percentile",
    y = "Sugar_percentile",
    title = "Price and Sugar"
  ) +
  theme_classic()

#---------------TIME SERIES DATA--------------------------
#---------------data that changes over time------------------
load("lecture_source/src5/anita/anita.RData")

'
linetype  
linewidth 
'
ggplot(anita, aes(x = timestamp, y = wind)) +
  geom_line(
    linetype = 1,
    linewidth = 0.5
  ) +
  geom_point(
    color = "deepskyblue4",
    size = 2
  ) +
  geom_hline(
    linetype = 2,
    yintercept = 60
  )
labs(
  x = "Date",
  y = "Wind Speed (Knots)",
  title = "Hurricane Anita"
)
