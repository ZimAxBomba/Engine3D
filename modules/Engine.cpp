#include "Engine.h"
#include <iostream>
#define GLFW_INCLUDE_NONE


/**
 * Konstruktor inicjializujący okno domyślnymi ustawieniami.
 */
Engine::Engine(){
    fullscreen = false;
    sizeX = 800;
    sizeY = 600;
    fps = 60;
    mouseInput = true;
    keyboardInput = true;
    }
/**
 * Konstruktor inicjalizuje okno z podanymi wartościami.
 * @param full Otwiera okno w pełnym ekranie jeśtli wartośc wynosi true.
 * @param x Szerokość okna.
 * @param y Wysokość okna.
 * @param name Wyświetlana nazwa okna.
 */
Engine::Engine(bool full,int x,int y){
        fullscreen = full;
        sizeX = x;
        sizeY = y;
        fps = 60;
        mouseInput = true;
        keyboardInput = true;
    }
/**
 * Główna funckja uruchamiająca pętle gry.
 */
void EngineWrapper::run(){
    init();
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    GLFWwindow *window = engine.getWindow();
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window)){
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);
        /* Swap front and back buffers */
        glfwSwapBuffers(window);
        /* Poll for and process events */
        glfwPollEvents();
        }
    glfwDestroyWindow(window);
    glfwTerminate();
    }

void EngineWrapper::init(){
    glfwInit();

    engine.drawWindow();
    GLFWwindow *window = engine.getWindow();
    glfwSetErrorCallback(HandleErrors);
    glfwSetKeyCallback(window,HandleInput);
}

void EngineWrapper::Update(double dt){
    }

void Engine::drawWindow(){
    if(fullscreen){
        mainWindow = glfwCreateWindow(sizeX,sizeY,"Default",glfwGetPrimaryMonitor(),NULL);
    }
    else{
        mainWindow = glfwCreateWindow(sizeX,sizeY,"Default",NULL,NULL);
    }
}

void EngineWrapper::HandleErrors(int error,const char *msg){
    std::string s;
    s = std::to_string(error) + msg + '\n';
    std::cerr << s << std::endl;
}

void EngineWrapper::render(){
    }

void Engine::resize(int x, int y){
}

void Engine::resize(){
}
void Engine::setFps(int f){
    fps = f;
}

void Engine::setFullscreen(bool full){
    fullscreen = full;
}

void Engine::setX(int x){
    sizeX = x;
}

void Engine::setY(int y){
    sizeY = y;
}

GLFWwindow* Engine::getWindow(){
    return mainWindow;
}

bool Engine::isFullscreen(){
    return fullscreen;
}

bool Engine::mouse(){
    return mouseInput;
}

bool Engine::keyboard(){
    return keyboardInput;
}

int Engine::getFps(){
    return fps;
}

int Engine::getX(){
    return sizeX;
}
int Engine::getY(){
    return sizeY;
}

static void HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
