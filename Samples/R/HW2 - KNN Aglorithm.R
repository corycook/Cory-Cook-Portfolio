
########################################## Normalize Function ##################################
#
#  Summary: Function normalizes non categorical data columns using the 
#           formula Xi=(X-Min)/(Max - Min). Assumes last row is response & will not normalize it
#  Params:   The data set and flag. If flag = "rec" normalize vector, else norm set minus last col
#  Output:  The data set with all non-categorical columns normalized (Excluding Response COlumn) 
#
################################################################################################

normalize <- function(x, flag) {
  if (flag == "rec"){
    for(col in names(x)) {
      if (is.factor(data[,col])) {
		cat('Categorical Data Column \n')
      } else {
		x[,col] <- (x[,col]- min(data[,col]))/(max(data[,col])-min(data[,col]))
      }
    }
  }
  else 
     for(col in names(x[,1:(ncol(x)-1)])) {
      if (is.factor(data[,col])) {
        cat('Categorical Data Column \n')
      } else {
        x[,col] <- (x[,col]- min(x[,col]))/(max(x[,col])-min(x[,col]))
      }
    }
  return(x)
}


########################################## Distance Function ##################################
#
#  Summary: Calcluates distance from input point to all points in the training set           
#  Params:  The test record x
#  Output:  A column containing the distances between x and all the training set points
#
################################################################################################
calcdistance <- function(x){
  distcol <- cbind(Distance=rep(0,nrow(sdata)))
  for(col in names(sdata[,1:(ncol(sdata)-1)])) {
    if (is.factor(sdata[,col])) {
      cat('Categorical Data Column \n')
    } 
    else {
      distcol <- distcol + (sdata[,col]-x[,col])^2
    }
  }
  return((sqrt(distcol)))
}

normal <- function(x) {
	ss <- Map(function(c) c <- (c - min(c))/(max(c) - min(c)), Filter(is.numeric, x))
	replace(x, names(ss), ss)
}

distance <- function(d, x) {
	p <- normal(Filter(is.numeric, rbind(d, x[1,])))
	ssx <- Map(function(n) rep(n, nrow(p)-1), p[nrow(p),])
	sqrt(Reduce("+", as.data.frame((p[1:nrow(p)-1,] - ssx)^2)))
}

