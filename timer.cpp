#include <iostream>
#include <unistd.h>
#include <iomanip>


using namespace std;

void write_time(int n){
	int seconds = 0;
	int minutes = 0;
	while(minutes < n){
		cout << "\033[1A\033[2K";
		cout << setfill('0') << setw(2) << minutes << ':' << setfill('0') << setw(2) << seconds << '\n';
		++seconds;
		if(seconds == 60){
			seconds = 0;
			++minutes;
		}
		sleep(1);
	}
}

void start_timer(void){
	write_time(52);
	cout << "You have worked for 52 minutes. Rest time started!\n\n";
	write_time(17);
	cout << "Rest finished!\n";
}

int main(){
	char input;
	cout << "This is the 52-17 timer!\n";
	while(true){
		cout << "Enter 'y' to start timer and 'n' to exit.\n";
		cin >> input;
		if(input == 'y') start_timer();
		else if(input == 'n'){
			cout << "\033[1AProgram exiting...\n";
			break;
		}
	}
}
