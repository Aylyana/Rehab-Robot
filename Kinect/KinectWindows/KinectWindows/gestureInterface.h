#pragma once
#include <NiTE.h>
#include <math.h>

//TODO: better way of tacking posistion of points
//Easy: euclid distance
//Itermediate: trilateration
//Hard: deltas/keyframes
class GestureInterface
{
private:
	nite::Skeleton skeleton;
public:
	GestureInterface(nite::Skeleton skeleton) : skeleton(skeleton) {};
	virtual ~GestureInterface() {};

	virtual bool checkForGesture() = 0;

	nite::Skeleton getSkeleton() { return skeleton; }
	
	
	//sqroot can be taken out to improve on performance
	float euclidDistance(nite::Point3f a, nite::Point3f b)
	{
		return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
	}



	// TODO: catch exceptions, what happens if there is no skelton or it cant find joint

	//head
	nite::Point3f getHeadPos() { return skeleton.getJoint(nite::JOINT_HEAD).getPosition(); }

	//neck
	nite::Point3f getNeckPos() { return skeleton.getJoint(nite::JOINT_NECK).getPosition(); }

	//torso
	nite::Point3f getTorsoPos() { return skeleton.getJoint(nite::JOINT_TORSO).getPosition(); }

	//shoulder
	nite::Point3f getLeftShoulderPos() { return skeleton.getJoint(nite::JOINT_LEFT_SHOULDER).getPosition(); }
	nite::Point3f getRightShoulderPos() { return skeleton.getJoint(nite::JOINT_RIGHT_SHOULDER).getPosition(); }

	//elbow
	nite::Point3f getLeftElbowPos() { return skeleton.getJoint(nite::JOINT_LEFT_ELBOW).getPosition(); }
	nite::Point3f getRightElbowPos() { return skeleton.getJoint(nite::JOINT_RIGHT_ELBOW).getPosition(); }

	//Hands
	nite::Point3f getLeftHandPos() { return skeleton.getJoint(nite::JOINT_LEFT_HAND).getPosition(); }
	nite::Point3f getRightHandPos() { return skeleton.getJoint(nite::JOINT_RIGHT_HAND).getPosition(); }

	//hip
	nite::Point3f getLeftHipPos() { return skeleton.getJoint(nite::JOINT_LEFT_HIP).getPosition(); }
	nite::Point3f getRightHipPos() { return skeleton.getJoint(nite::JOINT_RIGHT_HIP).getPosition(); }

	//knee
	nite::Point3f getLeftKneePos() { return skeleton.getJoint(nite::JOINT_LEFT_KNEE).getPosition(); }
	nite::Point3f getRightKneePos() { return skeleton.getJoint(nite::JOINT_RIGHT_KNEE).getPosition(); }

	//feet
	nite::Point3f getLeftFootPos() { return skeleton.getJoint(nite::JOINT_LEFT_FOOT).getPosition(); }
	nite::Point3f getRightFootPos() { return skeleton.getJoint(nite::JOINT_RIGHT_FOOT).getPosition(); }

};
