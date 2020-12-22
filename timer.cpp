#include <iostream>
#include <unistd.h>
#include <iomanip>
#include <fstream>


using namespace std;

void write_time(int n){
	int seconds = 0;
	int minutes = 0;
	while(minutes < n){
		cout << "\033[1A\033[2K";							//clear previous time and move cursor back to the start
		cout << setfill('0') << setw(2) << minutes << ':' << setfill('0') << setw(2) << seconds << '\n'; //special xx : xx formatting
		++seconds;
		if(seconds == 60){
			seconds = 0;
			++minutes;
		}
		sleep(1);
	}
}

void start_timer(int count){
	write_time(52);
	cout << "You have worked for 52 minutes. Rest time started!\n\n";
	write_time(17);
	cout << "Rest finished!\n";
	ofstream log;
	log.open("timer_log.txt", ios::trunc);
	log << ++count;
}

int main(){
	ifstream log;
	int count = 0;
	log.open("timer_log.txt");
	if(!(log.is_open())){
		cout << "Log file not found.\nCreating new one...\n";
		log.close();
		ofstream log;
		log.open("timer_log.txt");
	}
	else{
		log >> count;
	}
	char input;
	cout << "This is the 52-17 timer!\nYou have used this timer " << count << " times.\n";
	while(true){
		cout << "Enter 'y' to start timer and 'n' to exit.\n";
		cin >> input;
		if(input == 'y') start_timer(count);
		else if(input == 'n'){
			cout << "Program exiting...\n";
			break;
		}
	}
}
