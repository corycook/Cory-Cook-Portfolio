# Cory Cook
# CS256 45521
# 7 September 2014

# 8a
setwd('C:/Workspace/R')
college<-read.csv('college.csv')

# 8b
# fix(college)
rownames(college)=college$X
college=college[,-1]
# fix(college)

# 8ci
summary(college)

#8cii
pairs(college[,1:10])

# 8ciii
boxplot(college$Outstate, college$Private)

# 8civ
Elite=rep('No', nrow(college))
Elite[college$Top10perc>50]='Yes'
Elite=as.factor(Elite)
college=data.frame(college,Elite)
summary(college$Elite)
boxplot(college$Outstate,college$Elite)

# 8cv
par(mfrow=c(2,2))
for(set in college[,2:5]) hist(set)

# 8cvi
# see output.txt

# 9a
setwd('C:/Workspace/R')
auto<-read.csv('Auto.csv')
fix(auto)

# all values except for name are quantitative
# non numeric values may be considered qualitative
for(col in names(auto)) if(is.factor(auto[,col])) print(col)

# 9b
# range
for(col in names(auto)) {
 if(!is.factor(auto[,col]))
  cat(col, ':', range(auto[,col]), '\n')
}

# 9c
# mean and standard deviation
for(col in names(auto)) {
 if(!is.factor(auto[,col]))
  cat(col, ':', mean(auto[,col]), sd(auto[,col]), '\n')
}

# 9d
rows<-row(auto)[,1]<10|row(auto)[,1]>85
sauto<-auto[rows,]
for(col in names(auto)) {
 if(!is.factor(auto[,col]))
  cat(col, ':', range(sauto[,col]), mean(sauto[,col]), sd(sauto[,col]), '\n')
}

# 9e
plot(auto)
# The name has no affect on the rest of the data.

# 9f
# The weight and displacement of the vehicle appear to affect the mpg of the vehicle.
# The data plots vs mpg show an inverse relationship between the metrics.



