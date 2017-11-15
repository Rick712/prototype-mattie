# prototype-mattie
Welcome to the online manual to make an prototype for Mattie: a smart mattress. 
For this prototype, you'll need:
- A NODEMCU ESP8266MOD with USB cabel
- A servomotor
- A 3-pin on/off button
- A sponge
- 5 female to female cabel connectors
- Scissors
- Tape

### Step 1: Cutting the sponge
First, cut the sponge halfway through the middle in the side, and make a hole in it. Make sure the button fits right in it.
Then, cut a small hole for the servomotor. 

### step 2: Putting the hardware into place
Connect the servomotor and the button with one end to a female to female cabel connectors. It doesn't need to be connected to the NODEMCU, we'll get to that later.
When they have one side of the cabels connected, put them in de spots you just cut open. When they are in place, make sure you can press the button on top of the sponge. When everything fits, tape them, so they don't fall out the sponge.

### step 3: Connecting to the NODEMCU
Now comes the tricky part. The button (as descriped) has 3 pins: an 3 VOLT INPUT, a SIGNAL OUTPUT and a GROUND. From top to bottom, the pins are signal, 3v and ground. Connect the 3v button to the 3v3 pin in the NODEMCU, the signal to D1 and the ground to ground.
Some buttons work differently than others, so your button could be working differently. We'll come to that in a second*
The servomotor has only 2 pins: a + and a -. Red is + and black is -. Connect the + to D2, and the - to ground.

### step 4: Uploading the code
This is the easy part. All you have to do is take the code, and upload it to your NODEMCU. If you don't quite understand what the code does, there are a lot of comments in the code. Everything that happens has a comment, so you can easily learn how the code works.

Here is the code:

```[15:30, 15-11-2017] Rick Buter: // If you want to make a variable that will not change, you need to put const before int
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

// And done, it's a piece of cake```

### step 5: Let the magic happen
When you're done uploading the code, there won't happen much. When you press the button longer than 1 second, the sponge will start vibrating. When you release the button, the sponge will stop vibrating.

*If your button does work differently, you'll notice that nothing will happen when you press it. Start switching your cables with eachother. There are only 6 combinations of possible ways the pins work, so it shouldn't be that hard finding out how your buttons work
