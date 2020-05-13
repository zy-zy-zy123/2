#include"iostream"
using namespace std;
class vehicle
{
private:
	int maxspeed, weight;
public:
	void run()
	{
		cout << "vehicle run" << endl;
	}
	void stop()
	{
		cout << "vehicle stop" << endl;
	}
	vehicle(int speed, int weight)
	{
		maxspeed = speed;
		this->weight = weight;
		cout << "vehicle constructor called. " << "maxspeed:" << maxspeed << "; " << "weight:" << this->weight << endl;
	}
	~vehicle()
	{
		cout << "vehicle destructor called. " << "maxspeed:" << maxspeed << "; " << "weight:" << this->weight << endl;
	}
};
class bicycle :virtual public vehicle
{
private:
	int height;
public:
	bicycle(int height, int maxspeed, int weight) :vehicle(maxspeed, weight)
	{
		this->height = height;
		cout << "bicycle constructor called. height:" << this->height << endl;
	}
	~bicycle()
	{
		cout << "bicycle destructor called. height:" << this->height << endl;
	}
};
class motorcar :virtual public vehicle
{
private:
	int seatnum;
public:
	motorcar(int seatnum, int maxspeed, int weight) :vehicle(maxspeed, weight)
	{
		this->seatnum = seatnum;
		cout << "motorcar constructor called. seatnum:" << this->seatnum << endl;
	}
	~motorcar()
	{
		cout << "motorcar destructor called. seatnum:" << this->seatnum << endl;
	}
};
class motorcycle : virtual public bicycle, virtual public motorcar
{
public:
	motorcycle(int height, int seatnum, int maxspeed, int weight) :bicycle(height, maxspeed, weight), motorcar(seatnum, maxspeed, weight), vehicle(maxspeed, weight)
	{
		cout << "motorcycle constructor called" << endl;
	}
	~motorcycle()
	{
		cout << "motorcycle destructor called" << endl;
	}
};
int  main(int  argc, char* argv[])
{
	motorcycle  m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight 
	m.run();
	m.stop();
	return  0;
}