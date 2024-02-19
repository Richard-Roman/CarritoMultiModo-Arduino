#include <SoftwareSerial.h>        // Libreria para la trasmision de datos por bluetooth
#include <NewPing.h>                // Libreria para el sensor ultrasonico 
#include <Servo.h>                  // Libreria para el Servo

// Definimos los pines del sensor ultrasonico
#define TRIG_PIN A0                 // TRIG en el pin A0
#define ECHO_PIN A1                 // ECHO en el pin A1
// Distancia maxima del sensor ultrasonico
#define MAX_DISTANCE 200     

// Instanciamos un objeto que nos permita controlar el sensor ultrasonico       
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

// Instanciamos un objeto que nos permita controlar el servo    
Servo myservo;

// Definimos los pines del modulo bluetooth  
int bluetoothTx = 6;
int bluetoothRx = 7;

// Instanciamos un objeto que nos permita controlar el modulo bluetooth
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
           
// Configuraciones iniciales para el MotorDriver L298n                                  
const int motor1Input1 = 2;     // Pin de entrada 1 del motor 1
const int motor1Input2 = 3;     // Pin de entrada 2 del motor 1
const int motor2Input1 = 4;     // Pin de entrada 1 del motor 2
const int motor2Input2 = 5;     // Pin de entrada 2 del motor 2

// Declaración de variables  
char Modo;
char comando;
char respaldo; 
int distance = 100;               
boolean goesForward=false;   

void setup() {

  // Configuramos los pines para 2 sensores de linea.
  pinMode(A4, INPUT); // Sensor 1 a pin A4
  pinMode(A5, INPUT); // Sensor 2 a pin A5
  
  // Inicializamos la comunicación por bluetooth
  bluetooth.begin(9600);

  // Inicializamos la comunicación con el monitor serial
  Serial.begin(9600);

  // Definimos los pines del motordriver como salida
  pinMode(motor1Input1, OUTPUT);
  pinMode(motor1Input2, OUTPUT);
  pinMode(motor2Input1, OUTPUT);
  pinMode(motor2Input2, OUTPUT);

  // Configuramos el servomotor
  myservo.attach(9);              // PWM al pin 9
  myservo.write(115);              // VELOCIDAD DEL SERVO.

  // Esperamos 
  delay(2000);

  // Leemos la distancia mediante el sesor ultrasonico
  distance = readPing();

  // Esperamos
  delay(100);
  }

void loop() {

  if (bluetooth.available() > 0){  // Verficamos la conexión

      Serial.println("Conectado --- Modo Autonomo: X  Modo Bluethooth: C  Modo Sigue Lineas: T"); 
      Modo = (char)bluetooth.read(); // Leemos datos recibidos por bluetooth
      
      if (Modo == 'C'){ // Modo Bluetooth
        delay(500);
        Modo = (char)bluetooth.read();
        delay(2000);
        BluethoothControl();
      } 
      else if (Modo == 'X'){ // Modo Autonomo
        delay(500);
        Modo = (char)bluetooth.read();
        delay(2000);
        Autonomo();
      } 
      else if (Modo == 'T'){ // Modo Sigue Lineas
        delay(500);
        Modo = (char)bluetooth.read();
        delay(2000);
        seguidorLinea();
      }
      else{             // Si se recibe por bluetooth cualquier otra letra.
        Serial.println("No Existe este Modo");
      }

   }
   else{                  // Bluetooth sin conexión
     Serial.println("Sin Conexion");
   }

}
