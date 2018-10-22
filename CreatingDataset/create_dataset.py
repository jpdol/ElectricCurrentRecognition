import serial

porta = "/dev/cu.wchusbserialfd120"
velocidade = 9600
conexao = serial.Serial(porta, velocidade)

#Nome do arquivo
nome_arq = 'ElectricCurrentDataset.txt'

#Número de dados de corrente coletadas no domínio do tempo
numero_atributos_preditores = 300

#Número de exemplos a serem construidos
numero_exemplos = 63

#Lista para armazenar os dados da corrente
exemplo = []

#Matriz de exemplos
exemplos = []

# #Instância do atributo-alvo para os exemplos a serem criados
classe = 'Liquidificador'

#Criando os exemplos
for i in range(numero_exemplos):
	#criando cada exemplo
	for j in range (numero_atributos_preditores):
		exemplo.append(float(conexao.readline()))
	exemplos.append(exemplo)
	exemplo = []

try:
	#Lendo arquivo, se existir
	arq = open(nome_arq, 'r')
	texto = arq.read()
	arq.close()
except:
	#Criando arquivo
	arq = open(nome_arq, 'w')
	atributos = ''
	for i in range(numero_atributos_preditores):
		atributos += str(i)+','
	atributos += 'Device\n'
	arq.writelines(atributos)
	arq.close()
	#Settando texto inicial do arquivo
	texto = atributos

#Abrindo arquivo no modo de escrita
arq = open(nome_arq, 'w')

#Acrescentando exemplos ao texto do arquivo
for i in exemplos:
	for j in i:
		texto+=str(j)+' '
	texto+='\n'

#Formatando o arquivo para o padrao csv
for i in range(len(texto)):
	if texto[i]==' ':
		texto=texto.replace(texto[i], ',')
texto_aux=''
for i in range(len(texto)):
	if texto[i] == '\n' and texto[i-1] == ',':
		texto_aux += classe + '\n'
	else:
		texto_aux += texto[i]

#Atualizando o texto do arquivo
texto = texto_aux
arq.writelines(texto)
arq.close()