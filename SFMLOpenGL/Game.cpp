#include <Game.h>

bool updatable = false;

gpp::Vector3 v3;

Game::Game() : window(VideoMode(800, 600), "OpenGL Cube")
{
	index = glGenLists(1);
}

Game::~Game(){}

void Game::run()
{

	initialize();

	Event event;

	while (isRunning){

		//cout << "Game running..." << endl;

		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				isRunning = false;
			}
		}
		update();
		draw();
	}

}

void Game::initialize()
{
	isRunning = true;

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, window.getSize().x / window.getSize().y, 1.0, 500.0);
	glMatrixMode(GL_MODELVIEW);

	// glNewList(index, GL_COMPILE);
	// Creates a new Display List
	// Initalizes and Compiled to GPU
	// https://www.opengl.org/sdk/docs/man2/xhtml/glNewList.xml

	
	
}

void Game::update()
{
	elapsed = clock.getElapsedTime();

	if (elapsed.asSeconds() >= 1.0f)
	{
		clock.restart();

		if (!updatable)
		{
			updatable = true;
		}
		else
			updatable = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		closePoint -= 0.001;
		farPoint -= 0.001;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		closePoint += 0.001;
		farPoint += 0.001;
	}

	
	//cout << "Update up" << endl;
}

void Game::draw()
{
	//cout << "Drawing" << endl;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//cout << "Drawing Cube " << endl;
	glLoadIdentity();

	glNewList(index, GL_COMPILE);
	glBegin(GL_TRIANGLES);
	{

		// Right face, triangle one
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, farPoint);
		glVertex3f(v3.getX(), -1.0f, closePoint);
		glVertex3f(1.0f, 1.0f, closePoint);

		// Right face, tri two
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, closePoint);
		glVertex3f(1.0f, -1.0f, farPoint);
		glVertex3f(1.0f, 1.0f, farPoint);

		// Back face, tri one
		glColor3f(.0f, .0f, 1.0f);
		glVertex3f(v3.getX(), 1.0f, farPoint);
		glVertex3f(-1.0f, 1.0f, farPoint);
		glVertex3f(-1.0f, -1.0f, farPoint);

		// Back face, tri two
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, farPoint);
		glVertex3f(1.0f, -1.0f, farPoint);
		glVertex3f(-1.0f, -1.0f, farPoint);

		// Left face, tri one
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-1.0f, -1.0f, farPoint);
		glVertex3f(-1.0, 1.0f, closePoint);
		glVertex3f(-1.0f, -1.0f, closePoint);

		// Left face, tri two
		glColor3f(1.0f, .0f, .0f);
		glVertex3f(-1.0f, 1.0f, closePoint);
		glVertex3f(-1.0f, 1.0f, farPoint);
		glVertex3f(-1.0f, -1.0f, farPoint);

		// Bottom face, tri one
		glColor3f(.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, closePoint);
		glVertex3f(-1.0f, -1.0f, farPoint);
		glVertex3f(1.0f, -1.0f, closePoint);

		// Bottom face, tri two
		glColor3f(.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, farPoint);
		glVertex3f(1.0f, -1.0f, closePoint);
		glVertex3f(1.0f, -1.0f, farPoint);

		// Top face, tri one
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, closePoint);
		glVertex3f(1.0f, 1.0f, farPoint);
		glVertex3f(-1.0f, 1.0f, closePoint);

		// Top face, tri two
		glColor3f(1.0f, 1.0f, .0f);
		glVertex3f(1.0f, 1.0f, farPoint);
		glVertex3f(-1.0f, 1.0f, closePoint);
		glVertex3f(-1.0f, 1.0f, farPoint);

		//// Front face, triangle one
		//glColor3f(.0f, 1.0f, .0f);
		//glVertex3f(v3.getX(), 1.0f, closePoint);
		//glVertex3f(-1.0f, 1.0f, closePoint);
		//glVertex3f(-1.0f, -1.0f, closePoint);

		//// Front face, triangle two
		//glColor3f(0.0f, 1.0f, 0.0f);
		//glVertex3f(1.0f, 1.0f, closePoint);
		//glVertex3f(1.0f, -1.0f, closePoint);
		//glVertex3f(-1.0f, -1.0f, closePoint);


	}
	glEnd();
	glEndList();


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		glTranslatef(xAxis, 0.0, 0.0);
		xAxis -= 0.001;

		//// Rotate Cube around y-axis
		//matrixRowOne.x *= yRotateOne.x;
		//matrixRowOne.y *= yRotateOne.y;
		//matrixRowOne.z *= yRotateOne.z;

		//matrixRowTwo.x *= yRotateTwo.x;
		//matrixRowTwo.y *= yRotateTwo.y;
		//matrixRowTwo.z *= yRotateTwo.z;

		//matrixRowThree.x *= yRotateThree.x;
		//matrixRowThree.y *= yRotateThree.y;
		//matrixRowThree.z *= yRotateThree.z;
	}
	else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		glTranslatef(xAxis, 0.0, 0.0);
		xAxis += 0.001;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		glTranslatef(0.0, yAxis, 0.0);
		yAxis += 0.001;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		glTranslatef(0.0, yAxis, 0.0);
		yAxis -= 0.001;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		glRotatef(angle, 1.0, 0.0, -5.0);
		angle -= 0.01;
	}
	else {
		angle = 0.9999;
		xAxis = 1.0;
		yAxis = 1.0;
	}

	



	glCallList(1);



	window.display();

}

void Game::unload()
{
	//cout << "Cleaning up" << endl;
}
