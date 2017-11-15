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

### step 5: Let the magic happen
When you're done uploading the code, there won't happen much. When you press the button longer than 1 second, the sponge will start vibrating. When you release the button, the sponge will stop vibrating.

*If your button does work differently, you'll notice that nothing will happen when you press it. Start switching your cables with eachother. There are only 6 combinations of possible ways the pins work, so it shouldn't be that hard finding out how your buttons work
