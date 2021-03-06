#include "Polarization.h"
#include "Propagator.h"
#include <utility>

#ifndef RECEIVER_H_
#define RECEIVER_H_
class Receiver : public Polarization
{
	public:
	Receiver() : _receiverInitialAngle(0.0), _receiverRange(0.5), _numReceivedRFRays(0)
	{
		_receiverPosition.first = 0.0;
		_receiverPosition.second = 0.0;
		_observedRFRays.clear();
		_receiverDotProducts.clear();
		_receivedTimes.clear();
	};
	float _receiverInitialAngle; //initial angle with respect to horizontal, entered as degrees
	std::pair<float,float> _receiverPosition; //(y,z) position
	void InitializeReceiver(float,float,float); //set emitter y, z, initial angle.
	bool ReceiveRFRay(Propagator*); //True if the RFRay is near the receiver, controlled by _receiverRange.
	float _receiverRange; //Size of the receiver
	std::vector<Propagator> _observedRFRays;  //container of propagators that landed in the receiver.
	void SetReceiverRange(float); //Set function for _receiverRange
	std::vector<float> _receiverDotProducts; //Results of the dot products of received rays with Receiver polarization.
	int _numReceivedRFRays; //Number of rays received.  Equal to the length of _observedRFRays.
	int GetReceivedRFRays(); //Retrieve _numReceivedRFRays
	float GetReceivedDotProduct(int); //Retrieve dot product of an individual RFRay
	float GetDepth(); //Returns z-value.
	std::vector<float> _receivedTimes; //Global times of received rays
	std::vector<float> GetReceivedTimes(); //Return times of RFRay arrivals.
};

#endif
