#include <iostream>
#include <string>
#include <stdio.h>
#include "Messenger.h"

using namespace Messenger;

int main() {
    FILE* input;
    errno_t e = freopen_s(&input, "testing.in", "r", stdin);
    std::string arg;
    Handler handler;
    Chat chat;
    handler.SetConfig("users.txt");
    while (true) {
        std::cin >> arg;
        if (arg == "log-in") {
            handler.LogInUser();
        } else if (arg == "sign-up") {
            handler.SignUpUser();
        } else if (arg == "load-users") {
            handler.LoadUsers();
        } else if (arg == "save-users") {
            handler.SaveUsers();
        } else if (arg == "clear-users") {
            handler.ClearUsers();
        } else if (arg == "enter-chat") {
            handler.EnterChat(&chat);
        } else if (arg == "send-message") {
            handler.SendMessage();
        } else if (arg == "send-direct-message") {
            handler.SendDirectMessage();
        } else if (arg == "show-inbox") {
            handler.ShowInbox();
        } else if (arg == "exit") {
            break;
        }
    }
}
