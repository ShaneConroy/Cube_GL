#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <gl/GL.h>
#include <gl/GLU.h>

#include <Vector3.h>


using namespace std;
using namespace sf;
using namespace gpp;

class Game
{
public:
	Game();
	~Game();
	void run();
private:
	Window window;
	bool isRunning = false;
	void initialize();
	void update();
	void draw();
	void unload();

	//float translate(float);
	//float movement;

	GLuint index;
	Clock clock;
	Time elapsed;

	// angle cube will rotate by
	float angle = 0.9999;
	float xAxis = 1.0;
	float yAxis = 1.0;

	float farPoint = -15.0;
	float closePoint = -5.0;

	sf::Vector3f matrixRowOne   = { 0.0, 0.0, -5.0 };
	sf::Vector3f matrixRowTwo   = { 0.0, 0.0, -5.0 };
	sf::Vector3f matrixRowThree = { 0.0, 0.0, -5.0 };

	// Matrix for rotating around Y axis
	sf::Vector3f yRotateOne   = { cos(angle), 0.0, sin(angle)};
	sf::Vector3f yRotateTwo   = { 0.0, 1.0, 0.0 };
	sf::Vector3f yRotateThree = { sin(-angle), 0.0, cos(angle)};

};