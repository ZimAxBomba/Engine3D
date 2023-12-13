#ifndef ENGINE_H
#define ENGINE_H

#define GLFW_INCLUDE_NONE
#include <string>
#include <vector>
//#include <glad/glad.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
/**
 * Główna klasa Silnik.
 * Zajmuje się rysowaniem okna
 */
class Engine{
    public:
        
        Engine();
        
        Engine(bool,int,int);

        bool isFullscreen(); /**< Zwraca czy okno jest w pełnym ekranie. */
        bool mouse(); /**< zwraca czy myszka jest włączona. */
        bool keyboard(); /**< Zwraca czy klawiatura jest włączona. */
        int getX(); /**< Zwraca szerokośc okna. */
        int getY(); /**< Zwraca wysokośc okna. */
        std::string getTitle(); /**< Zwraca nazwę okna. */
        GLFWwindow* getWindow(); /**< Zwraca okno jako referencję. */
        int getFps(); /**< Zwraca limit FPS. */

        void setX(int); /**< Ustawia szerokośc okna. */
        void setY(int); /**< Ustawia wysokośc okna. */
        void resize(int,int); /**< Zmienia wymiary okna na podane wartości. */
        void resize(); /**< Zmienia wymiary okna. */
        void drawWindow(); /**< Rysuje puste okno. */
        void setFps(int); /**< Ustawia limit FPS. */
        void setFullscreen(bool); /**< Ustawia pełny ekran. */
    private:
        GLFWwindow *mainWindow; /**< Okno do rysowania. */

        bool fullscreen; /**< Parametr bool ustawiający pełny ekran. */
        bool mouseInput; /**< Parametr bool ustawiający myszkę. */
        bool keyboardInput; /** Parametr bool ustawiający klawiaturę. */
        //std::string title; /**< Nazwa okna. */
        char *title;
        int sizeX; /**< Szerokość okna. */
        int sizeY; /**< Wysokośc okna. */
        int fps; /**< Limit FPS. */
};
/**
 * Opakowanie klasy Engine z rendererem i eventem.
 */
class EngineWrapper{
    public:
        void run();
        //void HandleEvent(sf::Event);
        static void HandleErrors(int,const char*);
        void init();
        void render();
        void Update(double);
        Engine engine;
};


static void HandleInput(GLFWwindow* window, int key, int scancode, int action, int mods);
#endif
