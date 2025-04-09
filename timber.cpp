#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

using namespace sf;
void updateBranches(int seed);
const int NUM_BRANCHES =6;
Sprite branches[NUM_BRANCHES];
enum class side {LEFT,RIGHT,NONE};
side branchPositions[NUM_BRANCHES];

int main(){

 VideoMode vm(860,540);

 RenderWindow window(vm, "Timber!!!!!");
 View view(FloatRect(0,0,1920,1080));
 window.setView(view);
 Texture textureBackground;
 

 textureBackground.loadFromFile("graphics/background.png");

 Sprite spriteBackground;
 spriteBackground.setTexture(textureBackground);
 spriteBackground.setPosition(0,0);
 
 
 //tree
 Texture textureTree;
 textureTree.loadFromFile("graphics/tree.png");
 Sprite spriteTree;
 spriteTree.setTexture(textureTree);
 spriteTree.setPosition(810, 0);
 
 //bee
 Texture textureBee;
 textureBee.loadFromFile("graphics/bee.png");
 Sprite spriteBee;
 spriteBee.setTexture(textureBee);
 spriteBee.setPosition(0, 800);
 
 bool beeActive = false;
 float beeSpeed = 0.0f;//speed 
 
 //cloud
 Texture textureCloud;
 textureCloud.loadFromFile("graphics/cloud.png");
 Sprite spriteCloud1;
 Sprite spriteCloud2;
 Sprite spriteCloud3;
 
 spriteCloud1.setTexture(textureCloud);
 spriteCloud2.setTexture(textureCloud);
 spriteCloud3.setTexture(textureCloud);
 
 spriteCloud1.setPosition(0, 0);
 spriteCloud2.setPosition(0, 150);
 spriteCloud3.setPosition(0, 300);
  
 bool cloud1Active = false;
 bool cloud2Active = false;
 bool cloud3Active = false;
 
 float cloud1Speed = 0.0f;
 float cloud2Speed = 0.0f;
 float cloud3Speed = 0.0f;//speed 
 
 //clock
 Clock clock;
 //timebar
 RectangleShape timeBar; 
 float timeBarStartWidth=400;
 float timeBarHeight=80;
 timeBar.setSize(Vector2f(timeBarStartWidth,timeBarHeight));
 timeBar.setFillColor(Color::Red);
 timeBar.setPosition((1920 / 2) - timeBarStartWidth / 2, 980);
 Time gameTimeTotal;
 float timeRemaining = 6.0f;
 float timeBarWidthPerSecond = timeBarStartWidth / timeRemaining;


 bool paused=true;
 int score=0;
 Text messageText;
 Text scoreText;
 
 Font font;
 font.loadFromFile("fonts/KOMIKAP_.ttf");
 //message
 messageText.setFont(font);
 messageText.setString("Press Enter To Start!");
 messageText.setCharacterSize(75);
 messageText.setFillColor(Color::White);
 
 //score
 scoreText.setFont(font);
 scoreText.setString("Score = 0");
 scoreText.setCharacterSize(100);
 scoreText.setFillColor(Color::White);
 messageText.setPosition(1920 / 2.0f, 1080 / 2.0f);
  
 //postion of text
 FloatRect textRect = messageText.getLocalBounds();
 messageText.setOrigin(textRect.left +
 textRect.width / 2.0f,
 textRect.top +
 textRect.height / 2.0f);

 scoreText.setPosition(20, 20);
 
 //prepare branches
 Texture textureBranch;
 textureBranch.loadFromFile("graphics/branch.png");
 
 for(int i=0;i<NUM_BRANCHES;i++){
 branches[i].setTexture(textureBranch);
  branches[i].setPosition(-2000,-2000);
  branches[i].setOrigin(220, 20);
 }

Texture texturePlayer;
texturePlayer.loadFromFile("graphics/player.png");
Sprite spritePlayer;
spritePlayer.setTexture(texturePlayer);
spritePlayer.setPosition(580,720);
side PlayerSide =side::LEFT;


// gravestone
Texture textureRIP;
textureRIP.loadFromFile("graphics/rip.png");
Sprite spriteRIP;
spriteRIP.setTexture(textureRIP);
spriteRIP.setPosition(600, 860);
//axe
Texture textureAxe;
textureAxe.loadFromFile("graphics/axe.png");
Sprite spriteAxe;
spriteAxe.setTexture(textureAxe);
spriteAxe.setPosition(700, 830);

const float AXE_POSITION_LEFT = 700;
const float AXE_POSITION_RIGHT = 1075;

//log
Texture textureLog;
textureLog.loadFromFile("graphics/log.png");
Sprite spriteLog;
spriteLog.setTexture(textureLog);
spriteLog.setPosition(810, 720);
// Some other useful log related variables
bool logActive = false;
float logSpeedX = 1000;
float logSpeedY = -1500;
 
 //window_input handling
while (window.isOpen()) {

 Event event;
 while (window.pollEvent(event))
	if (event.type ==Event::Closed)
	window.close();
 if (Keyboard::isKeyPressed(Keyboard::Escape))
 {
  window.close();
 }
 // Start the game
 if (Keyboard::isKeyPressed(Keyboard::Return))
{
	paused=false;
	
//to pause
  //if(paused) paused=false;
  //else paused=true;
 
 // Reset the time and the score
 score = 0;
 timeRemaining = 6;
 }

if(!paused){
//for bee
 Time dt = clock.restart();
 
 timeRemaining -=dt.asSeconds();
 timeBar.setSize(Vector2f(timeBarWidthPerSecond * timeRemaining, timeBarHeight));
 if(timeRemaining<0.0f){
 //if lessthan 0 then pause thye game
	paused=true;
	
	messageText.setString("Game Over!!");
	FloatRect textRect =messageText.getLocalBounds();
	messageText.setOrigin(textRect.left+ textRect.width/2.0f,
	textRect.top+textRect.height/2.0f);
	messageText.setPosition(1920/2.0f,1080/2.0f);
}
 if(!beeActive){
 srand((int)time(0));

 srand((int)time(0));
 beeSpeed = (rand() % 200) + 200;

 srand((int)time(0) * 10);
 float height = (rand() % 500) + 500;
 spriteBee.setPosition(2000, height);
 beeActive = true;
 }
 
 else

{
 spriteBee.setPosition(
 spriteBee.getPosition().x -(beeSpeed * dt.asSeconds()),
 spriteBee.getPosition().y);

 if (spriteBee.getPosition().x < -100)
 {
 beeActive = false;
 }
}

//for cloud 
//cloud1
if(!cloud1Active){
srand((int)time(0) * 10);
cloud1Speed=(rand() %200)+100;

//height
srand((int)time(0) * 10);
float height =(rand() %150);
spriteCloud1.setPosition(-200,height);
cloud1Active=true;

}
else{
spriteCloud1.setPosition(spriteCloud1.getPosition().x +(cloud1Speed *dt.asSeconds()),spriteCloud1.getPosition().y);

if(spriteCloud1.getPosition().x>1920){
	cloud1Active=false;}
}

//cloud2
if(!cloud2Active){
srand((int)time(0)*20);
cloud2Speed=(rand()%200);

//height
srand((int)time(0)*20);
float height=(rand() % 300)-150;
spriteCloud2.setPosition(-200,height);
cloud2Active=true;
}
else{
spriteCloud2.setPosition(spriteCloud2.getPosition().x+(cloud2Speed*dt.asSeconds()),spriteCloud2.getPosition().y);
if (spriteCloud2.getPosition().x > 1920){
 cloud2Active = false;
 }
}

//cloud3
if(!cloud3Active){
srand((int)time(0)*30);
cloud3Speed=(rand()%200);

//height
srand((int)time(0)*30);
float height=(rand() % 450)-150;
spriteCloud3.setPosition(-200,height);
cloud3Active=true;
}
else{
spriteCloud3.setPosition(spriteCloud3.getPosition().x+(cloud3Speed*dt.asSeconds()),spriteCloud3.getPosition().y);
if (spriteCloud3.getPosition().x > 1920){
 cloud3Active = false;
 }
}
}

//draw part
if(!paused){
 std::stringstream ss;
 ss<<"SCORE = "<<score;
  score++;
 scoreText.setString(ss.str());

// update the branch sprites
for (int i = 0; i < NUM_BRANCHES; i++)
{
float height = i * 150;
if (branchPositions[i] == side::LEFT)
{

branches[i].setPosition(610, height);
branches[i].setRotation(180);
}
else if (branchPositions[i] == side::RIGHT)
{

branches[i].setPosition(1330, height);

branches[i].setRotation(0);
}
else
{

branches[i].setPosition(3000, height);
}
}
 }//if (!paused) end here
 window.clear();
 
 window.draw(spriteBackground);
 window.draw(spriteCloud1);
 window.draw(spriteCloud2);
 window.draw(spriteCloud3);
 // Draw the branches
 for (int i = 0; i < NUM_BRANCHES; i++) {
 window.draw(branches[i]);
 }

 window.draw(spriteTree);
  window.draw(spritePlayer);
  window.draw(spriteAxe);
  window.draw(spriteLog);
  window.draw(spriteRIP);
 window.draw(spriteBee);
 
 window.draw(scoreText);
 if(paused) {
 window.draw(messageText);
 }

 window.draw(timeBar);
 window.display();


 }
   return EXIT_SUCCESS;
}

void updateBranches(int seed)
{
for (int j=NUM_BRANCHES-1;j>0;j--){
	branchPositions[j]=branchPositions[j-1];
}

srand((int)time(0)+seed);
int r=(rand() % 5);

switch(r){
case 0:
	branchPositions[0]=side::LEFT;
	break;
case 1:
	branchPositions[0] =side::RIGHT;
	break;
default:
	branchPositions[0] =side::NONE;
	break;
}
}

