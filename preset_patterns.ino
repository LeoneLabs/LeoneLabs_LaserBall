/*
How to use/create new animation pattern presets:
-   "laser_frames[]" represents which lasers are ON in each frame. 
-   While laser_frames[] is a 1D array of values, I've chosen a syntax that shows the values divided into "rows".
-   Each "row" represents a 1D array of lasers as one "frame". 
-   So sequential "rows" represent sequential frames in time.
-   Each "row" should have "n_laser" values, so if n_lasers=14, then to for easily readability, each row should have 14 columns.
*/
PROGMEM prog_uint16_t laser_frames1[] = //to store in flash memory "PROGMEM prog_uint16_t" datatype is necessary
                       {
                     // 1,2,3,4,5,6,7,8,9,10,11,12,13,14 //this is my laser mapping on the ball  
                        1,0,1,0,1,0,0,0,1, 0, 0, 1, 0, 1,
                        0,1,0,1,0,1,1,1,0, 1, 1, 0, 1, 0,
                       };
PROGMEM prog_uint16_t laser_frames2[] =
                       {
                       1,0,0,0,0,0,0,0,0,0,0,0,0,1,
                       0,1,0,0,0,0,0,0,0,0,0,0,1,0,
                       0,0,1,0,0,0,0,0,0,0,0,1,0,0,
                       0,0,0,1,0,0,0,0,0,0,1,0,0,0,
                       0,0,0,0,1,0,0,0,0,1,0,0,0,0,
                       0,0,0,0,0,1,0,0,1,0,0,0,0,0
                       };
PROGMEM prog_uint16_t  laser_frames3[] =
                       {
                       0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                       0,0,0,0,0,1,1,1,1,0,0,0,0,0,
                       0,0,0,0,1,1,1,1,1,1,0,0,0,0,
                       0,0,0,1,1,1,1,1,1,1,1,0,0,0,
                       0,0,1,1,1,1,1,1,1,1,1,1,0,0,
                       0,1,1,1,1,1,1,1,1,1,1,1,1,0,
                       1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                       0,1,1,1,1,1,1,1,1,1,1,1,1,0,
                       0,0,1,1,1,1,1,1,1,1,1,1,0,0,
                       0,0,0,1,1,1,1,1,1,1,1,0,0,0,
                       0,0,0,0,1,1,1,1,1,1,0,0,0,0,
                       0,0,0,0,0,1,1,1,1,0,0,0,0,0,
                       0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       };
PROGMEM prog_uint16_t laser_frames4[]  =
                       {
                       1,0,0,0,0,0,1,1,0,0,0,0,0,1,
                       0,1,0,0,0,1,0,0,1,0,0,0,1,0,
                       0,0,1,0,1,0,0,0,0,1,0,1,0,0,
                       0,0,0,1,1,1,1,1,1,1,1,0,0,0,
                       0,0,1,1,1,1,1,1,1,1,1,1,0,0,
                       0,1,1,1,1,1,1,1,1,1,1,1,1,0,
                       1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                       0,1,1,1,1,1,1,1,1,1,1,1,1,0,
                       0,0,1,1,1,1,1,1,1,1,1,1,0,0,
                       0,0,0,1,1,1,1,1,1,1,1,0,0,0,
                       0,0,0,0,1,1,1,1,1,1,0,0,0,0,
                       0,0,0,0,0,1,1,1,1,0,0,0,0,0,
                       0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       };
PROGMEM prog_uint16_t laser_frames5[] =
                       {
                       1,0,1,0,1,0,1,0,1,0,1,0,1,0,
                       0,1,0,1,0,1,0,1,0,1,0,1,0,1,
                       };
PROGMEM prog_uint16_t laser_frames6[] =
                       {
                       1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                       0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                       0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                       0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                       0,0,0,0,0,0,1,1,0,0,0,0,0,0,
                       1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                       1,1,0,0,0,0,1,1,0,0,0,0,1,1,
                       1,1,0,0,0,0,1,1,0,0,0,0,1,1,
                       1,1,0,0,0,0,1,1,0,0,0,0,1,1,
                       1,1,0,0,0,0,1,1,0,0,0,0,1,1,
                       1,1,0,0,0,0,1,1,0,0,0,0,1,1,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                       1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                       1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                       1,1,0,0,0,0,0,0,0,0,0,0,1,1,
                       1,1,0,0,0,0,0,0,0,0,0,0,1,1,
                       1,1,0,0,0,0,0,0,0,0,0,0,1,1,
                       1,1,0,0,0,0,0,0,0,0,0,0,1,1,
                       1,1,1,1,1,1,1,1,1,1,1,1,1,1,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       0,0,0,0,0,0,0,0,0,0,0,0,0,0,
                       };                       
//used to select which pattern to display                       
prog_uint16_t* seq_select[] = {
                    laser_frames1,
                    laser_frames2,
                    laser_frames3,
                    laser_frames4,
                    laser_frames5,
                    laser_frames6
                    };
//stores the length of each pattern in order to loop properly
int seq_lengths[] = { //need this because sizeof() is a compile-time function, not run-time. So I can't use laser_frames[] as a variable in the main loop, meaning sizeof(laser_frames[]) must be called up front.
                    sizeof(laser_frames1),
                    sizeof(laser_frames2),
                    sizeof(laser_frames3),
                    sizeof(laser_frames4),
                    sizeof(laser_frames5),
                    sizeof(laser_frames6)
                    };

int seq_count = sizeof(seq_lengths)/sizeof(int);
