#pragma once

#include <string>
#include <vector>
#include "Message.h"

namespace Messenger {
	class User {
	private:
		std::string login;
		std::string userName;
		// TODO: password should use hash instead
		std::string password;
		int id;
		std::vector<Message> inbox;

	public:
		User() = default;
		User(std::string login, std::string userName, std::string password, int id);

		bool SetID(const int id);
		int GetID() const;

		bool SetLogin(const std::string login);
		std::string GetLogin() const;

		bool SetUserName(const std::string userName);
		std::string GetUserName() const;

		bool SetPassword(const std::string password);
		// TODO: password too vulnerable, replace with hash check
		std::string GetPassword() const;

		void AddMessage(Message message);

		void ShowInbox() const;
	};
}