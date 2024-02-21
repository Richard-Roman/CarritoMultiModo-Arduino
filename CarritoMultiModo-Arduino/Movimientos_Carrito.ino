void moveStop() {                       // Detenemos el carrito
  
  Serial.println("Detenerse");
  digitalWrite(motor1Input1, LOW);
  digitalWrite(motor1Input2, LOW);
  digitalWrite(motor2Input1, LOW);
  digitalWrite(motor2Input2, LOW);

} 
  
void moveBackward() {                   // Movemos el carrito hacia atrás

  Serial.println("Atrás");
  digitalWrite(motor1Input1, HIGH);
  digitalWrite(motor1Input2, LOW);
  digitalWrite(motor2Input1, HIGH);
  digitalWrite(motor2Input2, LOW);  
  
}

void moveForward() {                    // Movemos el carrito hacia adelante

  Serial.println("Adelante");
  digitalWrite(motor1Input1, LOW);
  digitalWrite(motor1Input2, HIGH);
  digitalWrite(motor2Input1, LOW);
  digitalWrite(motor2Input2, HIGH);      
  
}  

void turnRight() {                      // Giramos el carrito hacia la derecha y luego avanzamos

  Serial.println("Derecha");
  digitalWrite(motor1Input1, HIGH);
  digitalWrite(motor1Input2, LOW);
  digitalWrite(motor2Input1, LOW);
  digitalWrite(motor2Input2, HIGH);   
  delay(100);
  moveForward();      
  
} 
 
void turnLeft() {                      // Giramos el carrito hacia la izquierda y luego avanzamos

  Serial.println("Izquierda");
  digitalWrite(motor1Input1, LOW);
  digitalWrite(motor1Input2, HIGH);
  digitalWrite(motor2Input1, HIGH);
  digitalWrite(motor2Input2, LOW);    
  delay(100);
  moveForward();

}