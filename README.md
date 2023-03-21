# Function Generator
A Compact Cost Effective Function Generator based on 8051.

During modern times wireless digital communication plays a major role in everyone life. For digital communication between two devices, we use pulse signal and for wireless medium communication we modulate pulse signal to sinusoidal wave. For testing various system, there is a need of various type of waveform. Therefore, there is a need of the device which come in handy to perform all these operation with much ease and it is also affordable. The proposed device can generate a pulse wave, sinusoidal wave, ramp signal and Amplitude modulation signal frequency can be varied using buttons. An LCD 16 x 2 display will confirm the type of signal at output.

# How to Set it up

### Step 1 - Hardware 

You can go through the schematic I have uploaded to setup the hardware components.
We will be needing the following components
1. An **8051**, with a development kit / any device to dump code into it.
2. A 8 channel digital to analog converter ( **DAC0808 IC** ).
3. A **Keypad** and a **LCD** as input and output system.

 **The Analog out of the DAC will be our waveform output.**
 
_Before setting up the hardware components, you can test out the code using a simulation software such as **Proteus**, or directly use **Keil uVision 5** to verify the output with manual port inputs_

### Step 2 - Dumping the Code

Once the hardware is setup, and the code is verified and compiled, we use Keil uVision 5 to generate a Hex File for our code.

I have added a hex file in the repository. _**The file was generated based on a clock frequency of 11.0592 Mhz**_ make sure your device has the same clock frequency. If not generate it manually by setting up your frequency in the build context.

Dump the code into the MCU using device specif software ( I used flash magic ).

### Step 3 - Booting up & controlling the generator

Reset the MCU and the device will be ready.

The function generator has 8 different frequency options. These can be manually controlled using 3 pins of port 0. 
Based on the requirement, the keypad can be setup to control these pins.
![image](https://user-images.githubusercontent.com/125025955/226567002-027258ad-1b99-4977-96f9-90e530798137.png)

The Waveform option can be manually selected using the pins 4,5,6 of port 0.
Based on the requirement, the keypad can be setup to control these pins.

![image](https://user-images.githubusercontent.com/125025955/226567624-a71f8a80-ad40-4966-8504-e7c58dbeff96.png)

**Specifications**
1. The maximum frequency generated for sine wave in 8051 is 7 kHz
2. The maximum frequency generated for sawtooth wave in 8051 is 6.5 kHz
3. The maximum frequency generated for triangle wave in 8051 is 3.25 kHz
4. The maximum frequency generated for square wave generated in 8051 is 200 kHz
5. The maximum carrier frequency generated for amplitude modulated wave in 8051 is 11.52 kHz and message signal of 564.7 Hz

**Waveforms examples**

![image](https://user-images.githubusercontent.com/125025955/226568164-71d6fccf-b284-4a02-91c3-662f662174b1.png)

![image](https://user-images.githubusercontent.com/125025955/226568193-dbd29f39-be80-4898-8642-1cdab07ac7ab.png)

![image](https://user-images.githubusercontent.com/125025955/226568582-58b121b5-2000-4b02-baf7-5eafaecd8836.png)

![image](https://user-images.githubusercontent.com/125025955/226569168-0268dbad-30a8-45e1-b69d-04ed1795cd38.png)

These were few of the waveforms I was able to acheive.

Feel free to contact me if you have any doubts.

Thank you

