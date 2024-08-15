#include <string>
#include <vector>
#include "Chat.h"
#include "Message.h"

using namespace Messenger;

std::vector<Message> Chat::GetHistory() {
	return this->history;
}

bool Chat::AddUser(int user) {
	for (int i = 0; i < userIDs.size(); i++) {
		if (userIDs[i] == user) {
			return false;
		}
	}
	userIDs.push_back(user);
	return true;
}

bool Chat::RemoveUser(int user) {
	for (int i = 0; i < userIDs.size(); i++) {
		if (userIDs[i] == user) {
			userIDs.erase(userIDs.begin() + i);
			return true;
		}
	}
	return false;
}

void Chat::AddMessage(Message message) {
	history.push_back(message);
}