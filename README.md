<pre> web-app by AFNAN <br></pre>
### arduino code
```c
// arduino code

#include <Servo.h>

Servo motor;

int sensor_pin = 4;
int motor_pin = 5;

void setup() {
    pinMode(sensor_pin, INPUT);
    motor.attach(motor_pin);
}

void loop() {
    int val = digitalRead(sensor_pin);
    if(val == 0) {
        motor.write(0);
    }
    if(val == 1) {
        motor.write(180);
    }
}

```
### code explanation
```c
// arduino code
```
<pre> which is a comment </pre>
<br>

```c
#include <Servo.h>
```
<pre>includes library to control servo motor
</pre><br>

```c
Servo motor;
```
<pre> create motor object to control the servo motor </pre><br>

```c
int sensor_pin = 4;
int motor_pin = 5;
```

<pre>create two variables for raindrop sensor and servo motor<br>and assigning values to which pin they are connected</pre><br>

### arduino

<pre>an open source programmable circuit board and microcontroller<br>that makes it possible for anyone to build digital hardware products

- most popular model : UNO<br>
- microcontroller
  small inexpensive computer that can run on low power<br>  board is surrounded by pins that can be used to
  construct a circuit by connecting various input and output devices<br>
- USB port
  used to upload code to the device<br>
- software : sketch
  writren in purpose-built easy to learn programming language<br>  every program has 2 basic functions<br>
  1) setup()
     setup runs once, when the hardware is first powered on<br>
  2) loop()
     loop runs continuously to react to signals from input devices or
     changes to the state of program 

  used to build IoT products, robots, wearable devices, ...
   </pre>

   ### servo motor

   <pre> ... </pre>

   ### rain drop sensor

   <pre> ... </pre>

   ### ESP32 Web-Server

   <pre> ... </pre>
