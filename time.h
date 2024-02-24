#pragma once

class Time {

public:
	double timeDilationEquation() const {
		return hoursDay * minutesHour; // = td 
	}

	double timePerFrameEquation() const {
		return td / frameRate; // = tpf 
	} 

private: 
	double td; // time dilation, which is the ratio of simulator time to real-world time 
	int hoursDay; // hours in a day, 24 in the case of earth 
	int minutesHour; // minutes in an hour, 60 in this case 

	int tpf; // time per frame, which is real-world time in seconds for each frame in the simulator 
	int frameRate; // number of frames in the simulator per second, 30 in this case 
};
