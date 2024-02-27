#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

bool waitForEvent() {
    sleep(1);
    return true;
}

void sendFrame() {
    cout<<"Sender: Sending frame\n";
    // printf();
}

void getData() {
    cout<<"Sender: Getting data\n";
    // printf();
}

void makeFrame() {
    cout<<"Sender: Making frame\n";
    // printf();
}

void receiveFrame() {
    cout<<"Receiver: Receiving frame\n";
    // printf("Receiver: Receiving frame\n");
}

void extractData() {
    cout<<"Receiver: Extracting data\n";
    // printf("Receiver: Extracting data\n");
}

void deliverData() {
    cout<<"Receiver: Delivering data to network layer\n";
    // printf("Receiver: Delivering data to network layer\n");
}

bool Event(char ch) {
    if(ch=='R') {
        return true;
    }else if(ch=='A') {
        return false;
    }
}

int main() {
    char noti = 'R';

    while (true) {
        if (waitForEvent()) {
            if (Event(noti)) {
                getData();
                makeFrame();
                sendFrame();
                noti='A';
            } else {
                receiveFrame();
                extractData();
                deliverData();
                noti='R';
            }
        }
    }
    return 0;
}
