#include <vulkan\vulkan.h>
#include <GLFW\glfw3.h>
#define GLFW_INCLUDE_VULKAN
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <cstring>
#include <vector>


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

	void pickPhysicalDevice();

	bool isDeviceSuitable(VkPhysicalDevice device);

	std::vector<const char*> getRequiredExtensions();

	void setupDebugMessenger();

	void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);

	static VkResult CreateDebugUtilsMessengerEXT(
		VkInstance instance,
		const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
		const VkAllocationCallbacks* pAllocator,
		VkDebugUtilsMessengerEXT* pDebugMessenger
	);	

	static void DestroyDebugUtilsMessengerEXT(
		VkInstance instance,
		VkDebugUtilsMessengerEXT debugMessenger,
		const VkAllocationCallbacks* pAllocator
	);

	static VKAPI_ATTR VkBool32 VKAPI_CALL debugCallback(
		VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
		VkDebugUtilsMessageTypeFlagsEXT messageType,
		const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
		void* pUserData
	);

private:
	GLFWwindow* window;
	VkInstance instance;
	VkDebugUtilsMessengerEXT debugMessenger;
	VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
};
