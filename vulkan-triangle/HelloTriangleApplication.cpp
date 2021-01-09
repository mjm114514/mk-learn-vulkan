#include "HelloTriangleApplication.h"

void HelloTriangleApplication::run() {
	initVulkan();
	mainLoop();
	cleanup();
}
