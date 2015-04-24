data <- read.csv("HousingData.csv")

input <- data.frame(Age = 25, Loan = 40000, Floors = 'One Story', House.Price.Index = 0)
k <- 1

#Normalization of Input

data.2 <- data
data.3 <- rbind(data.2,input)
for(i in 1:((ncol(data.3))-1)){
  if(is.factor(data.3[,i])){
    data.3[,i] <- factor(data.3[,i],labels = c(0,1))
    data.3[,i] <- (as.numeric(data.3[,i])-1)}
  else{
    data.3[,i] <- ((data.3[,i]) - min(data.3[,i]))/((max(data.3[,i]))-min((data.3[,i]))) }
}
input.f <- data.3[nrow(data.3),]
input.f <- input.f[,-(ncol(input.f))]

#Normalization Function + Numeric Categorization of up to 2 factors with 2 levels each. 
#Assumes last column is response

for(i in 1:((ncol(data.2))-1)){
     if(is.factor(data.2[,i])){
         data.2[,i] <- factor(data.2[,i],labels = c(0,1))
         data.2[,i] <- (as.numeric(data.2[,i])-1)}
     else{
         data.2[,i] <- ((data.2[,i]) - min(data.2[,i]))/((max(data.2[,i]))-min((data.2[,i]))) }
     }
     
#Now I've normalized, gotta find distance between my pt and other pts, store as new vecotr or something...'

distcol <- cbind(Distance=rep(0,nrow(data.2)))

for(i in 1:(ncol(data.2)-1)){
  distcol <- distcol + (data.2[,i] - input.f[,i])^2
}
distcol <- sqrt(distcol)
data.2 <- cbind(data.2,distcol)

#Ok cool. Now I need to take k y values from the house price index and computer avg, then assign that avg value to my input.


data.2 <- data.2[order(data.2$Distance),]

total = 0
for(i in 1:k){
  total <- total + data.2$House.Price.Index[i]
}
y.est <- total*(1/k)
cat(y.est)
       

       