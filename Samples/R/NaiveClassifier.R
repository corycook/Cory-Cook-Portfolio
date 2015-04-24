mydata <- read.csv("Income_Training_Data.csv", header = T)
attach(mydata)


#assume last column is Response - hardcode as evade
rl <- summary(Evade)

# for each possible response category, calculate denominator
for (i in 1:length(rl)) { #cat(names(rl[i]), "\n")
                          denom <- as.integer(rl[i])

                          # Refund = NO and Respnose = No/Yes
                          num <-  nrow ( subset(data, subset=(data$Refund=="No" & data$Evade ==names(rl[i])))  ) 
                          cat(names(rl[i]), ":", num, "*", denom, "\n" )
                        
                          # Married = Single and Respnose = No/Yes
                          num <- nrow ( subset(data, subset=(data$Marital.Status=="Single" & data$Evade ==names(rl[i])))  )
                          cat("Single", names(rl[i]), ":", num, "*", denom, "\n" )                         
}

 
# determine which variables in dataset are categorical

varclass <- lapply(mydata, class)

for (i in 1:ncol(mydata)) 
  if(varclass[i]=="factor") {
    cat(names(mydata[i]), " is a factor ")
    cat("\n")
  }

dim(mydata)
is.factor(mydata$Tid)
is.factor(mydata$Refund)

for (lvl in levels(mydata$Evade)) cat(lvl, " ")


mytest <-function(x) { #cat(is.factor(x), "\n")
                       y <- 3
return(is.factor(x)) }
