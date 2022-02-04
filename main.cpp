 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
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
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */





 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have warnings about 'unused parameter', you aren't using one of your function parameters in your implementation.
    use the parameter in your implementation.
    If you have warnings about 'overshadow', a local variable in the function has the same name as a class member.
    change the name of your local variable so it is different from the class member's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
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
struct CoffeeMachine
{
    // brand name
    std::string brandName {"Krups"};
    // amount of water the reservoir can contain 
    float waterReservoirCapacity {2839.06f};
    // number of water tubes 
    int waterTubes {2};
    // number of holes in drip area 
    int numDripHoles {12};
    // power of heating element 
    float wattsOfHeatingElement {1200.0f};

    struct Settings
    {
        int brewStrength {4};
        int numCupsToBrew {2};
        int minutesUntilShutOff {15};
        float waterHardnessSetting {2.5f};
        float waterFlowSpeed {0.8f};

        void setTimer(float brewStart = 0, int minutesUntilShutOff = 20);
        void setBrewStrength(int brewStrength);
        bool flashDescalingIndicator(int waterHardness, int numCyclesMade); //returns true if the machine should run descaling program
    };

    // heat up water
    void heatWater(float tempInCelsius = 93.4f);
    // drip water over coffee grounds
    void dripWater(Settings brewSettings, int dripInterval = 2);
    // keep coffee warm
    void maintainHeat(float timeToMaintain = 5.5f, float tempInCelsius = 85.0f);

    Settings newBrewSettings;
};
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
struct CargoShip
{
    // size of deck 
    float deckSize {12000.0f};
    // size of fuel tank in million unit
    float fuelTankSize {1.7f};
    // amount of cargo 
    int numOfCargoContainers {1875};
    // ship name 
    std::string shipName {"Neptuno"};
    // captain name 
    std::string captainName {"James Cook"};

    struct CargoContent
    {
        std::string electronics {"home appliances"};
        std::string clothing {"t-shirts"};
        std::string food {"vegetables"};
        std::string constructionMaterial {"wood"};
        std::string furniture {"sofa"};

        bool contentIsFlammable(std::string category, int igniteLevel = 1); //returns if the transported goods are flammable or not
        bool contentIsToxic(std::string toxicityType, int classRating = 4); //returns if the transported goods are toxic or not
        float numItemsPerContainer(int numItems, float singleItemSize, float containerSize = 38.5f); // returns how many goods fit into one container
    };

    // transport goods
    void transportGoods(CargoContent ikeaItems, int amountOfContainers);
    // load/unload goods
    void handleGoods(CargoContent fridges, int amountOfContainers, bool shipIsEmpty = true);
    // burn fuel
    void burnFuel(float consumptionPerKm, float travelDistance, bool shipIsLoaded = true);

    CargoContent nextCargoLoad;
};
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
struct Computer
{
    // amount of storage 
    double storageInGb {500.0};
    // processor speed 
    float processorSpeed {3.5f};
    // display-size 
    float displaySize {13.0f};
    // amount of keys 
    int numKeys {101};
    // name of manufacturer
    std::string manufacturer {"Apple"};

    void storeData(int numFiles, std::string fileName = "unknown");
    void processData(float amountToProcess, float timeToProcess = 0.02f);
    void displayData(std::string fileName = "unknown", bool fullscreen = false);
};
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
struct Hotel
{
    // amount of single bedrooms 
    int numSingleRooms {46};
    // amount of double bedrooms 
    int numDoubleRooms {62};
    // number of roomkeys 
    int numRoomkeys {108};
    // amount of daily customers 
    int numDailyGuests {77};
    // name of receptionist
    std::string receptionistName {"Gabriel"};

    // provide lodging
    void provideLodging(Computer registerGuest, int daysToStay = 2, bool isDoubleRoom = true);
    // serve breakfast
    void serveBreakfast(int numGuestToServe = 65, bool isVegan = false);
    // charge guest
    void chargeGuest(int amountOfDays, float pricePerDay, bool usedRoomService = false, float priceRoomService = 25.5f);
};
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
struct RenderingEngine
{
    // Lighting Type 
    std::string lightingType {"spot light"};
    // Amount of Particles (double)
    double particleAmount {2300.0};
    // Material Texture 
    std::string materialTexture {"grass"};
    // Amount of Bloom effect 
    float bloomAmountInPercentage {10.0f};
    // Degrees of Camera View Field 
    float cameraViewField {180.0f};

    //render lighting
    void renderLights(std::string lightingType, int renderQuality = 4);
    // render material texture
    void renderMaterialTexture(std::string materialTexture = "stone", int renderQuality = 4);
    // update camera view position
    void updateCameraViewPosition(float cameraViewField, float positionX = 0.0f, float positionY = 0.0f);
};
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
struct PhysicsEngine
{
    // Physics Type 
    std::string physicsType {"default"};
    // Collision Response Type 
    std::string collisionResponse {"block"};
    // Amount of Gravity 
    float gravity {1.0f};
    // Amount of Surface Friction 
    float friction {4.0f};
    // Raytracing Distance 
    float raytracingDistance {100.0f};

    //detect collision
    void detectCollision(float raytracingDistance);
    // set gravity
    void setGravity(float gravity);
    // destroy object
    void destroyObject(std::string collisionResponse = "hit", std::string physicsType = "simulated", int impactForce = 9);
};
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
struct AudioEngine
{
    // Number of I/O Channels 
    int numChannels {2};
    // Volume 
    float volumeInDb {-18.0f};
    // Pitch Multiplier 
    float pitchMultiplier {1.0f};
    // Attenuation 
    float attenuationInDb {3.0f};
    // Audio Buffer Size 
    double audioBufferSize {256.0};

    // import soundfile
    void importSoundfile(std::string filePath, std::string fileName, float fileSizeInKb = 894.4f);
    // edit soundfile
    void editSound(float pitchMultiplier, float attenuationInDb = 6.0f);
    // playback sound
    void playSound(double audioBufferSize, int numChannels, float volumeInDb = -3.0f, bool loopSound = false);
};
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
struct NetworkingSystem
{
    // Network Mode 
    std::string networkMode {"standalone"};
    // Priority Status 
    int priorityStatus {1};
    // Read Buffer Size 
    double readBufferSize {1024};
    // Send Rate 
    float sendRate {60.0f};
    // Protocol Type 
    std::string protocolType {"UDP"};

    // enable multiplayer mode
    void setMultiplayerMode(std::string networkMode = "server", int numOfPlayers = 2);
    // share game state info
    void shareGameState();
    // send data to server
    void sendDataToServer(float sendRate, float dataSize);
};
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
struct AI
{
    // Acceptance Radius 
    float acceptanceRadius {90.0f};
    // Focal Point 
    float focalPoint {1.0f};
    // Movement Velocity 
    int moveVelocity {5};
    // Perception Properties 
    std::string perceptionProperty {"hearing sense"};
    // Stimuli Age (time until perceived sense is forgotten) 
    float stimuliAgeInSec {5.0f};

    // get target location
    float getTargetLocation(float positionX = 10.0f, float positionY = 10.0f); //returns current target position 
    // move to target
    void moveToTarget(int moveVelocity, float acceptanceRadius = 50.5f);
    // set focal point
    void setFocalPoint(float focalPoint, float oldPosition, float newPosition);
};
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
struct GameEngine
{
    // Rendering Engine
    RenderingEngine renderingEngine;
    // Physics Engine
    PhysicsEngine physicsEngine;
    // Audio Engine
    AudioEngine audioEngine;
    // Networking System
    NetworkingSystem networking;
    // AI
    AI arificialIntelligence;

    //edit graphics
    void editGraphics(RenderingEngine renderingEngine);
    // implement audio
    void implementAudio(AudioEngine audioEngine, std::string triggerEventName = "footsteps");
    // get user input
    void getUserInput(NetworkingSystem networkSettings, std::string controllerType = "PS4");
};



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
