// If you want to make a variable that will not change, you need to put const before int
// These variables wont change, so you need to put const in front of it
const int button = D1;
const int servoMotor = D2;

// These variables will change, so only int is enough
int buttonOutput = 0;

void setup() {
  
  // Here we put our pins that we'll use. Always begin with Serial.begin(115200) 
  // NOTE: the number between the () can be different if you don't use a NODEMCU EPS8277MOD
  Serial.begin(115200);
  
  // Here we declare the pins. For each pin that we'll need the value from, we declare
  // We need the output from the button and the input for the motor, so we declare them here
  pinMode(button, INPUT);
  pinMode(servoNotor, OUTPUT);
  
}

void loop() {
  // First we change buttonOutput into the signal that the button sends out (HIGH or LOW)
  buttonOutput = digitalRead(button);
  
  // Then we create an if/else statement, which checks if the output of the button is LOW 
  // (If you dont press the button, it will send out HIGH
  if (buttonOutput == LOW) {
    
    // If you want to, you can add a delay. This is not neccesary. This delay determines how long it will take for the servomotor to start vibrating
    delay(2000);
    
    // Then, if the putton is pressed, we'll send voltage to the servomotor
    digitalWrite(servoMotor, HIGH);
    
  } 
  
  else {

    // This part declares what the NODEMCU will do if the button is not pressed
    // Here we fill in that the servomotor is off when the button is not pressed
    digitalWrite(servoMotor, LOW);
    
  }

  // Add a small delay so the loop does not excecute a thousend times per second
  delay(100);
  
} 

// And done, it's a piece of cake
