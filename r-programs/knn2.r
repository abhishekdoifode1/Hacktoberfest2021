
euclidean <- function(x, q) {
	ret = sqrt(sum((x - q)^2))
	ret
}

knn <- function(base, query, k=3) {

	nAttrs = ncol(base)-1
	classAttr = ncol(base)

	distances = c()

	for (i in 1:nrow(base)) {
		distances = c(distances, euclidean(base[i,1:nAttrs], query))
	}

	# ordenar as distancias
	ids = sort.list(distances)[1:k]
	classes = base[ids,classAttr]

	result = sum(classes) / k

	result
}

test <- function() {
	b = read.table("../datasets/logistic/logistic-3.8.dat")
	test = read.table("../datasets/logistic/logistic-test.dat")
	ver = read.table("../datasets/logistic/logistic-test-verificar.dat")

	print(cbind(test, ver))

	input = test[1,]

	allResults = c()
	for (i in 1:10) {
		result = knn(b, input)
		allResults = c(allResults, result)
		input = result
	}

	ts.plot(cbind(ver))
	points(allResults, col=2)
}
