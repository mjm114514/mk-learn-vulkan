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

struct QueueFamilyIndices {
	uint32_t graphicsFamily;
};

class HelloTriangleApplication {
public:
	void run();

private:
	void initWindow();

	void initVulkan();

	void mainLoop();

	void cleanup();

	void createInstance();

	void pickPhysicalDevice();

	bool checkValidationLayerSupport();

	std::vector<const char*> getRequiredExtensions();

	void setupDebugMessenger();

	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	bool isDeviceSuitable(VkPhysicalDevice device);

	QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);

private:
	GLFWwindow* window;
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
};

#endif
