# Smart-Garage-System
## Overview about the project
## *This project simply manages entry and exit from the garage where the entrance and exit gate is closed with a rotating metal barrier*

* > 1- There is a PIR sensor 📼 at the entrance and exit gate ,if a car approaches it, it will 
sense the infrared signal radiation, Signal is sent to the microcontroller that has a car at the 
entrance gate, then the microcontroller checks the number of cars 🚗 inside the garage (because the
garage capacity is only 3 cars) If an empty space is found, it will send a signal to serve motor⏲, turn at + 90 °
and raise it ↖ ,the metal barrier that closed the road 🛣 it  does the 2sec Delay ⏳ until the car gets in
completely and turns back at an  angle of -90 ° ↘ and closes ,The way 🔒 and all the cases are printed on the lcd
and the number of cars inside the garage and whether entry is available or not By the number of cars inside.

* > 2- In case there is no car The entry or exit area of ​​the sensor has a low signal for the microcontroller, so no 
cars will be printed "car number inside equal ... " ,also, permissibility of entry is printed if the number of cars inside is 
less than 3, but if the number inside is 3 cars, then it is printed 
  **"It is not allowed to enter the garage is full "**
  **" Max number of car is only three cars "** 🚫.
 * > 3-In the case of exit, if a car approaches the exit gate The same cycle will occur in one step, the
 sensor will have a High signal for the microcontroller that there is a car at the exit gate, it will be displayed on the LCD that
  **"There is a car at the exit gate"**
Then the servo motor rotates at an angle of + 90 ° in order to raise the metal barrier ↖ and open the
way 🔓Delay by 2sec⏳ until the car comes out, and then the servo rotates at -90 ° so that the metal barrier descends ↘
and closes the road, and the lcd displays the new number of cars inside the garage, the permissibility of entry or nothing, and so on..♻

###  *In addition, I simulate the entry and exit of cars through 3 LEDs entering a car means LED lighting, and leaving the car means turning off the LED*

  *  ### The components used for the interface with the ATmega AVR 32 microcontroller
     > 1- PIR Passive infrared sensor   📼
     > 2- LCD LM32   🖥️
     > 3- Servo motor  
     > 4- logic state  
     > 5- Led   💡
     
