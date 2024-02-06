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

int main() {
    bool isSender = true;

    while (true) {
        if (waitForEvent()) {
            if (isSender) {
                getData();
                makeFrame();
                sendFrame();
            } else {
                receiveFrame();
                extractData();
                deliverData();
            }
            isSender = !isSender;
        }
    }
    return 0;
}
