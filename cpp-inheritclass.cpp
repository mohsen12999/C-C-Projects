#include <iostream>
#include <string>

using namespace std;

class Person{
	public:
		string name;
		string family;
		int national_id;
};

class Teacher: public Person{
	public:
		int personal_id;
		string* classes;
		void show()
		{
			cout<<"\nname: "<<name<<" "<<family<<" id: "<<national_id<<"\n";
			cout<<"classes: \n";
			for(int i=0;i<(sizeof(string)/sizeof(classes));i++)
			{
				cout<<classes[i]<<", ";
			}
		}
};

class Student: public Person{
	public:
		int student_id;
		float avg;
		void show()
		{
			cout<<"\nname: "<<name<<" "<<family<<" id: "<<national_id<<" - avg: "<<avg;
		}
};

int main()
{
	Teacher t1;
	t1.name="sara";
	t1.family="kamali";
	t1.national_id = 2276763;
	t1.personal_id = 46;
	string classes[] = {"cpp","c"};
	t1.classes = classes;
	t1.show();
	
	Student st1;
	st1.name="nasim";
	st1.family="alavi";
	st1.national_id = 2272121;
	st1.student_id = 97454;
	st1.avg = 15.6;
	st1.show();
	
	return 0;
}
