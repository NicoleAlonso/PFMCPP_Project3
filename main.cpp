/*
Project 3 - Part 1d / 5
Video:  Chapter 2 Part 5
User-Defined Types

Continue your work on branch Part1

Purpose: The entire purpose of this 5-part project is to get you writing C++ code that compiles and to 
reinforce the syntax habits that C++ requires.  
What you create in this project will be used as the basis of Project 5 in the course.   

************************
Part1 purpose:  Learn to write UDTs

You are going to write 10 UDTs in project3. 
Part1 will be broken up into 5 separate steps 
    Part 1a: you will learn to think about an object in terms of its sub-objects.
    Part 1b: you will write 4 un-related UDTs in plain english
    Part 1c: you will write 1 UDT in plain english that will be made of 5 related sub-objects
    Part 1d: you will write plain-english UDTs for the 5 sub-objects that form the UDT defined in Part 1c
    Part 1e: you will convert those 10 plain-english UDTs into code that runs.
************************

    The goal of this step is to get you to think about breaking down an object into smaller and smaller objects, 
    until the smallest object is made of up only C++ primitives and std::string. 

    Continuing the previous example:  Cell Phone

    A Cell Phone is made up of the following 5 properties/sub-objects and 3 actions:
        Display
        Memory
        CPU
        Radio
        Applications
    3 actions:
        make a call
        send a text
        run an application.

    These 5 properties can be broken down into their own sub-objects and properties. 

    If we break down the first property 'Display' into its 5 properties we get:
        brightness
        amount of power consumed.
        pixels
        width in cm
        height in cm

    the Display's brightness can be represented with a Primitive, such as a double. 

    The amount of power consumed can also be represented with a Primitive, such as a float or integer (i.e. 250mWa)
    
    The 'pixels' property must be represented with an array of Pixel instances, as the screen has more than 1 row of pixels.
        Arrays have not been discussed and can't be used in this project.
        Instead, we can use an Integer primitive to store the Number of Pixels:

    Display:
        Number of Pixels
        Amount of Power consumed (milliwatt-hours)
        Brightness
        width in cm
        height in cm
************************

1) Fill in #5 - #9 with plain-english UDTs for the 5 properties you created for UDT #10
    example: 
        If #10's first property was 'Engine', then your `Thing 5)` will be `Engine`
        you will need to provide 5 properties and 3 member functions of that Engine object in plain English
        Remember to pick properties that can be represented with 'int float double bool char std::string'
2) write the name of the primitive type you'll be using after each property
    pick properties that can be represented with 'int float double bool char std::string'
    example: 
        Display:
            Number of Pixels (int)
            Amount of Power consumed (milliwatt-hours) (float)
            Brightness (double)
            width in cm (int)
            height in cm (int)

3) move Thing 5-9 to between your Thing 4 and Thing 10.
*/

/*
Thing 1) Coffee Machine
5 properties:
    1) brand name (std::string)
    2) amount of water the reservoir can contain (float)
    3) number of water tubes (int)
    4) number of holes in drip area (int)
    5) power of heating element (float)
3 things it can do:
    1) heats up water
    2) drips water over coffee grounds
    3) keeps coffee warm
 */

/*
Thing 2) Cargo Ship
5 properties:
    1) size of deck (float)
    2) size of fuel tank (float)
    3) amount of cargo (int)
    4) ship name (std::string)
    5) captain name (std::string)
3 things it can do:
    1) transports goods
    2) load/unload goods
    3) burns fuel
 */

/*
Thing 3) Computer
5 properties:
    1) amount of storage (double)
    2) processor speed (float)
    3) display-size (float)
    4) amount of keys (int)
    5) name of manufacturer (std::string)
3 things it can do:
    1) store data
    2) process data
    3) display data
 */

/*
Thing 4) Hotel
5 properties:
    1) amount of single bedrooms (int)
    2) amount of double bedrooms (int)
    3) number of roomkeys (int)
    4) amount of daily customers (int)
    5) name of receptionist (std::string)
3 things it can do:
    1) provides lodging
    2) serves breakfast
    3) charges guest
 */

/* 
Thing 5) Rendering Engine
5 properties:
    1) Lighting Type (std::string)
    2) Amount of Particles (double)
    3) Material Texture (std::string)
    4) Amount of Bloom effect (float)
    5) Degrees of Camera View Field (float)
3 things it can do:
    1) render lighting
    2) render material texture
    3) update camera view position
 */

/*
Thing 6) Physics Engine
5 properties:
    1) Physics Type (std::string)
    2) Collision Response Type (std::string)
    3) Amount of Gravity (float)
    4) Amount of Surface Friction (float)
    5) Raytracing Distance (float)
3 things it can do:
    1) detect collision
    2) set gravity
    3) destroy object
 */

/*
Thing 7) Audio Engine
5 properties:
    1) Number of I/O Channels (int)
    2) Volume (float)
    3) Pitch Multiplier (float)
    4) Attenuation (float)
    5) Audio Buffer Size (double)
3 things it can do:
    1) import soundfile
    2) edit soundfile
    3) playback sound
 */

/*
Thing 8) Networking System
5 properties:
    1) Network Mode (std::string)
    2) Priority Status (int)
    3) Read Buffer Size (double)
    4) Send Rate (float)
    5) Protocol Type (std::string)
3 things it can do:
    1) enable multiplayer mode
    2) share game state info
    3) send data to server
 */

/*
Thing 9) AI
5 properties:
    1) Acceptance Radius (float)
    2) Focal Point (float)
    3) Movement Velocity (int)
    4) Perception Properties (std::string)
    5) Stimuli Age (int)
3 things it can do:
    1) get target location
    2) move to target
    3) set focal point
 */

/*
Thing 10) Game Engine
5 properties:
    1) Rendering Engine
    2) Physics Engine
    3) Audio Engine
    4) Networking System
    5) AI
3 things it can do:
    1) edit graphics
    2) implement audio
    3) get user input
 */




/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

#include <iostream>
int main()
{
    std::cout << "good to go!" << std::endl;
}
