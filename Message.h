#pragma once

#include <string>

namespace Messenger {
	class Message {
	private:
		int senderID;
		std::string message;
	public:
		Message() = delete;
		Message(int senderID, std::string message);

		int GetSenderID() const;
		std::string GetMessage() const;
	};
}