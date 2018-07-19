#include "Window.h"
#include <iostream>
#include <OpenNI.h>
#include "KInectStream.h"

#define log(x) std::cout << x << std::endl;


int main(int argc, char** argv)
{
	Window colorWindow;
	//Window depthWindow;
	Window skeltonWindow;
	skeltonWindow.init();
	colorWindow.init();
	//depthWindow.init();
	nite::UserTracker tracker;

	if (openni::OpenNI::initialize() != openni::Status::STATUS_OK)
	{
		log(openni::OpenNI::getExtendedError());
	}
	else
	{
		log("OpenNI succefully initilized");
	}

	nite::NiTE::initialize();
	
	
	openni::Array<openni::DeviceInfo> devices;
	openni::OpenNI::enumerateDevices(&devices);
	for (int i = 0; i < devices.getSize(); i++)
	{
		log(devices[i].getName());
	}

	openni::Device kinect;
	openni::VideoStream depth, color;
	const char* deviceuri = openni::ANY_DEVICE;
	openni::Status kinectStatus = kinect.open(deviceuri);

	if (kinectStatus != openni::Status::STATUS_OK)
	{
		log(openni::OpenNI::getExtendedError());
	}
	else
	{
		log("Kinect URI successfully opened");
	}

	if (tracker.create(&kinect) != openni::Status::STATUS_OK)
	{
		log("failed to create traker");
	}

	kinectStatus = depth.create(kinect, openni::SENSOR_DEPTH);
	
	if (kinectStatus == openni::Status::STATUS_OK)
	{
		kinectStatus = depth.start();
		if (kinectStatus != openni::Status::STATUS_OK)
		{
			log(openni::OpenNI::getExtendedError());
			depth.destroy();
		}
	}
	else
	{
		log(openni::OpenNI::getExtendedError());
	}

	kinectStatus = color.create(kinect, openni::SENSOR_COLOR);

	if (kinectStatus == openni::Status::STATUS_OK)
	{
		kinectStatus = color.start();
		if (kinectStatus != openni::Status::STATUS_OK)
		{
			log(openni::OpenNI::getExtendedError());
			color.destroy();
		}
	}
	else
	{
		log(openni::OpenNI::getExtendedError());
	}

	KinectStream kinectStream(kinect, depth, color, tracker);
	kinectStream.init();

	SDL_Event e;

	for (;;) {
		SDL_PollEvent(&e);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		kinectStream.run();
		kinectStream.drawColorFrame();
		kinectStream.runTracker();
		colorWindow.clearFlipBuffers();


		SDL_GL_MakeCurrent(skeltonWindow.getWindow(), skeltonWindow.getOpenGLContext());
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		kinectStream.runTracker();
		skeltonWindow.clearFlipBuffers();

		SDL_GL_MakeCurrent(colorWindow.getWindow(), colorWindow.getOpenGLContext());

		if (e.window.event == SDL_WINDOWEVENT_CLOSE) {
			break;
		}
	}
	
	nite::NiTE::shutdown();
	openni::OpenNI::shutdown();
	return 0;
}