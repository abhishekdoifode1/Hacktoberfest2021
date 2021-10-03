
f <- function(net, threshold = 0.5) {
	if (net > threshold) {
		return (1)
	} else {
		return (0)
	}
}

f_multiple_values <- function(nets, threshold = 0.5) {
	ret = nets
	ret[nets > threshold] = 1
	ret[nets <= threshold] = 0

	ret
}

perceptron <- function(dataset, eta = 0.1, epsilon = 0.0001) { #começa o código do perceptron

	# o = sum(input_i * weight_i) + theta
	# f(o) = f(sum(input_i * weight_i) + theta)

	answer = ncol(dataset)
	nAttrs = ncol(dataset) - 1

	weights = runif(min=-1, max=1, n=nAttrs+1) #seta um vetor de pesos de número igual ao número de entradas + theta

	error = epsilon + 1 #erro = epsilon + 1 (só pra entrar no while)
	while (error > epsilon) { #enquanto erro for maior que o epsilon
	   error = 0 #zera o erro

	   # para cada exemplo existente dentro do dataset, calcula o erro do exemplo, adiciona no erro total, atualiza os pesos 
	   for (j in 1:nrow(dataset)) {

		# aplique o perceptron
		net = 0 #função net recebe zero
		for (i in 1:nAttrs) { #para cada entrada (x1, x2, x3...)
			net = net + dataset[j,i] * weights[i] #net soma o xi * wi com seu valor
		}
		net = net + 1 * weights[nAttrs+1] # bias (theta)

		output = f(net) #output recebe o f(net), que possui um threshold para arredondamento em 0 ou 1

		# treinamento
		# w_i(t+1) = w_i(t) - eta * dE/dw_i
		# dE/dw_i = 2 * (esperada - obtida) * -entrada

		error = error + (dataset[j,answer] - output)^2 #calcula o erro: sum((esperado - obtido)^2)

		for (i in 1:nAttrs) { #pra cada peso
			dEdwi = (dataset[j,answer] - output) * -dataset[j,i]    #(y - o)(-xi)
			weights[i] = weights[i] - eta * dEdwi    #wi = wi -eta*(y-o)(-xi)
		}
		
		#o mesmo para o theta
		dEdwi = (dataset[j,answer] - output) * -1    
		weights[length(weights)] = weights[length(weights)] - eta * dEdwi

		# terminei o treinamento

		print(dataset[j,]) 
		cat(paste("\tsaida obtida: ", output, "\n"))
	   }
	}

	weights
}

plot.perceptron <- function(weights) {
	x = seq(0,1,len=100)
	result = f_multiple_values(outer(x, x, function(x,y) { 
		       cbind(x, y, rep(1,100)) %*% weights; } ))
	filled.contour(x, x, result)
}
