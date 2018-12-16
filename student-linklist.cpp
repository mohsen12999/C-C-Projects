#include <iostream>
#include <string>

using namespace std;

struct StudentNode
{
	int id;
	string name;
	float avg;

	StudentNode *next;
	//StudentNode *prev;
};

class linked_list
{
private:
	StudentNode *head, *tail;
public:
	linked_list()
	{
		head = NULL;
		tail = NULL;
	}

	void add_node(int id, string name,float avg)
	{
		StudentNode *tmp = new StudentNode;
		tmp->id = id;
		tmp->name = name;
		tmp->avg = avg;

		tmp->next = NULL;

		if (head == NULL)
		{
			//tmp->prev = NULL;
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			//StudentNode *last = tail;

			tail = tail->next;
			//tail->prev = last;
		}
	}

	void showAll()
	{
		StudentNode *st = head;
		cout << "student list:" << endl;
		while (st != NULL)
		{
			cout << "id: " << st->id << "\t\t name:"<< st->name << "\t\tavg: " << st->avg <<endl;
			st = st->next;
		}
	}

	void find_3max()
	{
		StudentNode *max[3];
		int max_size = 0;
		float max_min;
		int max_min_index;

		StudentNode *st = head;
		while (st != NULL)
		{
			if (max_size == 0)
			{
				max[max_size] = st;
				max_min = st->avg;
				max_min_index = max_size;
				max_size++;
			}
			else if (max_size < 3)
			{
				max[max_size] = st;
				if (st->avg < max_min)
				{
					max_min = st->avg;
					max_min_index = max_size;
				}
				max_size++;
			}
			else
			{
				if (st->avg > max_min)
				{
					max[max_min_index] = st;
					max_min = st->avg;
					for(int i=0;i<3;i++)
					{
						if (max[i]->avg < max_min)
						{
							max_min = max[i]->avg;
							max_min_index = i;
						}
					}
				}
			}

			st = st->next;
		}

		//sort
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2 - i; j++)
			{
				if (max[j]->avg < max[j + 1]->avg)
				{
					StudentNode *temp;
					temp = max[j];
					max[j] = max[j + 1];
					max[j + 1] = temp;
				}
			}
		}

		// show
		cout << "\n\n\n3 best student are:" << endl;
		for(int i = 0; i < 3; i++)
		{
			cout << "id: " << max[i]->id << "\t\t name:" << max[i]->name << "\t\tavg: " << max[i]->avg << endl;
		}

	}
};


int main()
{
	linked_list studentList;
	studentList.add_node(1,"hamid",12.5);
	studentList.add_node(2, "saeed", 14);
	studentList.add_node(3, "mohsen", 19);
	studentList.add_node(4,"ali",17);

	studentList.showAll();
	studentList.find_3max();

	return 0;
}