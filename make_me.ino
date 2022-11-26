 // TECHATRONIC.COM  
 // I2C LIBRARY  
 //https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library  
 #include <Wire.h>           
 #include <LiquidCrystal_I2C.h>   
 #include <Servo.h> 
 Servo servo_test;
 LiquidCrystal_I2C lcd(0x27,16,2);   
 int IR1 = 2; // IR Sensor 1    
 int IR2 = 3; // IR Sensor 2  
 int IR3 = 4;
 int IR4 = 5;
 int Slot = 4;      //Enter Total number of parking Slots  
 int flag1 = 0;  
 int flag2 = 0;  
 int flag3 = 0;
 int flag4 = 0;
 int angle = 0;
 int servovalue = 0;
 void setup()  {  
   lcd.init();      
   lcd.backlight();  
   pinMode(IR1, INPUT);  
   pinMode(IR2, INPUT);  
   pinMode(IR3, INPUT); 
   pinMode(IR4, INPUT);   
   servo_test.attach(9);
     
 }  
 void loop(){   
   if(digitalRead(IR1) == LOW && flag1 < 1){
    Slot = Slot-1;
    flag1 = 1;
    
   }
   else if(digitalRead(IR1)== HIGH  && flag1 >= 1){
    Slot = Slot+1;
    flag1 = 0;
   }
   if(digitalRead(IR2) == HIGH && flag2 < 1){
    Slot = Slot-1;
    flag2 = 1;
   }
   else if(digitalRead(IR2) == LOW && flag2 >=1){
    Slot = Slot+1;
    flag2 = 0;
   }
   if(digitalRead(IR3) == LOW && flag3 < 1){
    Slot = Slot-1;
    flag3 = 1;
    
   }
   else if(digitalRead(IR3)== HIGH  && flag3 >= 1){
    Slot = Slot+1;
    flag3 = 0;
   }
   if(digitalRead(IR4) == LOW && flag4 < 1){
    Slot = Slot-1;
    flag4 = 1;
    
   }
   else if(digitalRead(IR4)== HIGH  && flag4 >= 1){
    Slot = Slot+1;
    flag4 = 0;
   }
   
   if(Slot == 0){ 
     lcd.setCursor (0,0);  
     lcd.print("  SORRY  ");  
     
     lcd.setCursor (0,1);  
     lcd.print("Slot Left");  
      lcd.setCursor(12,1);  
      lcd.print(Slot);
      openServo();
      servovalue = 1;
   }
   else{
    lcd.setCursor (0,0);  
    lcd.print("  WELCOME!   ");  
    lcd.setCursor (0,1);  
    lcd.print("Slot Left: ");
    lcd.setCursor(12,1);  
    lcd.print(Slot);
    if(servovalue == 1){
      
      closeServo();
      servovalue = 0;
    }
    
    
   }
   
 } 
 void openServo(){

      servo_test.write(90);


 }
 void closeServo(){
    servo_test.write(0);

 
    
 } 
