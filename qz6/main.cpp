#include <iostream>
#include <string>

using namespace std;

class Clock{
	public:
		int hour;
		int minute;
		int second;
		string meridian;
		
		Clock(int x, int y, int z, string s){
			hour = x;
			minute = y;
			second = z;
			meridian = s;
			}
		void display(){
		cout << hour << ":" << minute << ":" << second << " " << meridian << endl;
		}
};

class StandardClock : Clock {
	public:
		StandardClock(int x, int y, int z, string s) : Clock(x, y, z, s){
		hour = x;
		minute = y;
		second = z;
		meridian = s;
		}
		void display(){
			if(meridian == "AM"){
					cout << "上午 " << hour << ":" << minute << ":" << second << endl;
				  } else if(meridian == "PM"){
					cout << "下午 " << hour << ":" << minute << ":" << second << endl;
				}
			} 
};

class MilitaryClock : Clock {
	public:
		MilitaryClock(int x, int y, int z, string s) : Clock(x, y, z, s){
			hour = x;
			minute = y;
			second = z;
			meridian = s;
		}
		void display(){
			if(meridian == "AM"){
				cout << hour << ":" << minute << ":" << second << " " << meridian << endl;
				} else if(meridian == "PM"){
				cout << hour+12 << ":" << minute << ":" << second << " " << meridian << endl;
				}
			} 	
};

int main(){
	Clock cc(10, 25, 43, "AM");
	StandardClock sc(10, 25, 43, "AM");
	MilitaryClock mc(10, 25, 43, "PM");
	cc.display();
	sc.display();
	mc.display();
	
	return 0;
}
