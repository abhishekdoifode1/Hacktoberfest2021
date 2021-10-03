# Radial-Basis Function Distance-Weighted Nearest Neighbors

euclidean <- function(x, q) { #calculo da distancia euclidiana: raiz quadrada do somat�rio do quadrado de exemplo - query
	sqrt(sum((x-q)^2))
}

gaussianKernel <- function(dist, sigma) { #calculo da fun��o kernel radial (gaussiana)
	exp(-dist^2/(2*sigma^2)) #e elevado a -(distancia�/2*sigma�)
}

dwnn <- function(base, query, sigma = 1) { #base = exemplos, sigma � da fun��o gaussiana

	nAttrs = ncol(base)-1 
	class = ncol(base)

	num = 0 #numerador da fun��o de c�lculo do Distance Weighted Nearest Neighbors vers�o cont�nua com kernel gaussiano (radial)
	den = 0 #denominador da fun��o de c�lculo do Distance Weighted Nearest Neighbors vers�o cont�nua com kernel gaussiano (radial)

	for (i in 1:nrow(base)) { 
		
		#calculo parcial da classifica��o: faz os somat�rios presentes no numerador e denominador da fun��o
		#fun��o denotada por: 
		#classifica��o = (somat�rio, pra todos exemplos, do peso X classe do exemplo)/(somat�rio, pra todos exemplos, do peso)

		dist = euclidean(base[i,1:nAttrs], query) #calcula a dist�ncia euclidiana do exemplo com a query
		w = gaussianKernel(dist, sigma) #calcula o peso a partir da fun��o gaussiana

		num = num + w * base[i, class] 
		den = den + w
	}

	gox = num / den #classe da query

	gox
}

test <- function(sigma=1) {
	b = read.table("../datasets/logistic/logistic-3.8.dat")
	test = read.table("../datasets/logistic/logistic-test.dat")
	ver = read.table("../datasets/logistic/logistic-test-verificar.dat")

	print(cbind(test, ver))

	input = test[1,]

	allResults = c()
	for (i in 1:10) {
		result = dwnn(b, input,sigma)
		allResults = c(allResults, result)
		input = result
	}

	ts.plot(cbind(ver))
	points(allResults, col=2)
}
