#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Handler.h"

using namespace Messenger;

Handler::Handler() {
	loggedIn = false;
	chat = NULL;
}


Handler::~Handler() {
	chat = NULL;
	delete chat;
}

bool Handler::VerifyUser() {
	if (!loggedIn) {
		std::cout << "Not logged in." << std::endl;
	}
	return loggedIn;
}

bool Handler::SetConfig(const std::string config) {
	this->config = config;
	return true;
}

std::string Handler::GetConfig() const {
	return this->config;
}

void Handler::LoadUsers() {
	try {
		std::ifstream input;
		input.open(config);
		if (input.is_open()) {
			std::string login;
			std::string userName;
			std::string password;
			int id;
			input >> login >> userName >> password >> id;
			users.push_back(User(login, userName, password, id));
			input.close();
		}
	}
	catch (std::exception e) {
	}
	std::cout << "Users loaded." << std::endl;
}

void Handler::SaveUsers() {
	try {
		std::ofstream output;
		output.open(config);
		if (output.is_open()) {
			for (User user : users) {
				output << user.GetLogin() << " " << user.GetUserName() << " " << user.GetPassword() << " " << user.GetID() << std::endl;
			}
			output.close();
		}
	}
	catch (std::exception e) {
		return;
	}
	std::cout << "Users saved." << std::endl;
}

void Handler::ClearUsers() {
	users.clear();
	std::cout << "Users cleared." << std::endl;
}

bool Handler::SignUpUser() {
	std::string login;
	std::string userName;
	std::string password;
	int id = 0;
	std::cout << "Login: ";
	std::cin >> login;
	std::cout << "Usermame: ";
	std::cin >> userName;
	std::cout << "Password: ";
	std::cin >> password;
	for (User user : users) {
		if (login == user.GetLogin()) {
			std::cout << "Login is not available." << std::endl;
			return false;
		} else if (userName == user.GetUserName()) {
			std::cout << "Name is not available." << std::endl;
			return false;
		} else if (password == user.GetPassword()) {
			// std::cout << "This password is already used by " << user.GetLogin() << std::endl;
		}
		if (id <= user.GetID()) {
			id = user.GetID() + 1;
		}
	}
	User user = User(login, userName, password, id);
	users.push_back(user);
	std::cout << "User signed up successfuly." << std::endl;
	return true;
}

bool Handler::LogInUser() {
	std::string login;
	std::string password;
	std::cout << "Login: ";
	std::cin >> login;
	std::cout << "Password: ";
	std::cin >> password;
	for (User user : users) {
		if (login == user.GetLogin()) {
			if (password == user.GetPassword()) {
				this->user = user;
				loggedIn = true;
				std::cout << "Logged in as " << user.GetUserName() << "(" << user.GetID() << ")" << std::endl;
				return true;
			} else {
				std::cout << "Incorrect password." << std::endl;
				return false;
			}

		}
	}
	std::cout << "User not found." << std::endl;
	return false;
}

bool Handler::EnterChat(Chat *chat) {
	if (!VerifyUser()) {
		return false;
	}
	if (chat == NULL)
		return false;

	this->chat = chat;
	return true;
}

bool Handler::LeaveChat() {
	if (!VerifyUser()) {
		return false;
	}
	this->chat = NULL;
	return true;
}

bool Handler::SendMessage() {
	if (!VerifyUser()) {
		return false;
	}
	std::string message;
	std::getline(std::cin, message);
	std::getline(std::cin, message);
	if (chat) {
		chat->AddMessage(Message(user.GetID(), message));
		std::cout << "Message sent." << std::endl;
		return true;
	}
	return false;
}

bool Handler::SendDirectMessage() {
	if (!VerifyUser()) {
		return false;
	}
	std::string recipient;
	std::string message;
	std::cout << "Send to: ";
	std::cin >> recipient;
	std::getline(std::cin, message);
	std::getline(std::cin, message);
	for (User &user : users) {
		if (recipient == user.GetUserName()) {
			user.AddMessage(Message(this->user.GetID(), message));
			std::cout << "Direct message sent." << std::endl;
			return true;
		}
	}
	std::cout << "User not found." << std::endl;
	return false;
}

void Handler::ShowInbox() {
	if (VerifyUser()) {
		user.ShowInbox();
	}
}