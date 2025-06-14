#include <WiFi.h>
WiFiServer Servidor(80); // Serividor Porta 80

/*Mude para os dados de sua internet e senha*/ 
const char* usuario = "NomeWifi";
const char* senha =  "senha";
#define sinal 34

void setup()
{
  //Define o pino de sinal vindo do Arduino Uno como entrada de dados na esp32 
  pinMode(sinal, INPUT_PULLUP);
  //Configura a taxa de transferência em bits por segundo de 115200 (baud rate) para trnasmissão serial
  Serial.begin(115200);
  conecta_wifi(); //função conecta_wifi
  delay(10);
  
}

//instrução que define o bloco conecta_wifi
void conecta_wifi(){
  //Inicializa a conexão com a internet com a rede e a senha
  WiFi.begin(usuario, senha);

   //Enquanto o status do WIFI for diferente de conectado, escreva na serial "Conectando ao WIFI..."
  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(1000);
    Serial.println("Conectando ao WIFI..");

  } 
  
    {
    //Ao conectar na rede, escreve na serial que o Wifi está conectado e fornece o endereço  Ip da esp32
    Serial.print("Conectado ao WIFI : "); 
    Serial.println(WiFi.localIP());
    //Diz ao servidor para começar a ouvir conexões de entrada
    Servidor.begin();
    }
                    }
  

void loop() 
{
  WiFiClient client = Servidor.available();
  client.println("HTTP/1.1 200 OK"); //resposta de status de sucesso que indica que a requisição foi bem sucedida.
  client.println("Content-Type: text/html");//identificador que informa ao cliente ou servidor HTTP o tipo de mídia ou arquivo do recurso. Neste caso, HTML em texto, tipo de mídia internet.
  client.println(""); //imprime linha em branco
  client.println("<!DOCTYPE HTML>"); //declaração para informar ao navegador qual é a versão do HTML utilizada no arquivo
  client.println("<html lang = 'pt-br'>");
  client.println("<head>"); 
  client.println("<meta http-equiv='refresh' content='1'>");// atualiza pagina 2 seg
  client.println("<meta charset='UTF-8'>"); //especifica a codificação de caracteres e símbolos para o documento HTML
  client.println("<style type = 'text/css'>");
  client.println(".principal{ display:flex; flex-direction:column;align-items:center; background:black; height:2000px}");
  client.println(".centro{width:600px}");
  client.println("h1{color:#fff;}");
  client.println("h2{color:#fff;}");
  client.println("p{color:#fff;}");
  client.println("#ledRed{color:#fff; border: 2px solid #fff; background-color:red; border-radius: 50%; padding: 2.5rem; width: 5rem; height: 5rem; }");
  client.println("#ledGreen{color:#fff; border: 2px solid #fff; background-color:green; border-radius: 50%; padding: 2.5rem; width: 5rem; height: 5rem; }");
  client.println("</style>");
  client.println("</head>");
  client.println("<body>");
  client.println("<main class='principal'>");
  client.println("<div class='centro'>");
  client.println("<h1>Sistema de Iluminação Automática</h1>"); // Título principal da página
  client.println("<h2>Status</h2>"); //Subtítulo da página 

 //Se o sinal for igual a 0, escreve "Sistema desligado" e o led fica vermelho
  if(digitalRead(sinal) == 0) 
  {
    client.println("<p>Sistema DESLIGADO </p>"); // Parágrafo na página
    client.println("<p id ='ledRed'></p>");
  }
// Senão, escreve "Sistema ligado" e o led fica verde
  else
  {
   client.println("<p>Sistema LIGADO </p>"); 
client.println("<p id ='ledGreen'></p>");

 }
  client.println("</div>");
  client.println("</main>");
  client.println("</body>");
  client.println("</html>"); 

delay(10);
  // Se o status do wifi for diferente de conectado, inserir mensagem "Wifi desconectou,..." e executa novamente conecta_wifi();
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wifi desconectou, Reconectando novamente...");
    conecta_wifi();
  }
}  