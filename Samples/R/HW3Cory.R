normal <- function(x) {
	ss <- Map(function(c) (c - min(c))/(max(c) - min(c)), Filter(is.numeric, x))
	replace(x, names(ss), ss)
}

distance <- function(d, x) {
	p <- normal(Filter(is.numeric, rbind(d, x[1,])))
	q <- Filter(is.factor, rbind(d, x[1,]))
	ssx <- Map(function(n) rep(n, nrow(p)-1)   , p[nrow(p),])
	sqrt(Reduce("+", as.data.frame((p[1:nrow(p)-1,] - ssx)^2)))
}

knn <- function(d, x, k) {
	as.numeric(Map(function(row) {
		p <- cbind(d, Distance=distance(d, x[row,]))
		Reduce("+", p[order(p$Distance),][1:k,ncol(p)-1])/k
	}, 1:nrow(x)))
}

kfold <- function(d, k) {
	n <- nrow(d)
	Map(function(i) {
		s <- rep(FALSE, n)
		s[((i-1)*n%/%k+1):(i*n%/%k)] <- TRUE
		sum(knn(d[!s,], d[s,], 5) - d[s,ncol(d)])^2
	}, 1:k);
}