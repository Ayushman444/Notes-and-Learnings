#include <iostream>
#include <list>
using namespace std;

class YouTubeChannel {
private:
	string Name;
	string OwnerName;
	int SubscribersCount;
	list<string> PublishedVideoTitles;
    //encapsulation says these properties should be private and inaccessible , and we should use methods to change these properties by user.

public:
	YouTubeChannel(string name, string ownerName) {
		Name = name;
		OwnerName = ownerName;
		SubscribersCount = 0;
	}
	void GetInfo() {
		cout << "Name: " << Name << endl;
		cout << "OwnerName: " << OwnerName << endl;
		cout << "SubscribersCount: " << SubscribersCount << endl;
		cout << "Videos: " << endl;
		for (string videoTitle : PublishedVideoTitles) {
			cout << videoTitle << endl;
		}
	}
    void Subscribe(){
        SubscribersCount++;
    }
    void Unsubscribe(){
        if(SubscribersCount>0){
            SubscribersCount--;
        } 
    }
    void PublishVideo(string title){
        PublishedVideoTitles.push_back(title);
    }
};

int main()
{
	YouTubeChannel ytChannel("CodeBeauty", "Saldina");
	// ytChannel.PublishedVideoTitles.push_back("C++ for beginners");
	// ytChannel.PublishedVideoTitles.push_back("HTML & CSS for beginners");
	// ytChannel.PublishedVideoTitles.push_back("C++ OOP");
    //using methods to allow user to change some things not directly , this is called encapsulation
    ytChannel.PublishVideo("c++ for beginners");
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Unsubscribe();
	ytChannel.GetInfo();



	system("pause>0");
}