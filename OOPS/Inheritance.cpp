#include <iostream>
#include <list>
using namespace std;
//inheritance - what if we want to create another youtube channel - inherit youtube channel class
class YouTubeChannel {
private:
	string Name;
	int SubscribersCount;
	list<string> PublishedVideoTitles;
protected:
	string OwnerName;
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
	void Subscribe() {
		SubscribersCount++;
	}
	void Unsubscribe() {
		if (SubscribersCount > 0)
			SubscribersCount--;
	}
	void PublishVideo(string title) {
		PublishedVideoTitles.push_back(title);
	}
};
//          derived class              base class
class CookingYouTubeChannel:public YouTubeChannel{
    //public means whatever is public in YoutubeChannel class will be public in Cooking YoutubeChannel class
    public:    
    CookingYouTubeChannel(string name,string ownerName): YouTubeChannel(name,ownerName){
        
    }

    void Practice(){
        cout<<OwnerName<<" is Creating new notes, learning new things, experimenting with spices. . ."<<endl;
    }
};

int main()
{
    //if we pass the parameters then it will call the constructor of base class , but for empty
    //parameters the derived class will not have a default constructor
    string name = "Jay Hub";
    string ownerName = "Sara Jay";
    CookingYouTubeChannel ytChannel(name,ownerName);
    ytChannel.PublishVideo("Oral");
    ytChannel.PublishVideo("Missionary");
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Unsubscribe();
    ytChannel.GetInfo();
    ytChannel.Practice(); // base class will not have .Practice() method
	system("pause>0");
}

// IMPORTANT - 
//If you define a constructor with parameters in a class, and then attempt to create an object of 
//that class without passing parameters, the compiler 
//will not automatically generate a default constructor. Instead, you must explicitly 
//define a default constructor if you want to create objects without passing parameters.