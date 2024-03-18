<pre> web-app by AFNAN <br></pre>
### arduino code
```ino
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
    else {
        motor.write(180);
    }
}

```
### code explanation
```ino
// arduino code
```
<pre> which is a comment </pre>
<br>

```ino
#include <Servo.h>
```
<pre>includes library to control servo motor
</pre><br>

```ino
Servo motor;
```
<pre> create motor object to control the servo motor </pre><br>

```ino
int sensor_pin = 4;
int motor_pin = 5;
```

<pre>create two variables for raindrop sensor and servo motor<br>and assigning values to which pin they are connected</pre><br>

```ino
void setup() {
    pinMode(sensor_pin, INPUT);
    motor.attach(motor_pin);
}
```
<pre>setup() runs once, when the hardware is first powered on<br>
pinMode - configures the specified pin to behave either as an input or an output<br>syntax : pinMode(pin, mode)<br>
.attach - attach variable to a pin<br> syntax : servo.attach(pin)</pre><br>

```ino
void loop() {
    int val = digitalRead(sensor_pin);
    if(val == 0) {
        motor.write(0);
    }
    else {
        motor.write(180);
    }
}
```
<pre>loop runs continuously to react to signals from input devices<br>or changes to the state of program<br>
digitalRead() - reads the value from a specified digit pin, either HIGH or LOW<br>syntax : digitalRead(pin)<br>
.write() - writes a value to the servo, controlling the shaft accordingly, set the angle in degrees<br></pre>
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
