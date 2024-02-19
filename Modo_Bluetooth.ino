void BluethoothControl(){

  Serial.println("Modo Bluethoot");
  delay(3000);
  comando = (char)bluetooth.read();
  Serial.println(comando);
    
  if (comando == 'A'){
      
    Serial.println("habilitado");
    delay(100);
    
    do{ 
      Serial.println("Comando");
       comando = (char)bluetooth.read();
      
       if (respaldo != comando){  
          Serial.println(comando);

          if( comando == 'F'){
            moveForward();                   // Nos movemos hacia Adelante
          }
          else if(comando == 'B'){
            moveBackward();                   // Nos movemos hacia Atras 
          }
          else if(comando == 'L'){
            turnLeft();                       // Giramos a la Izquierda 
          }
          else if(comando == 'R'){
            turnRight();                      // Giramos a la derecha 
          }
          else if(comando == 'S'){
            moveStop();                       // Nos detenemos 
          }
        
        }
        else{
          Serial.println("Sin Mudificacion");
        }

      respaldo = comando;          
    }while(comando != 'P');       // Orden para detener el modo Bluetooth
    
    Serial.println("Bucle finalizado Bluethooth");
  }
  else{  // Si no se dio la orden para inicializar el modo 
    Serial.println("No se inicializo Bluethooth");
  }

}