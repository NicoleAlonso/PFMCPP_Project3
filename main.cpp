/*
Project 3 - Part 1e / 5
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

Convert your 10 Plain-english UDTs into code.

I recommend compiling after finishing each one and making sure it compiles 
without errors or warnings before moving on to writing the next UDT. 

1) define an empty struct below your plain-english UDT. i.e.:

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#if false //ignore these #if #endif lines. they're just here to prevent compiler errors.
struct CarWash
{

};
#endif
/*
    - Do this for all 10 UDTs

2) Below your plain-english UDT, Copy your 5 properties & 3 actions into the empty struct body.
    - comment them out.
    - Do this for all 10 UDTs
    
3) declare your member variables and member functions underneath each plain-english comment in your struct's body.
    - give the member variables relevant data types
    - Do this for all 10 UDTs
    - if your functions return something other than 'void', add a comment explaining what is being returned.  see the example code below.
 
4) make the function parameter list for those member functions use some of your User-Defined Types
    - You'll write definitions/implementations for these functions in Project3 Part2
    - you'll call each of these functions in Project3 part3
    - Do this for all 10 UDTs
 
5) make 2 of the 10 user-defined types have a nested class.  
    - this nested class also needs 5 properties and 3 actions.
    - these nested classes are not considered one of your 10 UDTs.
    - this nested class must be related to the class it is nested inside
 
6) your 10th UDT's properties should be instances of your #5-#9 UDTs.   
    - No primitives allowed!
 
7) After you finish defining each type, click the [run] button.  
    Clear up any errors or warnings as best you can. 
    if your code produces a [-Wpadded] warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

/*
 example:  

Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>

struct CarWash //                                   1) define an empty struct for each of your 10 types.       
{
    //number of vacuum cleaners                     2) copied and commented-out plain-english property
    int numVacuumCleaners = 3; //                   3) member variables with relevant data types.
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car //5)                                 Note that the nested type 'Car' is related to the 'CarWash' 
    {
        //2) member variables with relevant data types.  the names are appropriate for the U.D.T.'s purpose.
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        //3) a member function whose parameter has a default value.
        //the parameter name is related to the work the function will perform.
        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips); //3) returns the number of miles traveled
    };

    //wash and wax car
    void washAndWaxCar(Car carA); //4) a member function whose parameter is a UDT.
    //charge customer
    float chargeCustomer(float discountPercentage); //3) returns the total amount charged.
    //detail the car interior
    void detailInterior(Car carB);
    
    //5) a member variable whose type is a UDT.
    Car carBeingServiced;  

    /*
    Pay attention to the member functions that take an instance of 'Car'
    Notice that there is a member variable of the same type.

    It makes sense to pass a Car to the function 'washAndWaxCar' because car washes service MANY cars
    However, they only service ONE car at a time.
    the carBeingServiced's value would change every time you wash and wax the car. 

    I see many students who write code emulating this format, but their usage does not make logical sense.  
    Consider the following snippet:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        // train their skills
        void trainPlayerSkills(Manager managerA);
    
        Manager teamManager;
    };

    It does not make sense to pass in a new Manager whenever you are going to train your team players.
    Soccer teams have ONE manager.

    a much more relevant usage would be adding a member function that hires a new manager:

    struct SoccerTeam
    {
        struct Manager
        {
            ...
        };

        void hireNewManager(Manager newManager);
    
        Manager teamManager;
    };

    We can safely assume that the 'Manager' instance that is being passed in will be replacing the current 'teamManager' variable without looking at any other code.
    This is because the function name and function argument clearly indicate what they are/what they do.

    Your function names and parameter names should make LOGICAL SENSE.
    Readers of your code should be able to INTUITIVELY understand what your function implementations will do without actually seeing the implementations.

    Keep this in mind when you define your UDTs in this project part.
    */
};


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
