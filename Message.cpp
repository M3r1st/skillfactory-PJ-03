#include "Message.h"

using namespace Messenger;

Message::Message(int senderID, std::string message) {
	this->senderID = senderID;
	this->message = message;
}

int Message::GetSenderID() const {
	return this->senderID;
}
std::string Message::GetMessage() const {
	return this->message;
}