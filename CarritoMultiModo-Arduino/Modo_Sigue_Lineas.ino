void seguidorLinea() {

  Serial.println("Modo Seguidor de Linea");
  delay(3000);
  comando = (char)bluetooth.read();
  Serial.println(comando);

  if (comando == 'A'){ // Orden para iniciar el modo sigue Lineas
    
    do{
      
      int LEFT_SENSOR = digitalRead(A4);  // Sensor 1 - Izquierdo
      int RIGHT_SENSOR = digitalRead(A5); // Sensor 2 - Derecho
      
      if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 0) {
        Serial.print("Ir hacia adelante");
        Serial.println(LEFT_SENSOR);
        Serial.println(RIGHT_SENSOR);
        moveForward(); // Moverse hacia Adelante
      } 
      else if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 1) {
        Serial.print("ir izquierda");
        Serial.println(LEFT_SENSOR);
        Serial.println(RIGHT_SENSOR);
        turnLeft(); // Girar a la derecha
      } 
      else if (RIGHT_SENSOR == 1 && LEFT_SENSOR == 0) {
        Serial.print("ir derecha");
        Serial.println(LEFT_SENSOR);
        Serial.println(RIGHT_SENSOR);
        turnRight(); // Girar a la izquierda
      } 
      else if (RIGHT_SENSOR == 1 && LEFT_SENSOR == 1) {
        Serial.print("Detenerse");
        Serial.println(LEFT_SENSOR);
        Serial.println(RIGHT_SENSOR);
        moveStop();  // Detenerse
      }

      comando = (char)bluetooth.read();

    }while(comando != 'P');  // Orden para detener el modo sigue Lineas
    
    moveStop(); 
    Serial.println("Modo terminado terminado");
    
  }
  else{ // Si no se dio la orden para inicializar el modo 
    Serial.println("No se Inicializo");
 }

}