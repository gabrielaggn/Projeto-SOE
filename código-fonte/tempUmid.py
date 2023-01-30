#Desenvolvido para o projeto de SOE, UnB - GAMA. ALUNAS : GABRIELA GOES e PAMELA CAMPAGNUCCI
import Adafruit_DHT
import RPi.GPIO as GPIO
import time
 
# Define o tipo de sensor
sensor = Adafruit_DHT.DHT11
#sensor = Adafruit_DHT.DHT22
 
GPIO.setmode(GPIO.BOARD)
 
# Define a GPIO conectada ao pino de dados do sensor
pino_sensor = 4
 
# Informacoes iniciais
print ("*** Lendo os valores de temperatura e umidade");
 
# Efetua a leitura do sensor
umid, temp = Adafruit_DHT.read_retry(sensor, pino_sensor);
# Caso leitura esteja ok, mostra os valores na tela
if umid is not None and temp is not None:
    with open('dadostempumid.txt', 'w') as arquivo:
        print("Temperatura = {0:0.1f} C  Umidade = {1:0.1f} %".format(temp, umid), file=arquivo)
    
else:
	# Mensagem de erro de comunicacao com o sensor
	print("Falha ao ler dados do DHT11 !!!")
