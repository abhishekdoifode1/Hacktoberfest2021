# Radial-Basis Function Distance-Weighted Nearest Neighbors

euclidean <- function(x, q) { #calculo da distancia euclidiana: raiz quadrada do somatório do quadrado de exemplo - query
	sqrt(sum((x-q)^2))
}

gaussianKernel <- function(dist, sigma) { #calculo da função kernel radial (gaussiana)
	exp(-dist^2/(2*sigma^2)) #e elevado a -(distancia²/2*sigma²)
}

dwnn <- function(base, query, sigma = 1) { #base = exemplos, sigma é da função gaussiana

	nAttrs = ncol(base)-1 
	class = ncol(base)

	num = 0 #numerador da função de cálculo do Distance Weighted Nearest Neighbors versão contínua com kernel gaussiano (radial)
	den = 0 #denominador da função de cálculo do Distance Weighted Nearest Neighbors versão contínua com kernel gaussiano (radial)

	for (i in 1:nrow(base)) { 
		
		#calculo parcial da classificação: faz os somatórios presentes no numerador e denominador da função
		#função denotada por: 
		#classificação = (somatório, pra todos exemplos, do peso X classe do exemplo)/(somatório, pra todos exemplos, do peso)

		dist = euclidean(base[i,1:nAttrs], query) #calcula a distância euclidiana do exemplo com a query
		w = gaussianKernel(dist, sigma) #calcula o peso a partir da função gaussiana

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
