/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << a << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





struct CoffeeMachine
{
    std::string brandName {"Krups"};
    float waterReservoirCapacity {2839.06f};
    int waterTubes {2};
    int numDripHoles {12};
    float wattsOfHeatingElement {1200.0f};

    struct Settings
    {
        int brewStrength {4};
        int numCupsToBrew {2};
        int minutesUntilShutOff {15};
        float waterHardnessSetting {2.5f};
        float waterFlowSpeed {0.8f};

        void setTimer(int brewStart = 0, int minutesUntilShutOff = 20);
        void setBrewStrength(int brewStrength);
        bool flashDescalingIndicator(int waterHardness, int numCyclesMade); 
    };

    void heatWater(float tempInCelsius = 93.4f);
    void dripWater(Settings brewSettings, int dripInterval = 2);
    void maintainHeat(float timeToMaintain = 5.5f, float tempInCelsius = 85.0f);

    Settings newBrewSettings;
};

void CoffeeMachine::Settings::setTimer(int startTime, int shutOffTime)
{
    minutesUntilShutOff = shutOffTime - startTime;
}

void CoffeeMachine::Settings::setBrewStrength(int newBrewStrength)
{
    brewStrength = newBrewStrength;
    waterFlowSpeed = brewStrength * 0.2f;
}

bool CoffeeMachine::Settings::flashDescalingIndicator(int waterHardness, int numCyclesMade)
{
    if (numCyclesMade * waterHardness > 100)
    {
        return true;
    }

    return false;
}

void CoffeeMachine::heatWater(float heatTemp)
{
    wattsOfHeatingElement /= heatTemp * 90;
}

void CoffeeMachine::dripWater(Settings waterSettings, int dripPerSec)
{
    waterSettings.waterFlowSpeed += dripPerSec * numDripHoles;
}

struct CargoShip
{
    float deckSize {12000.0f};
    float fuelTankSize {1.7f};
    int numOfCargoContainers {1875};
    std::string shipName {"Neptuno"};
    std::string captainName {"James Cook"};

    struct CargoContent
    {
        std::string electronics {"home appliances"};
        std::string clothing {"t-shirts"};
        std::string food {"vegetables"};
        std::string constructionMaterial {"wood"};
        std::string furniture {"sofa"};

        bool contentIsFlammable(std::string category, int igniteLevel = 1); 
        bool contentIsToxic(std::string toxicityType, int classRating = 4); 
        float numItemsPerContainer(int numItems, float singleItemSize, float containerSize = 38.5f); 
    };

    void transportGoods(CargoContent ikeaItems, int amountOfContainers);
    void handleGoods(CargoContent fridges, int amountOfContainers, bool shipIsEmpty = true);
    void burnFuel(float consumptionPerKm, float travelDistance, bool shipIsLoaded = true);

    CargoContent nextCargoLoad;
};

bool CargoShip::CargoContent::contentIsFlammable(std::string category, int igniteLevel)
{
    if(igniteLevel > 2 && category == "liquids")
    {
        return true;
    }
    else if(igniteLevel > 3 && category == "solids")
    {
        return true;
    }

    return false;
}

bool CargoShip::CargoContent::contentIsToxic(std::string toxicityType, int classRating)
{
    if(classRating > 4 && toxicityType == "biohazard")
    {
        return true;
    }
    else if(classRating > 5 && toxicityType == "corrosive")
    {
        return true;
    }

    return false;
}

float CargoShip::CargoContent::numItemsPerContainer(int numItems, float singleItemSize, float containerSize)
{
    return (containerSize/singleItemSize) * numItems;
}

void CargoShip::transportGoods(CargoContent kitchenItems, int amountOfContainers)
{
    kitchenItems.electronics = "toaster";
    kitchenItems.furniture = "cupboard";
    numOfCargoContainers = amountOfContainers;
}

void CargoShip::handleGoods(CargoContent buildingMaterial, int numContainersToLoad, bool shipIsEmpty)
{
    buildingMaterial.constructionMaterial = "cement blocks";
    
    if(shipIsEmpty)
    {
       numContainersToLoad /= deckSize; // ship loads amount that fits on deck size
    }
    else
    {
        numContainersToLoad *= -1 ; // means ship unloads the amount of containers
    }
}

void CargoShip::burnFuel(float consumptionPerKm, float travelDistance, bool shipIsLoaded)
{
    float fuelBurned;
    
    if(!shipIsLoaded)
    {
        fuelBurned = (consumptionPerKm * 0.8f) * travelDistance;
    }
     
    fuelBurned = consumptionPerKm * travelDistance;
}

struct Computer
{
    double storageInGb {500.0};
    float processorSpeed {3.5f};
    float displaySize {13.0f};
    int numKeys {101};
    std::string manufacturer {"Apple"};

    void storeData(int numFiles, int fileSize, std::string fileName = "unknown");
    void processData(float amountToProcess, float timeToProcess = 0.02f);
    void displayData(std::string fileName = "unknown", bool fullscreen = false);
};

void Computer::storeData(int numFiles, int fileSize, std::string fileName)
{
    std::string database = "added " + fileName;
    storageInGb -= numFiles * fileSize;
}

void Computer::processData(float amountToProcess, float timeToProcess)
{
    processorSpeed = amountToProcess * timeToProcess;
}

struct Hotel
{
    int numSingleRooms {46};
    int numDoubleRooms {62};
    int numDailyGuests {77};
    float priceDiscount {5.0f};
    std::string receptionistName {"Gabriel"};

    void provideLodging(Computer registerGuest, int daysToStay = 2, bool isDoubleRoom = true);
    void serveBreakfast(int numGuestToServe = 65, bool isSober = true);
    void chargeGuest(int amountOfDays, float pricePerDay, bool usedRoomService = false, float priceRoomService = 25.5f);
};

void Hotel::provideLodging(Computer registerGuest, int daysToStay, bool isDoubleRoom)
{
    registerGuest.storeData(1, 24, "new guest");
    
    if(daysToStay > 10)
        priceDiscount = 15.0f;

    if(isDoubleRoom)
        --numDoubleRooms;
}

void Hotel::serveBreakfast(int numGuestToServe, bool isSober)
{
    if(!isSober)
        --numGuestToServe;
}

struct RenderingEngine
{
    std::string lightingType {"spot light"};
    double particleAmount {2300.0};
    std::string materialTexture {"grass"}; 
    float bloomAmountInPercentage {10.0f};
    float cameraViewField {180.0f};

    void renderLights(std::string lightingType, int renderQuality = 4);
    void renderMaterialTexture(std::string materialTexture = "stone", int renderQuality = 4, int numPolygons = 100);
    void updateCameraViewPosition(float cameraViewField, float positionX = 0.0f, float positionY = 0.0f);
};

void RenderingEngine::renderLights(std::string lightToRender, int renderQuality)
{
    lightingType = lightToRender;
    bloomAmountInPercentage *= renderQuality;
}

void RenderingEngine::renderMaterialTexture(std::string textureToRender, int renderQuality, int numPolygons)
{
    materialTexture = textureToRender;
    numPolygons *= renderQuality;
}

void RenderingEngine::updateCameraViewPosition(float currentViewField, float positionX, float positionY)
{
    cameraViewField = currentViewField + positionX + positionY;
}

struct PhysicsEngine
{
    std::string physicsType {"default"};
    std::string collisionResponse {"block"};
    float gravity {1.0f};
    float friction {4.0f};
    float raytracingDistance {100.0f};

    void detectCollision(float raytracingDistance);
    void setGravity(float gravity);
    void destroyObject(std::string collisionResponse = "hit", std::string physicsType = "simulated", int impactForce = 9);
};

void PhysicsEngine::detectCollision(float maxTracingDistance)
{
    if(raytracingDistance >= maxTracingDistance)
    {
        collisionResponse = "ignore";
    }
}

void PhysicsEngine::setGravity(float newGravityVal)
{
    gravity = newGravityVal;
}

void PhysicsEngine::destroyObject(std::string collisionType, std::string physicsSetting, int impactForce)
{
    collisionResponse = collisionType;
    physicsType = physicsSetting;

    if(collisionResponse == "explode" && impactForce < 10)
        impactForce *= 10;
}

struct AudioEngine
{
    int numChannels {2};
    float volumeInDb {-18.0f};
    float pitchMultiplier {1.0f};
    float attenuationInDb {3.0f};
    double audioBufferSize {256.0};

    void importSoundfile(std::string filePath, std::string fileName, int numChannels);
    void editSound(float pitchMultiplier, float attenuationInDb = 6.0f);
    void playSound(double audioBufferSize, int numChannels, float volumeInDb = -3.0f, bool isAlreadyPlaying = false);
};

void AudioEngine::importSoundfile(std::string filePath, std::string fileName, int audioChannels)
{
    if(filePath == "")
    {
        std::cout << "path not found";
        return;
    }   
    
    std::string typeSuffix = "SFX_" + fileName;
    numChannels = audioChannels;
}
void AudioEngine::editSound(float newPitchValue, float fasterAttenuation)
{
    pitchMultiplier = newPitchValue;
    attenuationInDb = fasterAttenuation;
}

void AudioEngine::playSound(double bufferSizeSetting, int outputChannels, float outputVol, bool isAlreadyPlaying)
{
    if(isAlreadyPlaying)
    {
        std::cout << "Sound already playing. Execution cancelled";
        return;
    }
    
    audioBufferSize = bufferSizeSetting;
    numChannels = outputChannels;
    volumeInDb = outputVol;

}

struct NetworkingSystem
{
    std::string networkMode {"standalone"};
    int priorityStatus {1}; 
    float readBufferSize {1024};
    float sendRate {60.0f}; 
    std::string protocolType {"UDP"};

    void setMultiplayerMode(std::string networkMode = "server", int numOfPlayers = 2);
    std::string shareGameState(std::string platform = "Nintendo");
    void sendDataToServer(float sendRate, float dataSize);
};

void NetworkingSystem::setMultiplayerMode(std::string userMode, int numOfPlayers)
{
    networkMode = userMode;
    if(numOfPlayers > 4)
        sendRate = 72.0f;
}

std::string NetworkingSystem::shareGameState(std::string platform)
{
    return platform;
}

void NetworkingSystem::sendDataToServer(float currentSendRate, float dataSize)
{
    readBufferSize = currentSendRate * dataSize;
}

struct AI
{
    float acceptanceRadius {90.0f};
    float focalPoint {1.0f};
    int moveVelocity {5};
    std::string perceptionProperty {"hearing sense"};
    float stimuliAgeInSec {5.0f};

    float getTargetLocation(float positionX = 10.0f, float positionY = 10.0f); 
    void moveToTarget(int moveVelocity, float acceptanceRadius = 50.5f);
    void setFocalPoint(float focalPoint, float oldPosition, float newPosition);
};

float AI::getTargetLocation(float positionX, float positionY)
{
    return positionX * positionY;
} 

void AI::moveToTarget(int chaseVelocity, float newRadius)
{
    acceptanceRadius = newRadius;
    moveVelocity = chaseVelocity;
    if (acceptanceRadius < 10.0f)
    {
        moveVelocity += 2;
    }
}

void AI::setFocalPoint(float newTargetPoint, float oldPosition, float newPosition)
{
    focalPoint = (newTargetPoint - oldPosition) + newPosition;
}

struct GameEngine
{
    RenderingEngine renderingEngine;
    PhysicsEngine physicsEngine;
    AudioEngine audioEngine;
    NetworkingSystem networking;
    AI arificialIntelligence;

    void editGraphics(RenderingEngine renderingEngine);
    void implementAudio(AudioEngine audioEngine, std::string triggerEventName = "footsteps");
    void getUserInput(NetworkingSystem networkSettings, std::string controllerType = "PS4");
};

void GameEngine::editGraphics(RenderingEngine newTexture)
{
    newTexture.renderMaterialTexture("water", 6);
}

void GameEngine::implementAudio(AudioEngine implementSFX, std::string triggerEventName)
{
    implementSFX.importSoundfile("/Sounds/SFX", triggerEventName, 2);
}

void GameEngine::getUserInput(NetworkingSystem networkSettings, std::string controllerType)
{
   std::string userPlatform = networkSettings.shareGameState();
   if(userPlatform != controllerType)
   {
       std::cout << "Cannot connect controller to platform. Type mismatch";
   }
}

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
    Example::main();
    
    
    std::cout << "good to go!" << std::endl;
}
