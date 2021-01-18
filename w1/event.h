#ifndef SDDS_EVENT_H__
#define SDDS_EVENT_H__

extern int g_sysClock;

namespace sdds {
	class Event {
		char *e_desc;
		int e_time;
		void setEmpty();
	public:
		Event(const Event&);
		Event();
		void display();
		void setDescription(char*);
		Event& operator=(const Event&);
	};
}
#endif // !SDDS_EVENT_H__

