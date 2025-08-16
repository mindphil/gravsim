#include <GLFW/glfw3.h>
#include <iostream>

GLFWwindow* StartGLFW();

int main(){
    GLFWwindow* window = StartGLFW();
    if (!window){
        return -1;
    }
    
    while (!glfwWindowShouldClose(window)){
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}

GLFWwindow* StartGLFW(){
    if(!glfwInit()){
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return nullptr;
    }
    
    // Set window hints
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    GLFWwindow* window = glfwCreateWindow(800, 600, "Gravity Simulation", NULL, NULL);
    if (!window){
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    
    glfwMakeContextCurrent(window);
    
    return window;
}