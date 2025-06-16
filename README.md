# Sistema de Iluminação Automática (IoT)

### Tecnologias Utilizadas
**Linguagens:** C++ (para a programação dos microcontroladores), HTML e CSS (para a página de monitoramento).

**Hardware:** Arduino Uno, ESP32, Sensor de Luminosidade (LDR)

Este projeto implementa um sistema de iluminação automática que utiliza um **Arduino Uno** para a lógica de controle e um **ESP32** como servidor web para monitoramento.

O objetivo é acionar um LED (simulando uma lâmpada) quando a luminosidade do ambiente, medida por um sensor LDR, cai abaixo de um certo nível. O status do sistema (LIGADO/DESLIGADO) pode ser visualizado em tempo real em qualquer dispositivo conectado na mesma rede Wi-Fi, através de uma página web servida pelo ESP32.


Esquema de montagem do Sistema de Iluminação Automático:

![image](https://github.com/user-attachments/assets/b3a0c458-1820-4d42-b655-83edd9d067d1)

Montagem do Sistema:

![image](https://github.com/user-attachments/assets/53a464d9-3491-40a6-ba49-bc28d93570a5)

Endereço IP "Sistema Ligado":

![image](https://github.com/user-attachments/assets/e7de4d2d-7764-4535-bd95-4b294ae740b6)


Leitura do LDR do Arduino One no Arduino IDE:

![image](https://github.com/user-attachments/assets/fda22e73-4847-4d0a-a9e4-d8e518f3dfe0)

Imagem LED Ligado (Amarelo à esquerda):

![image](https://github.com/user-attachments/assets/bb9dc618-2786-463f-9b4c-3e113d0fdfcc)

Imagem LED Desligado e Endereço IP "Sistema Desligado"

![image](https://github.com/user-attachments/assets/f3e14626-bf60-4e11-80ae-8568840c8c26)


