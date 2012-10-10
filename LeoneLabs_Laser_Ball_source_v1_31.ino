//Laser Ball source code v1.3
//LeoneLabs 2011
//mleone@leonelabs.com
//www.leonelabs.com

//Overview: 
//The code will animate the lasers in the Laser Ball and interpret IR signals from a 
//remote control to change patterns and their animation speed.

//Tutorials:
//Interrupts - http://www.arduino.cc/en/Reference/AttachInterrupt
//IR remote - http://www.arcfn.com/2009/08/multi-protocol-infrared-remote-library.html

//Hardware:
//Mini remote control - https://www.adafruit.com/products/389
//IR sensor - https://www.adafruit.com/products/157

//The codes use IR remote code from Ken Shirriff (see footer)
//Install the libraries by following "IR remote" tutorial above

#include <IRremote.h>
#include <avr/pgmspace.h>

//IR remote globals
int RECV_PIN = 5;
IRrecv irrecv(RECV_PIN);
decode_results results;
int pat_select;

//Interrupt globals
int int0 = 0; //interrupt 0 is on pin 5 on the Teensy;
volatile int state = LOW; //'volatile' is necessary for interrupts

//Lasers globals
int n_lasers = 14;
int laser[] = {23,16,15,10,8,7,9,14,13,12,11,22,6,4};//remaps the Teensy pin numbers to consecutive laser numbers

//animation globals
unsigned long j=0;
int frame_offset=0;
unsigned long frame_length = 20;
int frame_count = 6;
unsigned long loop_length = frame_count*frame_length;

//preset patterns - storing in flash memory requires "prog_uint16_t" datatype, "extern" means the initializations are in the other tab
//to make a new pattern go to "preset_patterns" tab, create an array like laser_frames[] and add it to the pointer array seq_select[] and array seq_length[]
extern prog_uint16_t  laser_frames1[];
extern prog_uint16_t  laser_frames2[];
extern prog_uint16_t  laser_frames3[];
extern prog_uint16_t  laser_frames4[];
extern prog_uint16_t* seq_select[]; 
extern int seq_lengths[];
extern int seq_count;

prog_uint16_t laser_pixels[1000]; //pixel buffer, gets animated in the main loop
                     
void setup()
{
  //IR setup
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pat_select = 0;
  
  //Interrupt setup
  attachInterrupt(int0,stateChange,CHANGE);
  
  //Laser setup
  for (int i=0;i<n_lasers;i++){
    pinMode(laser[i],OUTPUT);
  }
  //other pin setup
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(21,OUTPUT);
  
}

void loop() {
  //main animation loop
  frame_offset=0; 
  for (int j=0;j<loop_length;j++){ //loop length is in units of "cycles" 
      int IR_status=state; //for checking IR button presses
      
      load_sequence(seq_select[pat_select],laser_pixels,seq_lengths[pat_select]/sizeof(int)); //loads each "frame" ("laser_frames[]") into pixel buffer ("laser_pixels[]")
      
      for (int i=0;i<(n_lasers);i++){ //"draws" the frame
        if (laser_pixels[i+frame_offset]==1) digitalWrite(laser[i],HIGH);
        else digitalWrite(laser[i],LOW);
      }
      
      if (j%(frame_length)==frame_length-1) frame_offset+=n_lasers; //move to the start address of the next frame 
     
      if (state!=IR_status) break; //"state" is tied to the external interupt so pressing a remote button press will exit the loop
  }
}
//Load frame sequence
void load_sequence(prog_uint16_t  source[], prog_uint16_t destination[], int pixel_count){
  for (int i=0;i<(pixel_count);i++){
    destination[i]=pgm_read_word_near(&source[i]);
  }
  loop_length=pixel_count/n_lasers*frame_length;
}
//Interrupt function
void stateChange(){
  if (irrecv.decode(&results)) { //decode incoming IR signal and store in 'results'
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
  
  switch(results.value){  
      case 0xFD00FF:
      {
        Serial.println("VOL-"); //useful for debug
        if (frame_length>100) frame_length-=100;
        loop_length = frame_count*frame_length;
        results.value = 0x00;
      }
      break;
      case 0xFD40BF:
      {
        Serial.println("VOL+");
        frame_length+=100;
        loop_length = frame_count*frame_length;
        results.value = 0x00;
      }
      break;
      case 0xFDA05F:
      {
        Serial.println("UP");
        if (pat_select < seq_count-1)  pat_select++;
        results.value = 0x00;
      }
      break;
      case 0xFDB04F:
      {
        Serial.println("DOWN");
        if (pat_select>0) pat_select--;      
        results.value = 0x00;
      }
      break;
          
  }
  state = !state;
}

/*FOOTER*/
/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
*/
