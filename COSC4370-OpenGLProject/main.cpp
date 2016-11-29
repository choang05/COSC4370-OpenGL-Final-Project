// Std. Includes
#include <string>
#include <chrono>
#include <thread>
#include <vector>

// GLEW
#include <GL/glew.h>

// GLFW
#include <GLFW/glfw3.h>

// GL includes
#include "Shader.h"
#include "Camera.h"
#include "Model.h"

// GLM Mathemtics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

// Other Libs
#include "SOIL2/SOIL2.h"

// Properties
const GLuint WIDTH = 800, HEIGHT = 600;
int SCREEN_WIDTH, SCREEN_HEIGHT;

// Function prototypes
//void KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mode );
//void MouseCallback( GLFWwindow *window, double xPos, double yPos );
//void DoMovement( );

// Camera - (Position, Front, Yaw, Pitch)
Camera camera( glm::vec3(-3.5f, 1.0f, 4.0f ), glm::vec3(0.0f, 1.0f, 0.0f), -45, 0);
bool keys[1024];
GLfloat lastX = 400, lastY = 300;
bool firstMouse = true;

GLfloat deltaTime = 0.0f;
GLfloat lastFrame = 0.0f;

int main( )
{
    // Init GLFW
    glfwInit( );
    // Set all the required options for GLFW
    glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 3 );
    glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 3 );
    glfwWindowHint( GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE );
    glfwWindowHint( GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE );
    glfwWindowHint( GLFW_RESIZABLE, GL_FALSE );
    
    // Create a GLFWwindow object that we can use for GLFW's functions
    GLFWwindow *window = glfwCreateWindow( WIDTH, HEIGHT, "Chad_Hoang_finalproject", nullptr, nullptr );
    
    if ( nullptr == window )
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate( );
        
        return EXIT_FAILURE;
    }
    
    glfwMakeContextCurrent( window );
    
    glfwGetFramebufferSize( window, &SCREEN_WIDTH, &SCREEN_HEIGHT );
    
    // Set the required callback functions
    //glfwSetKeyCallback( window, KeyCallback );
    //glfwSetCursorPosCallback( window, MouseCallback );
    
    // GLFW Options
    glfwSetInputMode( window, GLFW_CURSOR, GLFW_CURSOR_DISABLED );
    
    // Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
    glewExperimental = GL_TRUE;
    // Initialize GLEW to setup the OpenGL Function pointers
    if ( GLEW_OK != glewInit( ) )
    {
        std::cout << "Failed to initialize GLEW" << std::endl;
        return EXIT_FAILURE;
    }
    
    // Define the viewport dimensions
    glViewport( 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT );
    
    // OpenGL options
    glEnable( GL_DEPTH_TEST );
    
    // Setup and compile our shaders
    Shader shader( "res/shaders/modelLoading.vs", "res/shaders/modelLoading.frag" );
    
    // Load base models
	Model Cube1Model("res/models/Cube1.obj");
	Model Cube2Model("res/models/Cube2.obj");
	Model Sphere1Model("res/models/Sphere.obj");
    
    // Draw in wireframe
    //glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
    
    glm::mat4 projection = glm::perspective( camera.GetZoom( ), ( float )SCREEN_WIDTH/( float )SCREEN_HEIGHT, 0.1f, 100.0f );

	#pragma region	Cache character models so its easier to acces from our frame array
	cout << "Loading character model frame 1 of 60..." << endl;
	Model CharacterModelFrame1("res/models/character_walkingupstairs/character1.0001.obj");
	cout << "Loading character model frame 2 of 60..." << endl;
	Model CharacterModelFrame2("res/models/character_walkingupstairs/character1.0002.obj");
	cout << "Loading character model frame 3 of 60..." << endl;
	Model CharacterModelFrame3("res/models/character_walkingupstairs/character1.0003.obj");
	cout << "Loading character model frame 4 of 60..." << endl;
	Model CharacterModelFrame4("res/models/character_walkingupstairs/character1.0004.obj");
	cout << "Loading character model frame 5 of 60..." << endl;
	Model CharacterModelFrame5("res/models/character_walkingupstairs/character1.0005.obj");
	cout << "Loading character model frame 6 of 60..." << endl;
	Model CharacterModelFrame6("res/models/character_walkingupstairs/character1.0006.obj");
	cout << "Loading character model frame 7 of 60..." << endl;
	Model CharacterModelFrame7("res/models/character_walkingupstairs/character1.0007.obj");
	cout << "Loading character model frame 8 of 60..." << endl;
	Model CharacterModelFrame8("res/models/character_walkingupstairs/character1.0008.obj");
	cout << "Loading character model frame 9 of 60..." << endl;
	Model CharacterModelFrame9("res/models/character_walkingupstairs/character1.0009.obj");
	cout << "Loading character model frame 10 of 60..." << endl;
	Model CharacterModelFrame10("res/models/character_walkingupstairs/character1.0010.obj");
	cout << "Loading character model frame 11 of 60..." << endl;
	Model CharacterModelFrame11("res/models/character_walkingupstairs/character1.0011.obj");
	cout << "Loading character model frame 12 of 60..." << endl;
	Model CharacterModelFrame12("res/models/character_walkingupstairs/character1.0012.obj");
	cout << "Loading character model frame 13 of 60..." << endl;
	Model CharacterModelFrame13("res/models/character_walkingupstairs/character1.0013.obj");
	cout << "Loading character model frame 14 of 60..." << endl;
	Model CharacterModelFrame14("res/models/character_walkingupstairs/character1.0014.obj");
	cout << "Loading character model frame 15 of 60..." << endl;
	Model CharacterModelFrame15("res/models/character_walkingupstairs/character1.0015.obj");
	cout << "Loading character model frame 16 of 60..." << endl;
	Model CharacterModelFrame16("res/models/character_walkingupstairs/character1.0016.obj");
	cout << "Loading character model frame 17 of 60..." << endl;
	Model CharacterModelFrame17("res/models/character_walkingupstairs/character1.0017.obj");
	cout << "Loading character model frame 18 of 60..." << endl;
	Model CharacterModelFrame18("res/models/character_walkingupstairs/character1.0018.obj");
	cout << "Loading character model frame 19 of 60..." << endl;
	Model CharacterModelFrame19("res/models/character_walkingupstairs/character1.0019.obj");
	cout << "Loading character model frame 20 of 60..." << endl;
	Model CharacterModelFrame20("res/models/character_walkingupstairs/character1.0020.obj");
	cout << "Loading character model frame 21 of 60..." << endl;
	Model CharacterModelFrame21("res/models/character_walkingupstairs/character1.0021.obj");
	cout << "Loading character model frame 22 of 60..." << endl;
	Model CharacterModelFrame22("res/models/character_walkingupstairs/character1.0022.obj");
	cout << "Loading character model frame 23 of 60..." << endl;
	Model CharacterModelFrame23("res/models/character_walkingupstairs/character1.0023.obj");
	cout << "Loading character model frame 24 of 60..." << endl;
	Model CharacterModelFrame24("res/models/character_walkingupstairs/character1.0024.obj");
	cout << "Loading character model frame 25 of 60..." << endl;
	Model CharacterModelFrame25("res/models/character_walkingupstairs/character1.0025.obj");
	cout << "Loading character model frame 26 of 60..." << endl;
	Model CharacterModelFrame26("res/models/character_walkingupstairs/character1.0026.obj");
	cout << "Loading character model frame 27 of 60..." << endl;
	Model CharacterModelFrame27("res/models/character_walkingupstairs/character1.0027.obj");
	cout << "Loading character model frame 28 of 60..." << endl;
	Model CharacterModelFrame28("res/models/character_walkingupstairs/character1.0028.obj");
	cout << "Loading character model frame 29 of 60..." << endl;
	Model CharacterModelFrame29("res/models/character_walkingupstairs/character1.0029.obj");
	cout << "Loading character model frame 30 of 60..." << endl;
	Model CharacterModelFrame30("res/models/character_walkingupstairs/character1.0030.obj");
	cout << "Loading character model frame 31 of 60..." << endl;
	Model CharacterModelFrame31("res/models/character_pickup/character1.0001.obj");
	cout << "Loading character model frame 32 of 60..." << endl;
	Model CharacterModelFrame32("res/models/character_pickup/character1.0002.obj");
	cout << "Loading character model frame 33 of 60..." << endl;
	Model CharacterModelFrame33("res/models/character_pickup/character1.0003.obj");
	cout << "Loading character model frame 34 of 60..." << endl;
	Model CharacterModelFrame34("res/models/character_pickup/character1.0004.obj");
	cout << "Loading character model frame 35 of 60..." << endl;
	Model CharacterModelFrame35("res/models/character_pickup/character1.0005.obj");
	cout << "Loading character model frame 36 of 60..." << endl;
	Model CharacterModelFrame36("res/models/character_pickup/character1.0006.obj");
	cout << "Loading character model frame 37 of 60..." << endl;
	Model CharacterModelFrame37("res/models/character_pickup/character1.0007.obj");
	cout << "Loading character model frame 38 of 60..." << endl;
	Model CharacterModelFrame38("res/models/character_pickup/character1.0008.obj");
	cout << "Loading character model frame 39 of 60..." << endl;
	Model CharacterModelFrame39("res/models/character_pickup/character1.0009.obj");
	cout << "Loading character model frame 40 of 60..." << endl;
	Model CharacterModelFrame40("res/models/character_pickup/character1.0010.obj");
	cout << "Loading character model frame 41 of 60..." << endl;
	Model CharacterModelFrame41("res/models/character_pickup/character1.0011.obj");
	cout << "Loading character model frame 42 of 60..." << endl;
	Model CharacterModelFrame42("res/models/character_pickup/character1.0012.obj");
	cout << "Loading character model frame 43 of 60..." << endl;
	Model CharacterModelFrame43("res/models/character_pickup/character1.0013.obj");
	cout << "Loading character model frame 44 of 60..." << endl;
	Model CharacterModelFrame44("res/models/character_pickup/character1.0014.obj");
	cout << "Loading character model frame 45 of 60..." << endl;
	Model CharacterModelFrame45("res/models/character_pickup/character1.0015.obj");
	cout << "Loading character model frame 46 of 60..." << endl;
	Model CharacterModelFrame46("res/models/character_pickup/character1.0016.obj");
	cout << "Loading character model frame 47 of 60..." << endl;
	Model CharacterModelFrame47("res/models/character_pickup/character1.0017.obj");
	cout << "Loading character model frame 48 of 60..." << endl;
	Model CharacterModelFrame48("res/models/character_pickup/character1.0018.obj");
	cout << "Loading character model frame 49 of 60..." << endl;
	Model CharacterModelFrame49("res/models/character_pickup/character1.0019.obj");
	cout << "Loading character model frame 50 of 60..." << endl;
	Model CharacterModelFrame50("res/models/character_pickup/character1.0020.obj");
	cout << "Loading character model frame 51 of 60..." << endl;
	Model CharacterModelFrame51("res/models/character_pickup/character1.0021.obj");
	cout << "Loading character model frame 52 of 60..." << endl;
	Model CharacterModelFrame52("res/models/character_pickup/character1.0022.obj");
	cout << "Loading character model frame 53 of 60..." << endl;
	Model CharacterModelFrame53("res/models/character_pickup/character1.0023.obj");
	cout << "Loading character model frame 54 of 60..." << endl;
	Model CharacterModelFrame54("res/models/character_pickup/character1.0024.obj");
	cout << "Loading character model frame 55 of 60..." << endl;
	Model CharacterModelFrame55("res/models/character_pickup/character1.0025.obj");
	cout << "Loading character model frame 56 of 60..." << endl;
	Model CharacterModelFrame56("res/models/character_pickup/character1.0026.obj");
	cout << "Loading character model frame 57 of 60..." << endl;
	Model CharacterModelFrame57("res/models/character_pickup/character1.0027.obj");
	cout << "Loading character model frame 58 of 60..." << endl;
	Model CharacterModelFrame58("res/models/character_pickup/character1.0028.obj");
	cout << "Loading character model frame 59 of 60..." << endl;
	Model CharacterModelFrame59("res/models/character_pickup/character1.0029.obj");
	cout << "Loading character model frame 60 of 60..." << endl;
	Model CharacterModelFrame60("res/models/character_pickup/character1.0030.obj");
	#pragma endregion

	//	Add the models to our frame array
	int currentCharacterFrame = 0;
	vector<Model> characterModelFrames;
	characterModelFrames.push_back(CharacterModelFrame1);
	characterModelFrames.push_back(CharacterModelFrame2);
	characterModelFrames.push_back(CharacterModelFrame3);
	characterModelFrames.push_back(CharacterModelFrame4);
	characterModelFrames.push_back(CharacterModelFrame5);
	characterModelFrames.push_back(CharacterModelFrame6);
	characterModelFrames.push_back(CharacterModelFrame7);
	characterModelFrames.push_back(CharacterModelFrame8);
	characterModelFrames.push_back(CharacterModelFrame9);
	characterModelFrames.push_back(CharacterModelFrame10);
	characterModelFrames.push_back(CharacterModelFrame11);
	characterModelFrames.push_back(CharacterModelFrame12);
	characterModelFrames.push_back(CharacterModelFrame13);
	characterModelFrames.push_back(CharacterModelFrame14);
	characterModelFrames.push_back(CharacterModelFrame15);
	characterModelFrames.push_back(CharacterModelFrame16);
	characterModelFrames.push_back(CharacterModelFrame17);
	characterModelFrames.push_back(CharacterModelFrame18);
	characterModelFrames.push_back(CharacterModelFrame19);
	characterModelFrames.push_back(CharacterModelFrame20);
	characterModelFrames.push_back(CharacterModelFrame21);
	characterModelFrames.push_back(CharacterModelFrame23);
	characterModelFrames.push_back(CharacterModelFrame24);
	characterModelFrames.push_back(CharacterModelFrame25);
	characterModelFrames.push_back(CharacterModelFrame26);
	characterModelFrames.push_back(CharacterModelFrame27);
	characterModelFrames.push_back(CharacterModelFrame28);
	characterModelFrames.push_back(CharacterModelFrame29);
	characterModelFrames.push_back(CharacterModelFrame30);
	characterModelFrames.push_back(CharacterModelFrame31);
	characterModelFrames.push_back(CharacterModelFrame32);
	characterModelFrames.push_back(CharacterModelFrame33);
	characterModelFrames.push_back(CharacterModelFrame34);
	characterModelFrames.push_back(CharacterModelFrame35);
	characterModelFrames.push_back(CharacterModelFrame36);
	characterModelFrames.push_back(CharacterModelFrame37);
	characterModelFrames.push_back(CharacterModelFrame38);
	characterModelFrames.push_back(CharacterModelFrame39);
	characterModelFrames.push_back(CharacterModelFrame40);
	characterModelFrames.push_back(CharacterModelFrame41);
	characterModelFrames.push_back(CharacterModelFrame42);
	characterModelFrames.push_back(CharacterModelFrame43);
	characterModelFrames.push_back(CharacterModelFrame44);
	characterModelFrames.push_back(CharacterModelFrame45);
	characterModelFrames.push_back(CharacterModelFrame46);
	characterModelFrames.push_back(CharacterModelFrame47);
	characterModelFrames.push_back(CharacterModelFrame48);
	characterModelFrames.push_back(CharacterModelFrame49);
	characterModelFrames.push_back(CharacterModelFrame50);
	characterModelFrames.push_back(CharacterModelFrame51);
	characterModelFrames.push_back(CharacterModelFrame53);
	characterModelFrames.push_back(CharacterModelFrame54);
	characterModelFrames.push_back(CharacterModelFrame55);
	characterModelFrames.push_back(CharacterModelFrame56);
	characterModelFrames.push_back(CharacterModelFrame57);
	characterModelFrames.push_back(CharacterModelFrame58);
	characterModelFrames.push_back(CharacterModelFrame59);
	characterModelFrames.push_back(CharacterModelFrame60);

    //	Display loop
    while( !glfwWindowShouldClose( window ) )
    {
        // Set frame time
        GLfloat currentFrame = glfwGetTime( );
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;
        
        // Check and call events
        glfwPollEvents( );
        //DoMovement( );
        
        // Clear the colorbuffer
        glClearColor( 0.05f, 0.05f, 0.05f, 1.0f );
        glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
        
        shader.Use( );
        
        glm::mat4 view = camera.GetViewMatrix( );
        glUniformMatrix4fv( glGetUniformLocation( shader.Program, "projection" ), 1, GL_FALSE, glm::value_ptr( projection ) );
        glUniformMatrix4fv( glGetUniformLocation( shader.Program, "view" ), 1, GL_FALSE, glm::value_ptr( view ) );
        
		// Draw the first cube
		glm::mat4 cube1;
		cube1 = glm::translate(cube1, glm::vec3(-0.1f, 0.08f, 0.3f)); // Translate
		cube1 = glm::scale(cube1, glm::vec3(0.15f, 0.15f, 0.15f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(cube1));
		Cube1Model.Draw(shader);

		// Draw the second cube
		glm::mat4 cube2;
		cube2 = glm::translate(cube2, glm::vec3(0.1f, 0.30f, 0.8f)); // Translate
		cube2 = glm::scale(cube2, glm::vec3(0.15f, 0.15f, 0.15f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(cube2));
		Cube2Model.Draw(shader);

		// Draw the sphere
		glm::mat4 sphere1;
		sphere1 = glm::translate(sphere1, glm::vec3(0.25f, 1.8f, 0.75f)); // Translate
		sphere1 = glm::scale(sphere1, glm::vec3(0.15f, 0.15f, 0.15f));	// It's a bit too big for our scene, so scale it down
		glUniformMatrix4fv(glGetUniformLocation(shader.Program, "model"), 1, GL_FALSE, glm::value_ptr(sphere1));
		Sphere1Model.Draw(shader);

        // Draw the character model frame by frame
		glm::mat4 model;
        model = glm::translate( model, glm::vec3( 0.0f, 0.0f, 0.0f ) ); // Translate it down a bit so it's at the center of the scene
        model = glm::scale( model, glm::vec3( 0.01f, 0.01f, 0.01f ) );	// It's a bit too big for our scene, so scale it down
        glUniformMatrix4fv( glGetUniformLocation( shader.Program, "model" ), 1, GL_FALSE, glm::value_ptr( model ) );
		characterModelFrames[currentCharacterFrame].Draw(shader);

		//	Update character frame
		cout << "Frame: " << currentCharacterFrame << endl;
		if (currentCharacterFrame >= characterModelFrames.size() - 1)
			currentCharacterFrame = 0;
		else
			currentCharacterFrame++;

        // Swap the buffers
        glfwSwapBuffers( window );

		//	Delay display by 33 miliseconds becuase our animation runs at 30 frames a second
		std::this_thread::sleep_for(std::chrono::milliseconds(33));
    }
    
    glfwTerminate( );
    return 0;
}

// Moves/alters the camera positions based on user input
/*void DoMovement( )
{
    // Camera controls
    if ( keys[GLFW_KEY_W] || keys[GLFW_KEY_UP] )
    {
        camera.ProcessKeyboard( FORWARD, deltaTime );
    }
    
    if ( keys[GLFW_KEY_S] || keys[GLFW_KEY_DOWN] )
    {
        camera.ProcessKeyboard( BACKWARD, deltaTime );
    }
    
    if ( keys[GLFW_KEY_A] || keys[GLFW_KEY_LEFT] )
    {
        camera.ProcessKeyboard( LEFT, deltaTime );
    }
    
    if ( keys[GLFW_KEY_D] || keys[GLFW_KEY_RIGHT] )
    {
        camera.ProcessKeyboard( RIGHT, deltaTime );
    }
}

// Is called whenever a key is pressed/released via GLFW
void KeyCallback( GLFWwindow *window, int key, int scancode, int action, int mode )
{
    if ( GLFW_KEY_ESCAPE == key && GLFW_PRESS == action )
    {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    
    if ( key >= 0 && key < 1024 )
    {
        if ( action == GLFW_PRESS )
        {
            keys[key] = true;
        }
        else if ( action == GLFW_RELEASE )
        {
            keys[key] = false;
        }
    }
}

void MouseCallback( GLFWwindow *window, double xPos, double yPos )
{
    if ( firstMouse )
    {
        lastX = xPos;
        lastY = yPos;
        firstMouse = false;
    }
    
    GLfloat xOffset = xPos - lastX;
    GLfloat yOffset = lastY - yPos;  // Reversed since y-coordinates go from bottom to left
    
    lastX = xPos;
    lastY = yPos;
    
    camera.ProcessMouseMovement( xOffset, yOffset );
}*/

