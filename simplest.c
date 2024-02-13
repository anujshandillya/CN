#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>

bool waitForEvent() {
    sleep(1);
    return true;
}

void sendFrame() {
    printf("Sender: Sending frame\n");
}

void getData() {
    printf("Sender: Getting data\n");
}

void makeFrame() {
    printf("Sender: Making frame\n");
}

void receiveFrame() {
    printf("Receiver: Receiving frame\n");
}

void extractData() {
    printf("Receiver: Extracting data\n");
}

void deliverData() {
    printf("Receiver: Delivering data to network layer\n");
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
