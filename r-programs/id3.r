
dataEntropy <- function(dataset) {

	# Se restou apenas um exemplo, entropia = 0
	if (is.vector(dataset)) {
		return (0)
	}

	# calcular entropia dos dados
	answer = ncol(dataset) #numero da coluna de respostas (nesse caso, ultima coluna)
	options = unique(dataset[,answer]) #cria um vetor com as opções do atributo resposta

	counting = c() #instancia contador
	for (i in 1:length(options)) {
		#conta quantas incidências ocorrem pra cada opção
		counting = c(counting,
			     sum(dataset[,answer] == options[i]))
	}

	prob = counting / sum(counting) #vetor com as probabilidades de ocorrencia de cada opção (counting/total)
	H = -sum(prob[!is.nan(prob)] * log2(prob[!is.nan(prob)])) #calculo de E(S) -> E(S) = sum(opcao/total log2 opcao/total)

	H
}

informationGain <- function(dataset, attrId) {

	E_S = dataEntropy(dataset) #calcula a entropia E(S)

	# calcular o ganho
	# Panorama = c(Nub, Chuv, Ens)
	options = unique(dataset[,attrId]) #cria um vetor com as opções daquele atributo(coluna)

	sum = 0
	for (i in 1:length(options)) {
		#faz a proporção entre o número de opções e o total de colunas 
		proportion = 
		   sum(dataset[,attrId] == options[i]) / nrow(dataset)
		
		rowIds = which(dataset[,attrId] == options[i]) #guarda quais linhas possuem a opção da posição i
		E_S_A_v = dataEntropy(dataset[rowIds,]) #calcula a entropia condicional daquela opção
		sum  = sum + proportion * E_S_A_v #calculo do somatório das entropias condicionais
	}

	IG = E_S - sum #calcula o ganho de informação, da forma IG = E(S) - sum(Sv/S*E(Sv))

	IG
}

id3_test <- function(node, example) {

	if (node$selectedAttrId == -1) {
		return(node$answer)
	}
	
	value = example[node$selectedAttrId]
	childId = which(node$options == value)
	id3_test(node$children[[childId]], example)
}

# algoritmo de arvores de decisao (Quinlan)
id3 <- function(dataset) {

	dataset = as.matrix(dataset) #transforma table dataset em matriz

	root = list() #cria objeto raiz
	root$data = dataset #passa para a variável data a matriz
	nAttrs = ncol(root$data)-1 #considera o número de atributos menos o que possui a resposta
	root$eligibleAttrs = seq(1, nAttrs) #lista atributos

	root = id3_recursive(root) 

	root
}

id3_recursive <- function(node) {

	selectedAttrId = -1 
	maxGain = 0

	# computando o ganho de informacao
	for (i in 1:length(node$eligibleAttrs)) { 
		attrId = node$eligibleAttrs[i] #seleciona o atributo elegível de posição i
		gain = informationGain(node$data, attrId) #calcula o ganho de informação dele
		
		#se for maior que o ganho anterior, seleciona 
		if (gain > maxGain) {
			selectedAttrId = attrId
			maxGain = gain
		}
	}

	# definindo qual atributo foi selecionado
	node$selectedAttrId = selectedAttrId

	# condicao de parada do algoritmo, pois entropia = 0 (se entropia = 0, então dá a resposta única à folha
	if (node$selectedAttrId == -1) {
		answerId = ncol(node$data) #pega a última coluna (coluna resposta)
		node$answer = unique(node$data[,answerId])[1] #atribui a resposta localizada naqueles nós
		return (node)
	}

	# definindo as opcoes ou valores para aquele atributo que permitem definir os filhos
	node$options = unique(node$data[, node$selectedAttrId]) #pega os valores disponíveis na coluna do atributo selecionado para o nó
	node$children = list() #cria um filho

	#para todas as opções dentro do nó, faça
	for (i in 1:length(node$options)) {
		# montando arvore para filho
		newnode = list() #cria um novo nó
		thisOption = node$options[i] #atribui a opção desse ciclo 
		rowIds = which(node$data[,node$selectedAttrId] == thisOption) #seleciona as colunas que se relacionam com aquela opção

		# realizando um corte nos exemplos
		newnode$data = node$data[rowIds,] #atribui à $data do filho apenas as colunas que têm apenas o valor option [i]
		newnode$eligibleAttrs = setdiff(node$eligibleAttrs, node$selectedAttrId) #seta nos atributos elegíveis do filho os atributos listados menos o empregado nesse nó

		node$children[[i]] = newnode 
	}

	for (i in 1:length(node$options)) {
		node$children[[i]] = id3_recursive(node$children[[i]]) #chama id3 recursivo pra cada filho
	}

	return (node)
}
