#pragma once

#include <string>
#include <vector>
#include "Chat.h"
#include "Message.h"
#include "User.h"

namespace Messenger {
	class Handler {
	private:
		std::vector<User> users;
		User user;
		Chat* chat;
		std::string config;
		bool loggedIn;
		bool VerifyUser();

	public:
		Handler();
		~Handler();

		bool SetConfig(const std::string config);
		std::string GetConfig() const;

		void LoadUsers();
		void SaveUsers();
		void ClearUsers();

		bool SignUpUser();
		bool LogInUser(); 
		
		bool EnterChat(Chat *chat);
		bool LeaveChat();

		bool SendMessage();
		bool SendDirectMessage();
		void ShowInbox();
	};
}
