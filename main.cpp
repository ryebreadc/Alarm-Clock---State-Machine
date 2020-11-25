#include <iostream>
#include <vector>

using namespace std;

class Sunday;
class Monday;
class Tuesday;
class Wednesday;
class Thursday;
class Friday;
class Saturday;
class AlarmClockAlert;
class AlarmClockContext;

class AlarmClockAlert {
  public:
    virtual void beep(AlarmClockContext *context) = 0;
    virtual void beepType() = 0;
    virtual ~AlarmClockAlert() {}
};
class Sunday: public AlarmClockAlert {
  public:
    void beep(AlarmClockContext *context) {
      cout << "It's Sunday, sleep in...\n";
    }
    void beepType() {
      cout << "Weekend\n";
    }
};
class Monday: public AlarmClockAlert {
  public:
    void beep(AlarmClockContext *context) {
      cout << "It's Monday, wake up...\n";
    }
    void beepType() {
      cout << "Weekday\n";
    }
};
class Tuesday: public AlarmClockAlert {
  public:
    void beep(AlarmClockContext *context) {
      cout << "It's Tuesday, wake up...\n";
    }
    void beepType() {
      cout << "Weekday\n";
    }
};
class Wednesday: public AlarmClockAlert {
  public:
    void beep(AlarmClockContext *context) {
      cout << "It's Wednesday, wake up...\n";
    }
    void beepType() {
      cout << "Weekday\n";
    }
};
class Thursday: public AlarmClockAlert {
  public:
    void beep(AlarmClockContext *context) {
      cout << "It's Thursday, wake up...\n";
    }
    void beepType() {
      cout << "Weekday\n";
    }
};
class Friday: public AlarmClockAlert {
  public:
    void beep(AlarmClockContext *context) {
      cout << "It's Friday, wake up...\n";
    }
    void beepType() {
      cout << "Weekday\n";
    }
};
class Saturday: public AlarmClockAlert {
  public:
    void beep(AlarmClockContext *context) {
      cout << "It's Saturday, sleep in...\n";
    }
    void beepType() {
      cout << "Weekend\n";
    }
};

class AlarmClockContext {
private:
	AlarmClockAlert *currentState;

public:
	AlarmClockContext(AlarmClockAlert *state) {
		currentState = state;
	}

	void setState(AlarmClockAlert *state) {
		currentState = state;
	}

	AlarmClockAlert *getState() {
		return currentState;
	}

	void beep() {
		currentState->beep(this);
	}
};

int main() {
  vector<AlarmClockAlert*> v;
  AlarmClockAlert* sun = new Sunday;
  AlarmClockAlert* mon = new Monday;
  AlarmClockAlert* tue = new Tuesday;
  AlarmClockAlert* wed = new Wednesday;
  AlarmClockAlert* thu = new Thursday;
  AlarmClockAlert* fri = new Friday;
  AlarmClockAlert* sat = new Saturday;
  
  v.push_back(sun);
  v.push_back(mon);
  v.push_back(tue);
  v.push_back(wed);
  v.push_back(thu);
  v.push_back(fri);
  v.push_back(sat);

  for(int i = 0; i < v.size(); i++) {
    AlarmClockContext *context = new AlarmClockContext(v[i]);
    context->getState()->beepType();
    context->beep();
  }
}