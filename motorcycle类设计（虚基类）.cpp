#include "iostream"
using namespace std;

class vehicle
{
private:
	double maxspeed, weight;
public:
	vehicle();
	vehicle(double maxspeed, double weight);
	~vehicle();
	void run();
	void stop();
};

vehicle::vehicle()
{
	this->maxspeed = this->weight = 0;
}

vehicle::vehicle(double maxspeed, double weight)
{
	this->maxspeed = maxspeed;
	this->weight = weight;
	cout << "vehicle constructor called. maxspeed:" << this->maxspeed << "; weight" << this->weight << endl;
}

vehicle::~vehicle()
{
	cout << "vehicle destructor called. maxspeed:" << this->maxspeed << "; weight" << this->weight << endl;
}

void vehicle::run()
{
	cout << "vehicle run" << endl;
}

void vehicle::stop()
{
	cout << "vehicle stop" << endl;
}

class bicycle :virtual public vehicle
{
private:
	double height;
public:
	bicycle();
	bicycle(double height, double maxspeed, double weight);
	~bicycle();

};

bicycle::bicycle()
{
	this->height = 0;
}

bicycle::bicycle(double height, double maxspeed, double weight):vehicle(maxspeed, weight)
{
	this->height = height;
	cout << "bicycle constructor called. height:" << this->height << endl;
}

bicycle::~bicycle()
{
	cout << "bicycle destructor called. height:" << this->height << endl;
}

class motorcar :virtual public vehicle
{
private:
	double seatnum;
public:
	motorcar();
	motorcar(double seatnum, double maxspeed, double weight);
	~motorcar();
};

motorcar::motorcar()
{
	this->seatnum = 0;
}

motorcar::motorcar(double seatnum, double maxspeed, double weight) :vehicle(maxspeed, weight)
{
	this->seatnum = seatnum;
	cout << "motorcar constructor called. seatnum:" << this->seatnum << endl;
}

motorcar::~motorcar()
{
	cout << "motorcar destructor called. seatnum:" << this->seatnum << endl;
}

class motorcycle :public bicycle, public motorcar
{
public:
	motorcycle(double height, double seatnum, double maxspeed, double weight);
	~motorcycle();
};

motorcycle::motorcycle(double height, double seatnum, double maxspeed, double weight):\
vehicle(maxspeed, weight), bicycle(height, maxspeed, weight), motorcar(seatnum, maxspeed, weight)
{
	cout << "motorcycle constructor called" << endl;
}

motorcycle::~motorcycle()
{
	cout << "motorcycle destructor called" << endl;
}


int main(int argc, char *argv[])
{
    motorcycle m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
    m.run();
    m.stop();
    return 0;
}

