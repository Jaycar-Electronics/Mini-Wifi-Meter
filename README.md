# Mini Wi-Fi Meter
_Test and Measure_
### Author: D.West.

:+1:

This handy little tool can be used to check for any Wi-Fi signals around, use it to see how well the connection in your workshop is going or to see if there’s any free Wi-Fi hotspots when you’re out and about. Using the beloved esp8266 we’ve attached a screen and let it run off 2 AA batteries. The screen is suited for 5v but it tries (and succeeds) at running at the lower voltage. You could even use rechargeable AA batteries in this one.

##### Important!
This will not work automatically off the arduino software without prior set up.

You must set up the IDE to program the ESP8266 before the source code will work. You can read it in the manual on the downloads tab for [XC3802](https://jaycar.com.au/p/XC3802)

## Bill of Materials

|Qty|	Code|	Description|
|---:| ---|---|
|1|[XC3802](https://jaycar.com.au/p/XC3802)|Our favorite device the ESP8266|
|1|[PH9280](https://jaycar.com.au/p/PH9280)|2AA Switched Battery Holder|
|1|[XC4384](https://jaycar.com.au/p/XC4384)|OLED Module|
| | | Some spare leads or wires|
| | | Mounting screws and or hot-glue|

## Connection table


| ESP8266 | OLED | Battery Pack |
| :--- | :--- | --- |
| D2 | SDA | |
| D1 | SCL | |
| Ground | Ground | Black |
|5V | VCC | |
|3v3 | | Red |

We connect the OLED because it's the closest, and provides the 3.3v pass through. You won't get a 5v supply unless a USB cable is connected.

## Assembly

The easiest way to assemble is to get some spare resistors or components and snip the leads off, then with the leads, make 3 “U” shapes using a pair of pliers.

There should be 4 connections between the two boards and they should be held together fairly strongly. You are trying to emulate a cross pattern over two sets of pins. Below is a diagram of the idea, you can picture it as green on the top side of the board and blue on the other.

![kris cross pattern](images/eagle_schematic.png)
_Line up the two boards so they're neat on the battery compartment, then use metal leads to form the connections_

It can be a bit hard to mount the ESP in a “straight” manner, but it can make nice diagonals with the U-shapes. Position the ESP and OLED on the bench with SDA and D1 lined up. Note that we’re not connecting SDA to D2, not D1, so use the previously built “U” shape to cross over and solder it in place, keeping alignment.

![alt text](images/IMAG0323.jpg)
_forgive the out of focus_

Then flip the unit over, and solder the next U shape over SCL and D1.

Use the last U shape to connect the ground to each other. The lead from the battery pack will come up and wrap around the middle of the U shape so leave some room there if needed.

Next, get another lead from a resistor and bend one end of it at a 90-degree angle, put into VCC to check where to make another 90-degree bend, so you should have a much wider “U” shape. Snip to size and solder it in.

Run the battery leads up under where the modules are supposed to go, then place the modules over the wires so you can measure up where the wires are meant to come to. Position the modules so that the top of the OLED is pretty close to the slit on the battery compartment. Flip open the modules while keeping the wires in place, then snip and strip the wires to size so that the red wire goes in 3v3 and the black wire goes to the aforementioned ground U connection.

Finally, check that the modules can be placed correctly, and use some small self-tapping screws to fix the OLED to the battery compartment. (TIP: [TD2089](https://jaycar.com.au/p/TD2089) is great for drilling pilot holes and is highly, highly recommended.)  check the clearance in the battery compartment, as depending on your screws, they might not make room for the batteries. Use a heavy duty pair of pliers to snip the underside of the screws and to give your batteries a bit more room.

## Programming

The complete source code is available [here](https://github.com/duinotech/Mini_Wifi_Meter/archive/master.zip)

Remember to change your Arduino environment to run the ESP8266, as specified in the [manual](https://www.jaycar.com.au/p/XC3802)

## Use
Simply plug in two AA batteries and switch the unit on. You should see text being displayed before a list of Wi-Fi networks show and their signal strength.
