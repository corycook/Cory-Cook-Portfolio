data <- read.csv("HousingData.csv", header=T)
testrec <- data.frame(Age=48, Loan=142000)  #record for testing purposes
sdata <- normalize(data,1)
ntestrec <- normalize(testrec,"rec")

distance <- calcdistance(ntestrec)
distancetable <- cbind(sdata,distance)
