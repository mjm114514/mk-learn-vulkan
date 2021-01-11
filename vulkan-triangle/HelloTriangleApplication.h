#ifndef __HELLO_TRIANGLE_APPLICATION_H__
#define __HELLO_TRIANGLE_APPLICATION_H__

#include <vulkan/vulkan.h>
#include <GLFW/glfw3.h>
#define GLFW_INCLUDE_VULKAN
#include <stdexcept>
#include <iostream>
#include <vector>

#ifdef NDEBUG
const bool enableValidationLayers = false;
#else
const bool enableValidationLayers = true;
#endif // NDEBUG

class HelloTriangleApplication {
public:
	void run();

private:
	void initWindow();

	void initVulkan();

	void mainLoop();

	void cleanup();

	void createInstance();

	bool checkValidationLayerSupport();

	std::vector<const char*> getRequiredExtensions();

	void setupDebugMessenger();

	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

private:
	GLFWwindow* window;
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
};

#endif
