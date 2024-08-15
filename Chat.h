#pragma once

#include <string>
#include <vector>
#include "Message.h"

namespace Messenger {
	class Chat {
	private:
		std::vector<int> userIDs;
		std::vector<Message> history;
		int chatID;

	public:
		Chat() = default;
		std::vector<Message> GetHistory();
		bool AddUser(int user);
		bool RemoveUser(int user);
		void AddMessage(Message message);
	};
}