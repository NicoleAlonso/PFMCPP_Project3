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
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
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
    CoffeeMachine();

    struct Settings
    {
        int brewStrength {4};
        int numCupsToBrew {2};
        int minutesUntilShutOff {15};
        float waterHardnessSetting {2.5f};
        float waterFlowSpeed {0.8f};
        Settings();

        void setTimer(int brewStart = 0, int minutesUntilShutOff = 20);
        void setBrewStrength(int brewStrength);
        bool flashDescalingIndicator(int waterHardness, int numCyclesMade); 
    };

    void heatWater(float tempInCelsius = 93.4f);
    void dripWater(int dripInterval = 2);
    void maintainHeat(float timeToMaintain = 5.5f, float tempInCelsius = 85.0f);

    Settings newBrewSettings;
};

CoffeeMachine::CoffeeMachine()
{
    std::cout << "CoffeeMachine being constructed!" << std::endl;
}

CoffeeMachine::Settings::Settings()
{
    std::cout << "CoffeeMachine::Settings being constructed!" << std::endl;
}

void CoffeeMachine::Settings::setTimer(int startTime, int shutOffTime)
{
    minutesUntilShutOff = (shutOffTime - startTime) * 10;
    std::cout << "CoffeeMachine::Settings::setTimer(): " << minutesUntilShutOff << std::endl;
}

void CoffeeMachine::Settings::setBrewStrength(int newBrewStrength)
{
    brewStrength = newBrewStrength;
    waterFlowSpeed = brewStrength * 0.2f;
    std::cout << "CoffeeMachine::Settings::setBrewStrength() Waterflow speed is now: " << waterFlowSpeed << std::endl;
}

bool CoffeeMachine::Settings::flashDescalingIndicator(int waterHardness, int numCyclesMade)
{
    if (numCyclesMade * waterHardness > 100)
    {
        std::cout << "CoffeeMachine::Settings::flashDescalingIndicator(): Time to descale machine" << std::endl;
        return true;
    }
    std::cout << "CoffeeMachine::Settings::flashDescalingIndicator(): No need for descaling yet" << std::endl;
    return false;
}

void CoffeeMachine::heatWater(float heatTemp)
{
    wattsOfHeatingElement /= heatTemp * 90;
    std::cout << "CoffeeMachine::Settings::flashDescalingIndicator(): " << wattsOfHeatingElement << std::endl;
}

void CoffeeMachine::dripWater(int dripPerSec)
{
    newBrewSettings.waterFlowSpeed += dripPerSec * numDripHoles;
    std::cout << "CoffeeMachine::dripWater(): " << newBrewSettings.waterFlowSpeed << std::endl;
}

void CoffeeMachine::maintainHeat(float timeToMaintain, float tempInCelsius)
{
    wattsOfHeatingElement = tempInCelsius * timeToMaintain;
    std::cout << "CoffeeMachine::maintainHeat() powerConsumption: " << wattsOfHeatingElement << std::endl;
}

struct CargoShip
{
    int deckSize {12000};
    float fuelTankSize {1.7f};
    int numOfCargoContainers {1875};
    std::string shipName {"Neptuno"};
    std::string captainName {"James Cook"};
    CargoShip();

    struct CargoContent
    {
        std::string contentA{"home appliances"};
        std::string contentB {"t-shirts"};
        int numItems {3500};
        CargoContent();

        bool contentIsFlammable(std::string category, int igniteLevel = 1); 
        bool contentIsToxic(std::string toxicityType, int classRating = 4); 
        float numItemsPerContainer(float singleItemSize, float containerSize = 38.5f); 
    };

    void transportGoods(std::string contentTypeA, std::string contentTypeB, int amountOfContainers);
    void handleGoods(int amountOfContainers, bool shipIsEmpty = true);
    void burnFuel(float consumptionPerKm, float travelDistance, bool shipIsLoaded = true);

    CargoContent nextCargoLoad;
};

CargoShip::CargoShip()
{
    std::cout << "CargoShip being constructed!" << std::endl;
}

CargoShip::CargoContent::CargoContent()
{
    std::cout << "CargoShip::CargoContent being constructed!" << std::endl;
}

bool CargoShip::CargoContent::contentIsFlammable(std::string category, int igniteLevel)
{
    if(igniteLevel > 2 && category == "liquids")
    {   
        std::cout << "CargoContent::contentIsFlammable(): contains flammable liquids!" << std::endl;
        return true;
    }
    else if(igniteLevel > 3 && category == "solids")
    {
        std::cout << "CargoContent::contentIsFlammable(): contains flammable solids!" << std::endl;
        return true;
    }
    std::cout << "CargoContent::contentIsFlammable(): Content is not flammable" << std::endl;
    return false;
}

bool CargoShip::CargoContent::contentIsToxic(std::string toxicityType, int classRating)
{
    if(classRating > 4 && toxicityType == "biohazard")
    {
         std::cout << "CargoContent::contentIsToxic(): Content classified as biohazard!" << std::endl;
        return true;
    }
    else if(classRating > 5 && toxicityType == "corrosive")
    {
         std::cout << "CargoContent::contentIsToxic(): Content classified as corrosive!" << std::endl;
        return true;
    }
    std::cout << "CargoContent::contentIsToxic(): Content is not toxic" << std::endl;
    return false;
}

float CargoShip::CargoContent::numItemsPerContainer(float singleItemSize, float containerSize)
{
    
    std::cout << "CargoContent::numItemsPerContainer(): total items "<< numItems << std::endl;
    return (containerSize/singleItemSize) * numItems;
}

void CargoShip::transportGoods(std::string contentTypeA, std::string contentTypeB, int amountOfContainers)
{
    nextCargoLoad.contentA = contentTypeA;
    nextCargoLoad.contentB = contentTypeB;
    numOfCargoContainers = amountOfContainers;
    std::cout << "CargoContent::transportGoods() type of goods: "<< contentTypeA << ',' << contentTypeB << std::endl;
}

void CargoShip::handleGoods(int numContainersToLoad, bool shipIsEmpty)
{
    
    if(shipIsEmpty)
    {
       numContainersToLoad = deckSize / numOfCargoContainers; // ship loads amount that fits on deck size
    }
    else
    {
        numContainersToLoad *= -1 ; // means ship unloads the amount of containers
    }
    std::cout << "CargoContent::handleGoods() amount to load/unload: "<< numContainersToLoad << std::endl;
}

void CargoShip::burnFuel(float consumptionPerKm, float travelDistance, bool shipIsLoaded)
{
    float fuelBurned;
    
    if(!shipIsLoaded)
    {
        fuelBurned = (consumptionPerKm * 0.8f) * travelDistance;
    }
     
    fuelBurned = consumptionPerKm * travelDistance;
    std::cout << "CargoContent::burnFuel() " << fuelBurned << std::endl;
}

struct Computer
{
    double storageInGb {500.0};
    float processorSpeed {3.5f};
    float displaySize {13.0f};
    int numKeys {101};
    std::string manufacturer {"Apple"};
    Computer();

    void storeData(int numFiles, int fileSize, std::string fileName = "unknown");
    void processData(float amountToProcess, float timeToProcess = 0.02f);
    void displayData(std::string fileName = "unknown", bool fullscreen = false);
};

Computer::Computer()
{
    std::cout << "Computer being constructed!" << std::endl;
}

void Computer::storeData(int numFiles, int fileSize, std::string fileName)
{
    std::string database = "added " + fileName;
    storageInGb -= numFiles * fileSize;
    std::cout << "Computer::storeData() " << database << std::endl;
}

void Computer::processData(float amountToProcess, float timeToProcess)
{
    processorSpeed = amountToProcess * timeToProcess;
    std::cout << "Computer::processData() speed: " << processorSpeed << std::endl;
}

void Computer::displayData(std::string fileName, bool fullscreen)
{
    if (!fullscreen)
        displaySize *= 0.5f;

    std::string displayText = "file stored: " + fileName;    
    std::cout << "Computer::displayData(): " << displayText << std::endl;
}

struct Hotel
{
    int numSingleRooms {46};
    int numDoubleRooms {62};
    int numDailyGuests {77};
    float priceDiscount {5.0f};
    std::string receptionistName {"Gabriel"};
    Hotel();

    void provideLodging(Computer registerGuest, int daysToStay = 2, bool isDoubleRoom = true);
    void serveBreakfast(int numGuestToServe = 65, bool isSober = true);
    void chargeGuest(int amountOfDays, float pricePerDay, bool usedRoomService = false, float priceRoomService = 25.5f);
};

Hotel::Hotel()
{
    std::cout << "Hotel being constructed!" << std::endl;
}

void Hotel::provideLodging(Computer registerGuest, int daysToStay, bool isDoubleRoom)
{
    registerGuest.storeData(1, 24, "new guest");
    
    daysToStay > 10 ? priceDiscount = daysToStay * 0.8f : priceDiscount = 0.0f;

    if(isDoubleRoom)
        --numDoubleRooms;

    std::cout << "Hotel::provideLodging() guest stays for: " << daysToStay << " days" << std::endl;
}

void Hotel::serveBreakfast(int numGuestToServe, bool isSober)
{
    if(!isSober)
        --numGuestToServe;

    std::cout << "Hotel::serveBreakfast() amount of guests: " << numGuestToServe << std::endl;
}

void Hotel::chargeGuest(int amountOfDays, float pricePerDay, bool usedRoomService, float priceRoomService)
{
    float totalPrice = pricePerDay * amountOfDays;
    
    if(usedRoomService)
        totalPrice += priceRoomService;
    
    std::cout << "Hotel::chargeGuest() total price: " << totalPrice << '$' << std::endl;
}

struct RenderingEngine
{
    std::string lightingType {"spot light"};
    double particleAmount {2300.0};
    std::string materialTexture {"grass"}; 
    float bloomAmountInPercentage {10.0f};
    float cameraViewField {180.0f};
    RenderingEngine();

    void renderLights(std::string lightingType, int renderQuality = 4);
    void renderMaterialTexture(std::string materialTexture = "stone", int renderQuality = 4, int numPolygons = 100);
    void updateCameraViewPosition(float cameraViewField, float positionX = 0.0f, float positionY = 0.0f);
};

RenderingEngine::RenderingEngine()
{
    std::cout << "RenderingEgine being constructed!" << std::endl;
}

void RenderingEngine::renderLights(std::string lightToRender, int renderQuality)
{
    lightingType = lightToRender;
    bloomAmountInPercentage *= renderQuality;
    std::cout << "RenderingEngine::renderLights() bloom effect: " << bloomAmountInPercentage << '%' << std::endl;
}

void RenderingEngine::renderMaterialTexture(std::string textureToRender, int renderQuality, int numPolygons)
{
    materialTexture = textureToRender;
    numPolygons *= renderQuality;
    std::cout << "RenderingEngine::renderMaterialTexture() " << materialTexture << std::endl;
}

void RenderingEngine::updateCameraViewPosition(float currentViewField, float positionX, float positionY)
{
    cameraViewField = currentViewField + positionX + positionY;
    std::cout << "RenderingEngine::updateCameraViewPosition() " << cameraViewField << std::endl;
}

struct PhysicsEngine
{
    std::string physicsType {"default"};
    std::string collisionResponse {"block"};
    float gravity {1.0f};
    float friction {4.0f};
    float raytracingDistance {100.0f};
    PhysicsEngine();

    void detectCollision(float raytracingDistance);
    void setGravity(float gravity);
    void destroyObject(std::string collisionResponse = "hit", std::string physicsType = "simulated", int impactForce = 9);
};

PhysicsEngine::PhysicsEngine()
{
    std::cout << "PhysicsEngine being constructed!" << std::endl;
}

void PhysicsEngine::detectCollision(float maxTracingDistance)
{
    if(raytracingDistance >= maxTracingDistance)
    {
        collisionResponse = "ignore";
    }
     std::cout << "PhysicsEngine::detectCollision() response: " << collisionResponse << std::endl;
}

void PhysicsEngine::setGravity(float newGravityVal)
{
    gravity = newGravityVal;
    std::cout << "PhysicsEngine::setGravity() " << gravity << std::endl;
}

void PhysicsEngine::destroyObject(std::string collisionType, std::string physicsSetting, int impactForce)
{
    collisionResponse = collisionType;
    physicsType = physicsSetting;

    if(collisionResponse == "explode" && impactForce > 10)
        impactForce *= 10;

    std::cout << "PhysicsEngine::destroyObject() impact force: " << impactForce << std::endl;
}

struct AudioEngine
{
    int numChannels {2};
    float volumeInDb {-18.0f};
    float pitchMultiplier {1.0f};
    float attenuationInDb {3.0f};
    double audioBufferSize {256.0};
    AudioEngine();

    void importSoundfile(std::string filePath, std::string fileName, int numChannels);
    void editSound(float pitchMultiplier, float attenuationInDb = 6.0f);
    void playSound(double audioBufferSize, int numChannels, float volumeInDb = -3.0f, bool isAlreadyPlaying = false);
};

AudioEngine::AudioEngine()
{
    std::cout << "AudioEngine being constructed!" << std::endl;
}

void AudioEngine::importSoundfile(std::string filePath, std::string fileName, int audioChannels)
{
    if(filePath == "")
    {
        std::cout << "path not found";
        return;
    }   
    
    std::string typeSuffix = "SFX_" + fileName;
    numChannels = audioChannels;
    std::cout << "AudioEngine::importSoundfile() " << typeSuffix << std::endl;
}
void AudioEngine::editSound(float newPitchValue, float fasterAttenuation)
{
    pitchMultiplier = newPitchValue;
    attenuationInDb = fasterAttenuation;
    std::cout << "AudioEngine::editSound() pitch value: " << pitchMultiplier << std::endl;
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
    std::cout << "AudioEngine::playSound() volume: " << volumeInDb << " dB" << std::endl;
}

struct NetworkingSystem
{
    std::string networkMode {"standalone"};
    int priorityStatus {1}; 
    float readBufferSize {1024};
    float sendRate {60.0f}; 
    std::string protocolType {"UDP"};
    NetworkingSystem();

    void setMultiplayerMode(std::string networkMode = "server", int numOfPlayers = 2);
    std::string identifyPlatform(std::string platform = "Nintendo");
    void sendDataToServer(float sendRate, float dataSize);
};

NetworkingSystem::NetworkingSystem()
{
    std::cout << "NetworkingSystem being constructed!" << std::endl;
}

void NetworkingSystem::setMultiplayerMode(std::string userMode, int numOfPlayers)
{
    networkMode = userMode;
    if(numOfPlayers > 4)
        sendRate = 72.0f;
    
    std::cout << "NetworkingSystem::setMultiplayerMode() " << networkMode << std::endl;
}

std::string NetworkingSystem::identifyPlatform(std::string platform)
{
    std::cout << "NetworkingSystem::identifyPlatform() platform used: " << platform << std::endl;
    return platform;
}

void NetworkingSystem::sendDataToServer(float currentSendRate, float dataSize)
{
    readBufferSize = currentSendRate * dataSize;
    std::cout << "NetworkingSystem::sendDataToServer() bufferSize: " << readBufferSize << std::endl;
}

struct AI
{
    float acceptanceRadius {90.0f};
    float focalPoint {1.0f};
    int moveVelocity {5};
    std::string perceptionProperty {"hearing sense"};
    float stimuliAgeInSec {5.0f};
    AI();

    float getTargetLocation(float positionX = 10.0f, float positionY = 10.0f); 
    void moveToTarget(int moveVelocity, float acceptanceRadius = 50.5f);
    void setFocalPoint(float focalPoint, float oldPosition, float newPosition);
};

AI::AI()
{
    std::cout << "AI being constructed!" << std::endl;
}

float AI::getTargetLocation(float positionX, float positionY)
{
    std::cout << "AI::getTargetLocation() position x-axis: " << positionX << std::endl;
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
    std::cout << "AI::moveToTarget() velocity: " << moveVelocity << std::endl;
}

void AI::setFocalPoint(float newTargetPoint, float oldPosition, float newPosition)
{
    focalPoint = (newTargetPoint - oldPosition) + newPosition;
    std::cout << "AI::setFocalPoint() " << focalPoint << std::endl;
}

struct GameEngine
{
    RenderingEngine renderingEngine;
    PhysicsEngine physicsEngine;
    AudioEngine audioEngine;
    NetworkingSystem networking;
    AI arificialIntelligence;
    GameEngine();

    void renderGraphics(std::string textureType);
    void loadSoundFile(std::string pathToSoundFile, std::string triggerEventName = "footsteps");
    void connectToPlatform(std::string controllerType = "PS4");
};

GameEngine::GameEngine()
{
    std::cout << "GameEngine being constructed!" << std::endl;
}

void GameEngine::renderGraphics(std::string textureType)
{
    renderingEngine.renderMaterialTexture(textureType, 6);
    std::cout << "GameEngine::renderGraphics() rendering: " << textureType << " texture" << std::endl;
}

void GameEngine::loadSoundFile(std::string pathToSoundFile, std::string triggerEventName)
{
    audioEngine.importSoundfile(pathToSoundFile, triggerEventName, 2);
    std::cout << "GameEngine::loadSoundFile() trigger event: " << triggerEventName << std::endl;
}

void GameEngine::connectToPlatform(std::string controllerType)
{
   std::string userPlatform = networking.identifyPlatform();
   if(userPlatform != controllerType)
   {
       std::cout << "Cannot connect controller to platform. Type mismatch\n";
   }
   std::cout << "GameEngine::connectToPlatform() playing on: " << userPlatform << std::endl;
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
    std::cout << "-------------------" << std::endl;

    CoffeeMachine nespressoMachine;
    CoffeeMachine::Settings coffeeSettings;

    nespressoMachine.heatWater(95.0f);
    nespressoMachine.dripWater(4);

    coffeeSettings.setBrewStrength(3);
    coffeeSettings.setTimer(7, 8);
    coffeeSettings.flashDescalingIndicator(3, 101);
    std::cout << "machine will shut down in: " << coffeeSettings.minutesUntilShutOff << " minutes" << std::endl;
    std::cout << "-------------------" << std::endl;

    CargoShip ship;
    CargoShip::CargoContent amazonItems;
    
    ship.transportGoods("fridges", " washmachines", 250);
    ship.handleGoods(250, true);

    amazonItems.contentIsFlammable("liquids", 3);
    amazonItems.contentIsToxic("corrosive", 2);
    amazonItems.numItemsPerContainer(0.24f, 38.5f);
    std::cout << "Captain " << ship.captainName << " will lead this ship" << std::endl;
    std::cout << "-------------------" << std::endl;
   
    Computer macBook;
    macBook.storeData(5, 64, "invoices");
    macBook.processData(20.0f, 0.05f);
    macBook.displayData("new message", false);
    std::cout << "-------------------" << std::endl;

    Hotel marriotHotel;
    marriotHotel.provideLodging(macBook, 12, true);
    marriotHotel.serveBreakfast(42, true);
    marriotHotel.chargeGuest(12, 87.9f, true, 25.5f);
    std::cout << "Price discount for guest: "<< marriotHotel.priceDiscount << '%' << std::endl; 
    std::cout << "-------------------" << std::endl;

    RenderingEngine renderingEngine;
    renderingEngine.renderLights("skylight", 4);
    renderingEngine.renderMaterialTexture("glass", 3, 146);
    renderingEngine.updateCameraViewPosition(95.2f, 55.0f, 14.5f);
    std::cout << "-------------------" << std::endl;

    PhysicsEngine physicsEengine;
    physicsEengine.detectCollision(105.0f);
    physicsEengine.setGravity(1.0f);
    physicsEengine.destroyObject("explode", "simulated", 11);
    std::cout << "-------------------" << std::endl;

    AudioEngine audioEngine;
    audioEngine.importSoundfile("/sounds/effects", "explosion", 2);
    audioEngine.editSound(1.15f, 4.0f);
    audioEngine.playSound(256.0, 2, 0.0f, false);
    std::cout << "-------------------" << std::endl;

    NetworkingSystem network;
    network.setMultiplayerMode("server", 4);
    network.identifyPlatform("Nintendo");
    network.sendDataToServer(60.0f, 24.0f);
    std::cout << "-------------------" << std::endl;

    AI ai;
    ai.getTargetLocation(45.0f, 10.0f);
    ai.moveToTarget(6, 65.5f);
    ai.setFocalPoint(55.0f, 23.5f, 47.0f);
    std::cout << "AI perceives target with its " << ai.perceptionProperty << " during " << ai.stimuliAgeInSec << " seconds\n";
    std::cout << "-------------------" << std::endl;

    GameEngine gameEngine;
    gameEngine.loadSoundFile("/Sounds/SFX/weapons", "gunshot");
    gameEngine.connectToPlatform("Xbox");
    
    std::cout << "good to go!" << std::endl;
}
