//===============================================================================
//  Pin
//===============================================================================
//Inputs:
int nesData       = 21;    // pin Data

//Outputs:
int nesClock      = 22;    // pin Clock
int nesLatch      = 27;    // pin Latch

//===============================================================================
//  Secuencia de inicio
//===============================================================================
void setup() 
{
  // Inicializa el puerto serie a 115200 baudios
  Serial.begin(115200);
  
  // Se inicia el pin Data como entrada
  pinMode(nesData, INPUT);
  
  // Se inician los pines Clock y Latch como salidas
  pinMode(nesClock, OUTPUT);
  pinMode(nesLatch, OUTPUT);
  
  // Se inician las salidas en 0 (GND)
  digitalWrite(nesClock, LOW);
  digitalWrite(nesLatch, LOW);
}

//===============================================================================
//  Programa principal
//===============================================================================
void loop() 
{ 
  leerControlNes();
  delay(150); 
}

//===============================================================================
//  Funciones
//===============================================================================
void leerControlNes() 
{  
    
  //Se activa la lectura del control poniendo un pulso en el pin Latch
  digitalWrite(nesLatch, HIGH);
  delay(5); //debido al reloj moderno del micro hay que poner un delay jejeje para que no supere la velocidad del control 
  digitalWrite(nesLatch, LOW);
  delay(5);
 
  //A 
  if (digitalRead(nesData) == LOW){
    Serial.println("FUNCION = A");
  }

  //B
  digitalWrite(nesClock, HIGH);
  delay(5);
  digitalWrite(nesClock, LOW);
  delay(5);
  if (digitalRead(nesData) == LOW){
    Serial.println("FUNCION = B");
  }
  
  // Select
  digitalWrite(nesClock, HIGH);
  delay(5);
  digitalWrite(nesClock, LOW);
  delay(5);
  if (digitalRead(nesData) == LOW){
    Serial.println("FUNCION = SELECT");
  }
  
  // Start 
  digitalWrite(nesClock, HIGH);
  delay(5);
  digitalWrite(nesClock, LOW);
  delay(5);
  if (digitalRead(nesData) == LOW){
    Serial.println("FUNCION = START");
  }
  
  
  // Arriba
  digitalWrite(nesClock, HIGH);
  delay(5);
  digitalWrite(nesClock, LOW);
  delay(5);
  if (digitalRead(nesData) == LOW){
    Serial.println("FUNCION = UP");
  }
  
  // Abajo
  digitalWrite(nesClock, HIGH);
  delay(5);
  digitalWrite(nesClock, LOW);
  delay(5);
  if (digitalRead(nesData) == LOW){
    Serial.println("FUNCION = DOWN");
  }

  // Izquierda
  digitalWrite(nesClock, HIGH);
  delay(5);
  digitalWrite(nesClock, LOW);
  delay(5);
  if (digitalRead(nesData) == LOW){
    Serial.println("FUNCION = LEFT");
  }
     
  // Derecha
  digitalWrite(nesClock, HIGH);
  delay(5);
  digitalWrite(nesClock, LOW);
  delay(5);  
  if (digitalRead(nesData) == LOW){
    Serial.println("FUNCION = RIGHT");
  }

}
